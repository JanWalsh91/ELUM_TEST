/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_input_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 10:21:41 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/12 13:15:14 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/lceb.h"

/*
** Input is invalid if the number of arguments is less than 4 or
** if any char is not a digit.
*/

bool	is_input_valid(int ac, char **av) {

	int	i;
	int	y;

	if (ac < 4) {
		error_exit("not enough arguments.");
		return (false);
	}
	for (i = 1; i < ac; i++) {
		if (atoi(av[i]) == 0) {
				error_exit("only strictly positive integers allowed.");
				return (false);
			}
		for (y = 0; y < (int)strlen(av[i]); y++) {
			if (!isdigit(av[i][y])) {
				error_exit("non-digit character found.");
				return (false);
			}
		}
	}
	return (true);
}