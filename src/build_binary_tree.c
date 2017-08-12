/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_binary_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 12:23:13 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/12 14:25:57 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lceb.h"

static void	re_link(t_list *node, t_list **head);

/*
** Builds a binary tree based off of the linked list. Creates nodes to group
** sub-expressions in the RPN expression until no more can be made.
*/

void	build_binary_tree(t_list **head) {
	printf("build_binary_tree\n");
	bool	build_again = false;
	t_list	*ptr;

	ptr = *head;
	while (ptr) {
		if (ptr->prev && ptr->prev->prev) {
			if (ptr->op != '0' && ptr->prev->value && ptr->prev->prev->value) {
				re_link(ptr, head);
				printf("relink done: \n- node value: %d\n- head value: %d\n", ptr->value, (*head)->value);
				build_again = true;
			}
		}
		ptr = ptr->next;
	}
	if (build_again) {
		build_binary_tree(head);
	}
}

/*
** Transforms a section of the linked list to a node when a valid series of symbols
** in the expression is found.
** A node is created by taking a operator in the expression preceeded by two values.
** The node's two previous values are assigned as its children.
** If a node is first in the linked list, it is set as the new head of the list.
** The next pointer of the link before those values is set to point to the node.
** The node value is updated.
** Sets the children's prev pointers to its parent and nulls the other ones.
** Example: in [ 5 4 + 9 * ], [ 5 4 + ] is a simplifyable expression.
*/

static void	re_link(t_list *node, t_list **head) {
	printf("re_link\n");
	printf("relinking: \n- node: %c\n- left: %d\n- right: %d\n", node->op, node->prev->prev->value, node->prev->value);
	node->left = node->prev->prev;
	node->right = node->prev;
	if (node->prev->prev == *head) {
		*head = node;
		node->prev = NULL;
	}
	else {
		node->prev = node->prev->prev->prev;
		node->prev->next = node;
	}
	node->value = do_op (node->left->value, node->op, node->right->value, NULL);
	node->left->next = NULL;
	node->left->prev = node;
	node->right->next = NULL;
	node->right->prev = node;
}
