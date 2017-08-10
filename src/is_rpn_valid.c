/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rpn_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 11:55:00 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/10 12:32:54 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/lceb.h"

/* 
** Checks for the validity of the RNP (Reverse Polish Notation) expression
*/

bool	is_rpn_valid(t_data *data) {
	
	int counter = 0;
	
	for (int i = 0; i < data->expr_length; i++) {
		if (data->expr[i].type == T_NUMBER)
			counter++;
		else if (data->expr[i].type == T_OPERATOR) {
			counter = counter - 2;
			if (counter < 0)
				return (false);
			counter++;
		}
	}
	return (counter == 1);
}