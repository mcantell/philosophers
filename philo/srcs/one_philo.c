/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:13:39 by mcantell          #+#    #+#             */
/*   Updated: 2024/09/27 15:35:57 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_is_one(t_table *table)
{
	if (table->philo_num == 1)
	{
		usleep(table->death_time * 1000);
		table->philo_is_dead = true;
		printf("%d %d died\n", table->death_time, table->philo_num);
		return (1);
	}
	return (0);
}
