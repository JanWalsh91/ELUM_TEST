/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rpn_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 11:55:00 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/10 17:50:57 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/lceb.h"

/* 
** Checks for the validity of the RNP (Reverse Polish Notation) expression
*/

bool	is_rpn_valid(t_data *data) {
	
	int counter = 0;
	int i;
	
	// print_expression(data);
	// check that all numbers are used in exression
	for (i = 0; i < data->num_count; i++) {
		if (!data->in_use[i]) {
			// printf("rpn invalid. 1 \n");
			return (false);
		}
	}
	// check that the rpn expression is valid
	for (i = 0; i < data->expr_length; i++) {
		if (data->expr[i].type == T_NUMBER)
			counter++;
		else if (data->expr[i].type == T_OPERATOR) {
			counter = counter - 2;
			if (counter < 0) {
				// printf("rpn invalid. 2\n");
				return (false);
			}
			counter++;
		}
	}
	// counter == 1 ? printf("rpn valid.\n") : printf("rpn invalid. 3\n");
	return (counter == 1);
}