/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:11:37 by mcantell          #+#    #+#             */
/*   Updated: 2024/09/27 15:16:15 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (check_args(argc, argv) == 1)
		return (0);
	if (!init_table(argv, &table))
	{
		printf(ERR_INIT_TABLE);
		return (0);
	}
	if (check_is_one(&table))
		return (0);
}
