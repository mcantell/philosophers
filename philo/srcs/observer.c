/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:32:04 by mcantell          #+#    #+#             */
/*   Updated: 2024/11/12 16:46:47 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	meal_check(t_table *table)
{
	int		meal_index;
	t_philo	*philo;

	meal_index = 0;
	philo = table->philo;
	while (1)
	{
		if (philo->index_meal == table->meal_num)
		{
			meal_index++;
			if (meal_index == table->philo_num)
			{
				table->dinner_is_end = true;
				return ;
			}
		}
		philo = philo->next;
		if (philo == table->philo)
			break ;
	}
}

void	death_check(t_table *table)
{
	t_philo		*philo;
	long long	current_time;

	philo = table->philo;
	while (1)
	{
		current_time = get_time();
		if (philo->last_meal &&
			(current_time - philo->last_meal >= philo->time_death))
		{
			pthread_mutex_lock(&table->writing);
			printf("%lld %d is dead\n", current_time - philo->last_meal, philo->index_philo);
			pthread_mutex_unlock(&table->writing);
			table->dinner_is_end = true;
			return ;
		}
		philo = philo->next;
		if (philo == table->philo)
			break ;
	}
}

void	observer_check(t_table *table)
{
	while (!table->dinner_is_end)
	{
		if (table->philo->index_meal > 0)
			meal_check(table);
		if (!table->dinner_is_end)
			death_check(table);
		if (table->dinner_is_end)
			break ;
		usleep(100);
	}
}

void	*observer_routine(void *arg)
{
	t_table *table;

	table = (t_table*)arg;
	if (table->philo_num > 1)
		observer_check(table);
	return (NULL);
}
