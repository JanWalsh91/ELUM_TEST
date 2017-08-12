/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_from_rpn.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 11:01:16 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/12 12:39:09 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/lceb.h"

/*
** Converts the RPN expression to a normal mathematical expression.
*/

char	*convert_from_rpn(t_data *data) {
	printf("convert_from_rpn\n");
	char	*string;
	t_list	*head;
	
	string = NULL;
	head = NULL;
	head = init_linked_list(data);

	print_linked_list(&head);
	
	build_binary_tree(&head);
	
	parse_binary_tree(head, &string);
	return (string);
}
