/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:52:51 by mcantell          #+#    #+#             */
/*   Updated: 2024/11/14 13:48:55 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_table(char **argv, t_table *table)
{
	table->philo_index = 0;
	table->philo_num = ft_atol(argv[1]);
	table->death_time = ft_atol(argv[2]);
	table->dinner_end = 0;
	table->dinner_start = 0;
	table->meal_num = -1;
	table->philo = NULL;
	table->philo_is_dead = false;
	table->dinner_is_end = false;
	if (pthread_mutex_init(&table->sitting, NULL)
		|| pthread_mutex_init(&table->eating, NULL)
		|| pthread_mutex_init(&table->writing, NULL))
		return (0);
	if (argv[5])
		table->meal_num = ft_atol(argv[5]);
	if (!create_new_philo(&table->philo, argv))
		return (0);
	return (1);
}

int	init_philo(t_philo *philo, char **argv, int i)
{
	philo->index_philo = i + 1;
	philo->time_death = ft_atol(argv[2]);
	philo->time_dinner = ft_atol(argv[3]);
	philo->time_sleep = ft_atol(argv[4]);
	philo->last_meal = 0;
	philo->index_meal = 0;
	philo->is_dead = false;
	philo->eating = false;
	philo->thinking = false;
	philo->sleeping = false;
	if (pthread_mutex_init(&philo->fork, NULL))
		return (0);
	return (1);
}

int	create_new_philo(t_philo **philo, char **av)
{
	int		i;
	t_philo	*new_philo;

	i = 0;
	while (i < ft_atol(av[1]))
	{
		new_philo = malloc(sizeof(t_philo));
		if (!new_philo || !init_philo(new_philo, av, i))
			return (0);
		if (!*philo)
		{
			new_philo->next = new_philo;
			new_philo->prev = new_philo;
			*philo = new_philo;
		}
		else
		{
			new_philo->next = *philo;
			new_philo->prev = (*philo)->prev;
			(*philo)->prev->next = new_philo;
			(*philo)->prev = new_philo;
		}
		i++;
	}
	return (1);
}
