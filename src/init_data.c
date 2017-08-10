/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 11:11:14 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/10 17:49:37 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/lceb.h"

static void	init_num_list(t_data *data, int ac, char **av);
static void	init_expr(t_data *data);

/*
** Initializes the t_data structure
*/

t_data 	*init_data(int ac, char **av) {

	t_data *data;
	// init data structure
	if (!(data = (t_data *)malloc(sizeof(t_data))))
		error_exit("malloc error.");
	// store desired result
	data->result = atoi(av[ac - 1]);
	printf("parsed result: %d\n", data->result);
	// init num list and in_use
	init_num_list(data, ac, av);
	printf("parsed numbers:\n");
	for (int i = 0; i < data->num_count; i++) {
		printf("- %d -", data->num_list[i]);
	}
	printf("\n");
	init_expr(data);
	data->error = 0;
	// exit(0);
	return (data);
}

static void	init_num_list(t_data *data, int ac, char **av) {

	data->num_count = ac - 2;
	// init num_list
	if (!(data->num_list = (int *)malloc((data->num_count) * sizeof(int))))
		error_exit("Malloc error.");
	// init in_use
	if (!(data->in_use = (bool *)malloc(sizeof(bool) * data->num_count)))
		error_exit("malloc error.");
	// add verification for out of range numbers
	for (int i = 1; i < ac - 1; i++) {
		data->num_list[i - 1] = atoi(av[i]);
		data->in_use[i - 1] = true;
	}
}

static void	init_expr(t_data *data) {
	// init expr
	data->expr_length = 2 * data->num_count - 1;
	// printf("expr length: %d\n", data->expr_length);
	if (!(data->expr = (t_sym *)malloc((data->expr_length) * sizeof(t_sym))))
		error_exit("malloc error.");
	// init symbol
	for (int i = 0; i < data->num_count; i++) {
		data->expr[i].type = T_NUMBER;
		data->expr[i].value = data->num_list[i];
		data->expr[i].index = i;
		data->expr[i].op = '0';
	}
	for (int i = data->num_count; i < data->expr_length; i++) {
		data->expr[i].type = T_OPERATOR;
		data->expr[i].value = -1;
		data->expr[i].index = 0;
		data->expr[i].op = '+';
	}
}