/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rpn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 11:56:23 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/10 12:55:02 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/lceb.h"

/*
** Evaluates the RPN expression and returns the result.
*/

int	calc_rpn(t_data *data, int *error) {
	
	int 	*stack;
	int		stack_i = -1; // index for the stack
	int		expr_i = 0; // index for the expression
	t_sym	*expr = data->expr; // expr alias
	int		result;

	if (!(stack = (int *)malloc(sizeof(int) * data->num_count)))
		error_exit("malloc error.");
	// just in case...
	bzero(stack, sizeof(int) * data->num_count);
	while (expr_i < data->expr_length) {
		if (expr[expr_i].type == T_NUMBER) {
			// printf("--expr: %d --\n", expr[expr_i].value);
			stack[++stack_i] = expr[expr_i].value;
			// printf("  top of stack: %d\n", stack[stack_i]);
			++expr_i;
		}
		else if (expr[expr_i].type == T_OPERATOR) {
			// printf("--expr: %c --\n", expr[expr_i].op);
			--stack_i;
			stack[stack_i] = do_op(stack[stack_i], expr[expr_i].op, stack[stack_i + 1], error);
			// printf("  top of stack: %d\n", stack[stack_i]);
			if (*error) return (1);
			expr_i++;
		}
	}
	// printf("stack_i: %d\n", stack_i);
		// printf("result: %d\n", stack[stack_i]);
	result = stack[stack_i];
	free(stack);
	return (result);
}