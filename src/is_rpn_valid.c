/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rpn_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 11:55:00 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/12 14:42:23 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lceb.h"

/* 
** Checks for the validity of the RNP (Reverse Polish Notation) expression.
** - All numbers must be used.
** - The difference between the number of operands and operators must not
**   be lower than 0 evaluated anywhere throughout the expression.
** - The total difference between the number of operands and operators must
**   be 1.
** Returns true if the expression is valid, false if the expression is invalid.
*/

bool	is_rpn_valid(t_data *data) {
	
	int counter = 0;
	int i;
	
	for (i = 0; i < data->num_count; i++) {
		if (!data->in_use[i]) {
			return (false);
		}
	}
	for (i = 0; i < data->expr_length; i++) {
		if (data->expr[i].type == T_NUMBER)
			counter++;
		else if (data->expr[i].type == T_OPERATOR) {
			counter = counter - 2;
			if (counter < 0) {
				return (false);
			}
			counter++;
		}
	}
	return (counter == 1);
}