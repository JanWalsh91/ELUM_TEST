/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 09:54:33 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/10 13:00:03 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/lceb.h"

int		main(int ac, char **av) {

	t_data	*data = NULL;
	int		error = 0; // used to check for full division

	if (is_input_valid(ac, av))
		data = init_data(ac, av);
	printf("expression: \n");
	for (int i = 0; i < data->expr_length; i++) {
		if (data->expr[i].type == T_NUMBER)
			printf("%d ", data->expr[i].value);
		else if (data->expr[i].type == T_OPERATOR)
			printf("%c ", data->expr[i].op);
	}
	if (is_rpn_valid(data)) {
		printf(": rpn valid.\n");
		if (calc_rpn(data, &error) == data->result && !error)
			print_expression(data);
		else
			printf("solution not found.\n");
	}
	return (0);
}

