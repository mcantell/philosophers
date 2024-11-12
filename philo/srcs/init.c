/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:52:51 by mcantell          #+#    #+#             */
/*   Updated: 2024/11/12 16:51:54 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* inizializzo sia il tavolo sia la lista dei filosofi
** quando vado a creare la lista di filosofi vado a dare
** come riferimento il puntatore alla testa della lista
*/
int	init_table(char **argv, t_table *table)
{
	table->philo_index =  0;
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
	if(!create_new_philo(&table->philo, argv))
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

/* creo una lista circolare
** nell'if metto il caso in cui non esista nessun elemento della lista
** essendo che la voglio fare circolare metto un elemento che punta a se stesso
** sia come precedente sia come successivo
** nell'else creo appunto il resto della lista mantenenedola circolare
** all'inizio gli dico che al successivo di new gli do la test
** a quello precedente gli do l'ultimo della lista
** all'ultimo prima della testa aggiungo il nuovo nodo
** infine gli dico che il precedente alla testa e il nodo appena aggiunto
*/
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
