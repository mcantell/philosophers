/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:48:37 by mcantell          #+#    #+#             */
/*   Updated: 2024/11/15 15:07:28 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	eating_utils(t_table *table, t_philo *philo);
static int	before_eating(t_table *table, t_philo *philo);

/* Abbiamo la funzione di quando il filosofo pensa */
void	thinking(t_table *table, t_philo *philo)
{
	long long	current_time;
	int			index;

	if (table->dinner_is_end)
		return ;
	index = philo->index_philo;
	current_time = get_time();
	pthread_mutex_lock(&table->writing);
	printf("%lld %d is thinking\n", current_time - table->dinner_start, index);
	pthread_mutex_unlock(&table->writing);
	if (table->philo_num % 2 != 0)
		usleep(philo->time_dinner * 1000);
	philo->thinking = false;
	philo->eating = true;
}

/* Qua faccio la funzione per dormire */
void	sleeping(t_table *table, t_philo *philo)
{
	long long	current_time;
	int			index;

	if (table->dinner_is_end)
		return ;
	index = philo->index_philo;
	current_time = get_time();
	pthread_mutex_lock(&table->writing);
	printf("%lld %d is sleeping\n", current_time - table->dinner_start, index);
	pthread_mutex_unlock(&table->writing);
	usleep(philo->time_sleep * 1000);
	philo->sleeping = false;
	philo->thinking = true;
	philo->eating = true;
}

void	eating(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->next->fork);
	if (before_eating(table, philo))
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		return ;
	}
	if (table->dinner_is_end)
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		return ;
	}
	eating_utils(table, philo);
	philo->index_meal++;
	if (table->meal_num != -1 && philo->index_meal == table->meal_num
		&& philo->index_philo == table->philo_num)
		table->dinner_is_end = true;
	philo->sleeping = true;
	if (table->philo_num % 2 != 0)
		philo->thinking = true;
	philo->eating = false;
}

static void	eating_utils(t_table *table, t_philo *philo)
{
	long long	current_time;
	int			index;

	current_time = get_time();
	pthread_mutex_lock(&table->writing);
	printf("%lld %d has taken a fork\n%lld %d has taken a fork\n",
		current_time - table->dinner_start, philo->index_philo,
		current_time - table->dinner_start, philo->index_philo);
	pthread_mutex_unlock(&table->writing);
	index = philo->index_philo;
	pthread_mutex_lock(&table->writing);
	printf("%lld %d is eating\n", current_time - table->dinner_start, index);
	pthread_mutex_unlock(&table->writing);
	philo->last_meal = get_time();
	usleep(philo->time_dinner * 1000);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

/* per adesso mi calcolo un tempo di morte solo maggiore ma non uguale */
static int	before_eating(t_table *table, t_philo *philo)
{
	int				index;
	long long int	current_time;

	index = philo->index_philo;
	if (philo->index_meal == 0 && (index % 2 == 0 || index == table->philo_num))
	{
		current_time = get_time();
		if (current_time - table->dinner_start >= philo->time_death)
		{
			table->philo_is_dead = true;
			philo->is_dead = true;
			table->dinner_is_end = true;
			pthread_mutex_lock(&table->writing);
			printf("%lld %d is dead\n",
				current_time - table->dinner_start, index);
			pthread_mutex_unlock(&table->writing);
			return (1);
		}
	}
	return (0);
}
