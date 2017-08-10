/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 09:54:33 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/10 17:49:51 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/lceb.h"

int		main(int ac, char **av) {

	t_data	*data = NULL;

	if (is_input_valid(ac, av))
		data = init_data(ac, av);
	
	// print_expression(data);

	bool 	solution = false;
	int		result;	
	
	while (!solution) {
		// printf("-----\n");
		// sleep(1);
		if (is_rpn_valid(data)) {
			result = calc_rpn(data);
			// printf("result: %d, data->result: %d\n", result, data->result);
			if (data->error || result != data->result) {
				data->error = 0;
				if (increment_expression(data)) {
					// printf("A- ");
					// print_expression(data);
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
			// printf("B- ");
			// print_expression(data);
			continue ;
		}
		else break ;
	}
	printf("solution: ");
	solution ? print_expression(data) : printf("solution not found.\n");
	return (0);
}
