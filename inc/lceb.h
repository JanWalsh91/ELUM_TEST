/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lceb.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 09:54:37 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/10 17:15:14 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <strings.h>
# include <ctype.h>
# include <unistd.h>

typedef enum	e_type {

		T_NUMBER,
		T_OPERATOR,
		T_RESET
}				t_type;

typedef struct	s_sym {
	
		t_type	type;
		int		value; // value if T_NUMBER
		int		index; // index in num_list
		char	op; // operator if T_OPERATOR
}				t_sym;

typedef struct	s_data {

		int		result;
		int		*num_list;
		bool	*in_use;
		int		num_count;
		t_sym	*expr;
		int		expr_length;
		int		error;
}				t_data;

bool	is_input_valid(int ac, char **av);
t_data 	*init_data(int ac, char **av);

bool	is_rpn_valid(t_data *data);
int		calc_rpn(t_data *data);
int		do_op(int a, char op, int b, int *error);
int		increment_expression(t_data *data);
/*
** Misc
*/

void	print_expression(t_data *data);
void	error_exit(char *error_msg);