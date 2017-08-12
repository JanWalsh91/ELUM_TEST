/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_input_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 10:21:41 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/12 14:54:32 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lceb.h"

/*
** Checks for the validity of user input. Invalid if: 
** - there are less than 3 numbers.
** - there are more than 8 numbers.
** - there are any negative or null numbers.
** - if any characters are not digits.
*/

bool	is_input_valid(int ac, char **av) {

	if (ac < 4) {
		error_exit("please provide at least 3 numbers.");
		return (false);
	}
	if (ac > 10) {
		error_exit("Please provide no more than 9 numbers.");
		return (false);
	}
	for (int i = 1; i < ac; i++) {
		if (atoi(av[i]) == 0) {
				error_exit("only strictly positive integers allowed.");
				return (false);
			}
		if (atoi(av[i]) != atol(av[i])) {
				error_exit("input numbers must be less than INT_MAX.");
				return (false);
		}
		for (int y = 0; y < (int)strlen(av[i]); y++) {
			if (!isdigit(av[i][y])) {
				error_exit("input characters must be composed of digits only.");
				return (false);
			}
		}
	}
	return (true);
}