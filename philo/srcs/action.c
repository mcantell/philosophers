/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:48:37 by mcantell          #+#    #+#             */
/*   Updated: 2024/10/28 15:58:54 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	eating_utils(t_table *table, t_philo *philo);


/* Abbiamo la funzione di quando il filosofo pensa */
void	thinking(t_table *table, t_philo *philo)
{
	long long	current_time;
	int			index;
	if (table->dinner_end)
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

	if (table->dinner_end)
		return ;
	index = philo->index_philo;
	current_time = get_time();
	pthread_mutex_lock(&table->writing);
	printf("%lld %d is sleeping\n", current_time - table->dinner_start, index);
	pthread_mutex_unlock(&table->writing);
	usleep(philo->time_sleep * 1000);
	philo->sleeping = false;
	philo->eating = true;
}

/* Adesso faccio la funzione per il mangiare */
void	eating(t_table *table, t_philo *philo)
{
	before_eating(table, philo);
	eating_utils(table, philo);
	philo->index_meal++;
	if (philo->index_meal == table->meal_num
		&& philo->index_philo == table->philo_num)
		table->dinner_end = true;
	philo->sleeping = true;
	if (table->philo_num % 2 != 0)
		philo->thinking = true;
	philo->eating = false;
	philo->last_meal = get_time();
}
static void	eating_utils(t_table *table, t_philo *philo)
{
	long long	current_time;
	int			index;

	index = philo->index_philo;
	pthread_mutex_lock(&philo->next->fork);
	pthread_mutex_lock(&philo->fork);
	current_time = get_time();
	pthread_mutex_lock(&table->writing);
	if (table->dinner_end)
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		pthread_mutex_unlock(&table->writing);
		return ;
	}
	printf("%lld %d is eating\n", current_time - table->dinner_start, index);
	pthread_mutex_unlock(&table->writing);
	usleep(philo->time_dinner * 1000);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

/* per adesso mi calcolo un tempo di morte solo maggiore ma non uguale*/
void	before_eating(t_table *table, t_philo *philo)
{
	int			index;

	index = philo->index_philo;
	if (table->dinner_start - philo->last_meal > philo->time_death)
	{
		table->philo_is_dead = true;
		philo->is_dead = true;
		pthread_mutex_lock(&table->writing);
		printf("%d ")
	}
}
