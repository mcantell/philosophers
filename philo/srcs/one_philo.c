/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:13:39 by mcantell          #+#    #+#             */
/*   Updated: 2024/10/21 16:29:35 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	one_philo(t_table *table, t_philo *philo)
{
	if (table->philo_num == 1)
	{
		pthread_mutex_lock(&table->writing);
		printf("0 1 has taken fork\n");
		usleep(table->death_time * 1000);
		table->dinner_end = true;
		philo->is_dead = true;
		printf("%d %d died\n", table->death_time, table->philo_num);
		pthread_mutex_unlock(&table->writing);
		return (1);
	}
	return (0);
}
