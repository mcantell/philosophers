/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:38:07 by mcantell          #+#    #+#             */
/*   Updated: 2024/10/28 16:24:00 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	ft_atol(char *str)
{
	long	num;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	num = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return (num * sign);
}

long long	get_time(void)
{
	long long		time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	time = (long long)tv.tv_sec * 1000LL + (long long)tv.tv_usec / 1000;
	return (time);
}

void	destroy_mutex(t_table *table, t_philo *philo)
{
	pthread_mutex_destroy(&table->writing);
	pthread_mutex_destroy(&table->eating);
	pthread_mutex_destroy(&table->sitting);
	pthread_mutex_destroy(&philo->fork);
}

void	free_list(t_philo **philo)
{
	t_philo	*current;
	t_philo	*next;

	current = *philo;
	if (!current)
		return ;
	while (1)
	{
		next = current->next;
		free (current);
		if (next == *philo)
			return ;
		current = current->next;
	}
}
