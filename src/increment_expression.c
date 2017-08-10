/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment_expression.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 13:03:05 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/10 17:50:39 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/lceb.h"

static int	increment_symbol(t_data *data, int index);
static int	get_next_operator(t_data *data, int expr_i);
static int	get_next_available_number(t_data *data, int num_list_i, int expr_i);

/*
** Changes the expression in data->expr to the next logical combination of
** symbols and numbers. Returns 1 if there are no more expressions left.
*/

int	increment_expression(t_data *data) {

	// printf("increment_expression\n");

	if (!increment_symbol(data, data->expr_length - 1))
		return (0);
	return (1);
}

/*
** Attempts to increment the symbol at 'index' in data->expr to the next logical
** symbol. 
*/

static int increment_symbol(t_data *data, int index) {
	
	// printf("increment_symbol: ");
	// data->expr[index].type == T_NUMBER ? printf("%d", data->expr[index].value) : printf("%c", data->expr[index].op);
	t_sym	*sym = &data->expr[index]; //alias of symbol to increment in expression.

	// printf(" at index: %d\n", index);
	if (index < 0) {
		return (0);
	}
	// if symbol to increment is a number
	if (sym->type == T_NUMBER || sym->type == T_RESET) {
		// try to find next available number
		if (!get_next_available_number(data, sym->index, index)) { // if no number available, get an operator
			if (!get_next_operator(data, index)) { // if no opertator available, increment previous symbol
				return (increment_symbol(data, index - 1));
			}
		}
	}
	else if (sym->type == T_OPERATOR) {
		// try to find next available operator
		if (!get_next_operator(data, index)) {
			return (increment_symbol(data, index - 1));	
		}
	}
	if (index + 1 < data->expr_length)
		return (increment_symbol(data, index + 1));
	return (1);
}

static int	get_next_operator(t_data *data, int expr_i) {
	
	// printf("get_next_operator\n");
	if (data->expr[expr_i].type == T_OPERATOR && data->expr[expr_i].op == '/') {
		// printf("reset: %c at index %d\n", data->expr[expr_i].op, expr_i);
		data->expr[expr_i].type = T_RESET;
		return (0);
	}
	if (data->expr[expr_i].type == T_NUMBER || data->expr[expr_i].type == T_RESET) {
		data->in_use[data->expr[expr_i].index] = 0;
		data->expr[expr_i].op = '+';
	}
	else {
		switch (data->expr[expr_i].op) {
		case '+' :
			data->expr[expr_i].op = '-';
			break ;
		case '-' :
			data->expr[expr_i].op = '*';
			break ;
		case '*' :
			data->expr[expr_i].op = '/';
			break ;
		}
	}
	data->expr[expr_i].type = T_OPERATOR;
	data->expr[expr_i].value = 0;
	data->expr[expr_i].index = -1;
	return (1);
}



/*
** Starting at index in data->num_list, finds the next available number 
** ie, the number with in_use == 0;
** If found, sets the current number's in_use to 0;
** and the new numbers's in_use  to 1;
*/

static int	get_next_available_number(t_data *data, int num_list_i, int expr_i) {

	// printf("get_next_available_number\n");
	// num_list_i : index of int to change in num_list
	// expr_i : current index of symbol to increment
	for (int i = num_list_i + 1; i < data->num_count; i++) { // for all numbers after current one 
		// Starting at num_list_i in data->num_list, find the next available number 
		if (!data->in_use[i]) { // if found an available number
			// set current number to not in_use
			data->in_use[num_list_i] = 0;
			// set new number to in_use
			data->in_use[i] = 1;
			data->expr[expr_i].type = T_NUMBER;
			data->expr[expr_i].value = data->num_list[i];
			data->expr[expr_i].index = i;
			data->expr[expr_i].op = '0';
			// found number: return 1
			return (1);
		}
	}
	// error: no number found
	return (0);
}
