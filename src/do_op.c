/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 12:21:11 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/12 12:06:27 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/lceb.h"

/*
** Calculates the mathematical expression and returns the result.
*/

int	do_op(int a, char op, int b, int *error) {
	// printf("   do-op: %d %c %d\n", a, op, b);
	switch (op) {
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
		if (b == 0) {
				if (error) *error = 1;
				// printf("error: 1: %d / %d\n", a, b);
				return (a);
			}
			if (a % b != 0) {
				if (error) *error = 2;
				// printf("error: 2: %d / %d\n", a, b);
				return (a);
			}
			return (a / b);
		default:
			return (-1);
	}
}