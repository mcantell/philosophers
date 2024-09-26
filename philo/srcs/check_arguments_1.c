/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:50:52 by mcantell          #+#    #+#             */
/*   Updated: 2024/09/26 15:17:26 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isdigit_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (str[i] && !ft_isdigit(str[i]))
		{
			printf(ERR_ARGS_DIGIT);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_is_positive(char *str)
{
	long	num;

	num = ft_atol(str);
	if (num < 0 || num >= 2147483647)
		return (0);
	return (1);
}

int	check_input_num(char *str)
{
	int	num;

	num = ft_atol(str);
	if (num == 0)
	{
		printf(ERR_NUM_IMPUT);
		return (0);
	}
	return (1);
}

int	check_philo_num(char *str)
{
	int	num;

	num = ft_atol(str);
	if (num > 200)
	{
		printf(ERR_NUM_PHILO);
		return (0);
	}
	return (1);
}
