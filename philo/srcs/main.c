/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:11:37 by mcantell          #+#    #+#             */
/*   Updated: 2024/10/21 16:26:17 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_table		table;
	pthread_t	*thread;

	if (check_args(argc, argv) == 1)
		return (0);
	if (!init_table(argv, &table))
	{
		printf(ERR_INIT_TABLE);
		return (0);
	}
	thread = malloc(sizeof(pthread_t) * (ft_atol(argv[1]) + 1));
	if (!thread)
	{
		printf(ERR_INIT_THREAD);
		return (0);
	}
	if (!routine(&table, thread))
		return (0);
}
