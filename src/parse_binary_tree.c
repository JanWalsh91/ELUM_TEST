/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_binary_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 12:27:09 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/12 14:59:01 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lceb.h"

static void		build_equation(t_list *node, char **string);
static void		open_parentheses(t_list *node, char **string);
static void		close_parentheses(t_list *node, char **string);

/*
** Traverses the binary tree (in-order traversal) to build the equation.
*/

void		parse_binary_tree(t_list *node, char **string) {

	if (node) {
		open_parentheses(node, string);
		parse_binary_tree(node->left, string);
		build_equation(node, string);
		parse_binary_tree(node->right, string);
		close_parentheses(node, string);
	}
}

/*
** Concatenates the next operator or value.
*/

static void	build_equation(t_list *node, char **string) {
	if (node->op == '0') {
		*string = ft_strjoinfree(*string, ft_itoa(node->value), 'l');
	}
	else {
		*string = ft_strjoinfree(*string, &node->op, 'l');
	}
	*string = ft_strjoinfree(*string, " ", 'l');
}

/*
** Adds an open parenthese if necessary.
*/

static void		open_parentheses(t_list *node, char **string) {
	if (node->op != '0' && node->prev && node->prev->op != '0') {
		if ((node->prev->op == '+' && node->op == '-') ||
			(node->prev->op == '-' && node->op == '+') ||
			(node->prev->op == '-' && node->op == '-') ||
			(node->prev->op == '*') ||
			(node->prev->op == '/')) {
				if (*string == NULL) {
					if (!(*string = (char *)malloc(sizeof(char) * 3))) {
						error_exit("malloc error.");
					}
					(*string)[0] = '(';
					(*string)[1] = ' ';
					(*string)[2] = '\0';
				}
				else if (*string) {
					*string = ft_strjoinfree(*string, "( ", 'l');
				}
			}
	}
}

/*
** Adds a close parenthese if necessary.
*/

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