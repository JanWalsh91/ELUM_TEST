/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 12:21:11 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/10 12:55:17 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/lceb.h"

/*
** Calculates the mathematical expression and returns the result.
*/

int	do_op(int a, char op, int b, int *error) {
	// printf("  do-op: %d %c %d\n", a, op, b);
	switch (op) {
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			if (a % b != 0) *error = 1;
			return (a / b);
		default:
			return (-1);
	}
}