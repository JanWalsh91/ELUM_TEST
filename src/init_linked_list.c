/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_linked_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 11:40:11 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/12 14:59:13 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lceb.h"

static t_list	*init_link(t_sym *sym);
static void		append_to_list(t_list **head, t_list *new_link);

/*
** Initiliazes a doubly linked list based off of the data->expr
*/

t_list	*init_linked_list(t_data *data) {

	t_list	*head;
	
	head = NULL;
	for (int i = 0; i < data->expr_length; i++) {
		append_to_list(&head, init_link(&data->expr[i]));
	}
	return (head);
}

/*
** Initiliazes a link for the linked list;
*/

static t_list	*init_link(t_sym *sym) {

	t_list	*new_link;

	new_link = NULL;
	if (!(new_link = (t_list *)malloc(sizeof(t_list)))) {
		error_exit("malloc error.");
	}
	if (sym->type == T_NUMBER) {
		new_link->value = sym->value;
		new_link->op = '0';
	}
	else if (sym->type == T_OPERATOR) {
		new_link->value = 0;
		new_link->op = sym->op;
	}
	new_link->next = NULL;
	new_link->prev = NULL;
	new_link->left = NULL;
	new_link->right = NULL;
	new_link->parentheses = false;
	return (new_link);
}


/*
** Appends a link to the list as a doubly linked linked list.
*/

static void	append_to_list(t_list **head, t_list *new_link) {

	t_list *ptr;

	ptr = *head;
	if (new_link) {
		if (!*head) {
			*head = new_link;
		}
		else {
			while (ptr->next) {
				ptr = ptr->next;
			}
			ptr->next = new_link;
			new_link->prev = ptr;
		}
	}
}