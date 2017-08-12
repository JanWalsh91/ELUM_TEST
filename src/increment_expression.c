/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment_expression.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 13:03:05 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/12 14:32:09 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lceb.h"

static int	increment_symbol(t_data *data, int index);
static int	get_next_operator(t_data *data, int expr_i);
static int	get_next_available_number(t_data *data, int num_list_i, int expr_i);

/*
** Changes the expression in data->expr to the next logical combination of
** symbols and numbers. Returns 1 if there are no more expressions left.
*/

int	increment_expression(t_data *data) {

	if (!increment_symbol(data, data->expr_length - 1))
		return (0);
	return (1);
}

/*
** Attempts to increment the symbol at 'index' in data->expr to the next logical
** symbol. 
*/

static int increment_symbol(t_data *data, int index) {
	
	t_sym	*sym = &data->expr[index];

	if (index < 0) {
		return (0);
	}
	if (sym->type == T_NUMBER || sym->type == T_RESET) {
		if (!get_next_available_number(data, sym->index, index)) {
			if (!get_next_operator(data, index)) {
				return (increment_symbol(data, index - 1));
			}
		}
	}
	else if (sym->type == T_OPERATOR) {
		if (!get_next_operator(data, index)) {
			return (increment_symbol(data, index - 1));	
		}
	}
	if (index + 1 < data->expr_length)
		return (increment_symbol(data, index + 1));
	return (1);
}

/*
** Attempts to change the sym at data->expr[expr_i] to the next available operator.
** Returns 0 if none are available.
** Returns 1 on success.
*/

static int	get_next_operator(t_data *data, int expr_i) {
	
	if (data->expr[expr_i].type == T_OPERATOR && data->expr[expr_i].op == '/') {
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
** and the new numbers's in_use to 1;
*/

static int	get_next_available_number(t_data *data, int num_list_i, int expr_i) {

	for (int i = num_list_i + 1; i < data->num_count; i++) {
		if (!data->in_use[i]) {
			data->in_use[num_list_i] = 0;
			data->in_use[i] = 1;
			data->expr[expr_i].type = T_NUMBER;
			data->expr[expr_i].value = data->num_list[i];
			data->expr[expr_i].index = i;
			data->expr[expr_i].op = '0';
			return (1);
		}
	}
	return (0);
}
