/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rpn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 11:56:23 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/12 14:36:57 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lceb.h"

/*
** Evaluates the RPN expression and returns the result.
*/

int	calc_rpn(t_data *data) {
	
	int 	stack[8];
	int		stack_i = -1;
	int		expr_i = 0;
	t_sym	*expr = data->expr;
	int		result;

	for (int i = 0; i < data->expr_length; i++) {
		if (data->expr[i].value == 0 && data->expr[i].type == T_NUMBER) {
			exit(0);
		}
	}
	memset(&stack, -1, 8 * sizeof(int));
	while (expr_i < data->expr_length) {
		if (expr[expr_i].type == T_NUMBER) {
			stack[++stack_i] = expr[expr_i].value;
			++expr_i;
		}
		else if (expr[expr_i].type == T_OPERATOR) {
			--stack_i;
			stack[stack_i] = do_op(stack[stack_i], expr[expr_i].op, stack[stack_i + 1], &(data->error));
			if (data->error) return (expr_i);
			expr_i++;
		}
	}
	result = stack[stack_i];
	return (result);
}