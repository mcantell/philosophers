/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:52:55 by mcantell          #+#    #+#             */
/*   Updated: 2024/09/26 15:18:19 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc <= 4 || argc > 6)
	{
		printf (ERR_NUM_ARGS);
		return (1);
	}
	if (!check_philo_num(argv[i]))
		return (1);
	while (argv[i])
	{
		if (!ft_isdigit_str(argv[i]))
			return (1);
		if (!check_is_positive(argv[i]))
		{
			printf(ERR_POSITIVE);
			return (1);
		}
		if (!check_input_num(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
