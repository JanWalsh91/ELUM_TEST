/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 12:21:11 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/12 14:07:40 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lceb.h"

/*
** Calculates the mathematical expression and returns the result.
*/

int	do_op(int a, char op, int b, int *error) {
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
				return (a);
			}
			if (a % b != 0) {
				if (error) *error = 2;
				return (a);
			}
			return (a / b);
		default:
			return (-1);
	}
}