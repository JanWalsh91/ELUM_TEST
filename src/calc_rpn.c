/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rpn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 11:56:23 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/10 17:50:19 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/lceb.h"

/*
** Evaluates the RPN expression and returns the result.
*/

int	calc_rpn(t_data *data) {
	
	// printf("calc_rpn\n");
	int 	stack[8];
	int		stack_i = -1; // index for the stack
	int		expr_i = 0; // index for the expression
	t_sym	*expr = data->expr; // expr alias
	int		result;

	// if (!(stack = (int *)malloc(sizeof(int) * data->num_count)))
	// 	error_exit("malloc error.");
	// just in case...
	// bzero(stack, sizeof(int) * data->num_count);
	for (int i = 0; i < data->expr_length; i++) {
		if (data->expr[i].value == 0 && data->expr[i].type == T_NUMBER) {
			// printf("num at %d: %d\n", i, data->expr[i].value);
			exit(0);
		}
	}
	memset(&stack, -1, 8 * sizeof(int));
	while (expr_i < data->expr_length) {
		// printf("expr: ");
		// for (int i = 0; i < data->expr_length; i++) {
			// printf("%d ", data->expr[i].value);
		// }
		// printf("\nstack: ");
		// for (int i = 0; i < 8; i++) {
			// printf("%d ", stack[i]);
		// }
		// printf("\n");
		if (expr[expr_i].type == T_NUMBER) {
			// printf("   add to stack stack[%d]=%d\n", stack_i + 1, expr[expr_i].value);
			// printf("--expr: %d --\n", expr[expr_i].value);
			stack[++stack_i] = expr[expr_i].value;
			// printf("  top of stack: %d\n", stack[stack_i]);
			++expr_i;
		}
		else if (expr[expr_i].type == T_OPERATOR) {
			// printf("--expr: %c --\n", expr[expr_i].op);
			--stack_i;
			// printf("   do op %d %c %d\n", stack[stack_i], expr[expr_i].op, stack[stack_i + 1]);
			stack[stack_i] = do_op(stack[stack_i], expr[expr_i].op, stack[stack_i + 1], &(data->error));
			// printf("  top of stack: %d\n", stack[stack_i]);
			if (data->error) return (expr_i); // return the index of the '/' to change imediately. 
			expr_i++;
		}
	}
	// printf("stack_i: %d\n", stack_i);
		// printf("result: %d\n", stack[stack_i]);
	result = stack[stack_i];
	// free(stack);
	return (result);
}