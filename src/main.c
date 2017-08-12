/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 09:54:33 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/12 15:00:27 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lceb.h"

/*
** Initilizes data structure.
** Attempts to find a solution.
** Converts the solution from Reverse Polish Notation (RPN) format.
** Displays solution or error message.
*/

int		main(int ac, char **av) {

	t_data	*data = NULL;
	char	*final_equation =  NULL;
	bool 	solution = false;
	int		result;	

	if (is_input_valid(ac, av))
		data = init_data(ac, av);
	while (!solution) {
		if (is_rpn_valid(data)) {
			result = calc_rpn(data);
			if (data->error || result != data->result) {
				data->error = 0;
				if (increment_expression(data)) {
					continue ;
				}
				else break ;
			}
			else {
				solution = true;
				break ;
			}
		}
		else if (increment_expression(data)) {
			continue ;
		}
		else break ;
	}
	if (solution) {
		final_equation = convert_from_rpn(data);
		final_equation = ft_strjoinfree(final_equation, "= ", 'l');
		final_equation = ft_strjoinfree(final_equation, ft_itoa(data->result), 'l');
		printf("%s\n", final_equation);
	} else {
		printf("No solution.\n");
	}
	return (0);
}

