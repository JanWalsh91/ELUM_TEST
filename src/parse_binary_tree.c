/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_binary_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 12:27:09 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/12 13:13:49 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/lceb.h"
static void	build_equation(t_list *node, char **string);
static void		open_parentheses(t_list *node, char **string);
static void		close_parentheses(t_list *node, char **string);

/*
** In-order binary tree traversal.
*/

void		parse_binary_tree(t_list *node, char **string) {

	if (node) {
		// printf("parsing binary tree. node-value: %d op: %c\n", node->value, node->op);
		// printf("- going left\n");
		open_parentheses(node, string);
		parse_binary_tree(node->left, string);
		build_equation(node, string);
		// printf("- going right\n");
		parse_binary_tree(node->right, string);
		close_parentheses(node, string);
		// printf("- going up\n");
	}
}

static void	build_equation(t_list *node, char **string) {
	// printf("building equation: ");
	if (node->op == '0') {
		*string = ft_strjoinfree(*string, ft_itoa(node->value), 'l');
		// printf("%s\n", *string);
	}
	else {
		*string = ft_strjoinfree(*string, &node->op, 'l');
		// printf("%s\n", *string);
	}
	*string = ft_strjoinfree(*string, " ", 'l');
}

static void		open_parentheses(t_list *node, char **string) {
	// printf("check for open parethenses: node->op: %c, node->prev: %p", node->op, node->prev);
	if (node->op != '0' && node->prev && node->prev->op != '0') {
		// printf(" node->prev->op: %c", node->prev->op);
		// printf(" node->op: %c", node->op);
		if ((node->prev->op == '+' && node->op == '-') ||
			(node->prev->op == '-' && node->op == '+') ||
			(node->prev->op == '-' && node->op == '-') ||
			(node->prev->op == '*') ||
			(node->prev->op == '/')) {
				// printf("building equation: ");
				*string = ft_strjoinfree(*string, "( ", 'l');
				// printf("%s\n", *string);
			}
	}
	// printf("\n");
}

static void		close_parentheses(t_list *node, char **string) {
	if (node->op != '0' && node->prev && node->prev->op != '0') {
		if ((node->prev->op == '+' && node->op == '-') ||
			(node->prev->op == '-' && node->op == '+') ||
			(node->prev->op == '-' && node->op == '-') ||
			(node->prev->op == '*') ||
			(node->prev->op == '/')) {
				*string = ft_strjoinfree(*string, ") ", 'l');
			}
	}
}