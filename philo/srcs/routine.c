/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:56:03 by mcantell          #+#    #+#             */
/*   Updated: 2024/10/28 16:54:52 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* Qui creo la funzione che mi andra' a impostare il tutto per piu' filosofi*/
void	multiple_philo(t_table *table, t_philo *philo)
{
	while (1)
	{
		if (table->dinner_end)
			break ;
		if (philo->eating)
			eating(table, philo);
		if (philo->sleeping)
			sleeping(table, philo);
		if (philo->thinking)
			thinking(table, philo);
		if (table->philo_is_dead)
			break ;
	}
}

/* Qui vado a startare la routine che seguiranno i vari filosofi */
void	*start_routine(void *arg)
{
	t_table	*table;
	t_philo	*philo;

	table = (t_table*)arg;
	if (!table)
		return (NULL);
	philo = table->philo;
	pthread_mutex_lock(&table->sitting);
	while (philo->index_philo != table->philo_index + 1)
		philo = philo->next;
	table->philo_index++;
	table->dinner_start = get_time();
	if (philo->index_philo % 2 != 0)
		philo->eating = true;
	else
		philo->thinking = true;
	pthread_mutex_unlock(&table->sitting);
	if (one_philo(table, philo))
		return (NULL);
	multiple_philo(table, philo);

	return (NULL);
}

/* Qui io creo i thread e nella funzione gli passo la routine che faranno */
int	routine(t_table *table, pthread_t *thread)
{
	int	i;

	i = 0;
	while (i < table->philo_num)
	{
		if (pthread_create(&thread[i], NULL, start_routine, (void *)table))
		{
			printf(ERR_CREATE_PHILO);
			return (0);
		}
		i++;
	}
	i = 0;
	while (i <= table->philo_num)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	if (table->philo_is_dead)
		destroy_mutex(table, table->philo);
	free_list(&table->philo);
	return (1);
}
