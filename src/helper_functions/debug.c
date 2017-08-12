/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 12:55:34 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/12 14:12:10 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lceb.h"

/*
** Debug functions
*/

void	print_expression(t_data *data) {
	printf("expression: ");
	for (int i = 0; i < data->expr_length; i++) {
		if (data->expr[i].type == T_NUMBER)
			printf("%d ", data->expr[i].value);
		else if (data->expr[i].type == T_OPERATOR)
			printf("%c ", data->expr[i].op);
	}
	printf("= %d\n", data->result);
}

void	print_linked_list(t_list **head) {
	printf("linked list: ");
	t_list *ptr;

	ptr = *head;
	while (ptr) {
		if (ptr->value) {
			printf("%d ", ptr->value);
		}
		else {
			printf("%c ", ptr->op);
		}
		ptr = ptr->next;
	}
	printf("\n");
}