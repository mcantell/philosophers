/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:48:37 by mcantell          #+#    #+#             */
/*   Updated: 2024/10/24 12:29:56 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* Abbiamo la funzione di quando il filosofo pensa */
void	thinking(t_table *table, t_philo *philo)
{
	long long	current_time;
	int			index;

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
	long long	current_time;
	int			index;

	index = philo->index_philo;
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->next->fork);
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
	philo->sleeping = true;
	philo->thinking = true;
	philo->eating = false;
}
