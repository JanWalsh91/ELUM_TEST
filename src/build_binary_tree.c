/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_binary_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 12:23:13 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/12 13:13:58 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/lceb.h"

static void	re_link(t_list *node, t_list **head);

/*
** 
*/

void	build_binary_tree(t_list **head) {
	// printf("build_binary_tree\n");
	bool	build_again = false;
	t_list	*ptr;

	ptr = *head;
	while (ptr) {
		if (ptr->prev && ptr->prev->prev) {
			if (ptr->op != '0' && ptr->prev->value && ptr->prev->prev->value) {
				re_link(ptr, head);
				// printf("relink done: \n- node value: %d\n- head value: %d\n", ptr->value, (*head)->value);
				build_again = true;
			}
		}
		ptr = ptr->next;
	}
	if (build_again) {
		build_binary_tree(head);
	}
}

static void	re_link(t_list *node, t_list **head) {
	// printf("re_link\n");
	// printf("relinking: \n- node: %c\n- left: %d\n- right: %d\n", node->op, node->prev->prev->value, node->prev->value);
	// set node's children
	node->left = node->prev->prev;
	node->right = node->prev;

	// if node is now first in list, reset *head and set prev to NULL
	// else relink node with new previous node.
	if (node->prev->prev == *head) {
		*head = node;
		node->prev = NULL;
	}
	else {
		node->prev = node->prev->prev->prev;
		node->prev->next = node;
	}

	// calculate node value
	node->value = do_op (node->left->value, node->op, node->right->value, NULL);

	// remove linked list pointers for children
	node->left->next = NULL;
	node->left->prev = node;
	node->right->next = NULL;
	node->right->prev = node;
}
