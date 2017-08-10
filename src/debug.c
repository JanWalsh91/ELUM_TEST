/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 12:55:34 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/10 16:17:06 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/lceb.h"

/*
** Debug functions
*/

void print_expression(t_data *data) {
	printf("expression: ");
	for (int i = 0; i < data->expr_length; i++) {
		if (data->expr[i].type == T_NUMBER)
			printf("%d ", data->expr[i].value);
		else if (data->expr[i].type == T_OPERATOR)
			printf("%c ", data->expr[i].op);
	}
	printf("= %d\n", data->result);
}