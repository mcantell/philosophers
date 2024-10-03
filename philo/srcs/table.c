/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:52:51 by mcantell          #+#    #+#             */
/*   Updated: 2024/09/27 15:31:10 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_table(char **argv, t_table *table)
{
	table->philo_index = 0;
	table->philo_num = ft_atol(argv[1]);
	table->death_time = ft_atol(argv[2]);
	table->dinner_end = 0;
	if (argv[5])
		table->meal_num = ft_atol(argv[5]);
	return (1);
}
