/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lceb.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 09:54:37 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/12 12:57:22 by jwalsh           ###   ########.fr       */
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
	
		t_type			type;
		int				value; // value if T_NUMBER
		int				index; // index in num_list
		char			op; // operator if T_OPERATOR
}				t_sym;

typedef struct	s_data {

		int				result;
		int				*num_list;
		bool			*in_use;
		int				num_count;
		t_sym			*expr;
		int				expr_length;
		int				error;
}				t_data;

typedef struct 	s_list {
		int				value;
		char			op;
		struct s_list	*next;
		struct s_list	*prev;
		struct s_list	*left;
		struct s_list	*right;
		bool			parentheses;
}				t_list;

bool	is_input_valid(int ac, char **av);
t_data 	*init_data(int ac, char **av);

bool	is_rpn_valid(t_data *data);
int		calc_rpn(t_data *data);
int		do_op(int a, char op, int b, int *error);
int		increment_expression(t_data *data);

/*
** Convert from RPN
*/

char	*convert_from_rpn(t_data *data);
t_list	*init_linked_list(t_data *data);
void	build_binary_tree(t_list **head);
void	parse_binary_tree(t_list *node, char **string);
/*
** Misc
*/

void	print_expression(t_data *data);
void	error_exit(char *error_msg);
void	print_linked_list(t_list **head);

/*
** Helper funcions
*/

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoinfree(char const *s1, char const *s2, char c);
char	*ft_itoa(int n);