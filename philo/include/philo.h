/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:09:15 by mcantell          #+#    #+#             */
/*   Updated: 2024/09/27 15:31:00 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <time.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include "messages.h"

typedef enum e_bool
{
	false = 0,
	true = 1,
}	t_bool;

typedef struct e_table
{
	long long	dinner_end;
	t_bool		philo_is_dead;
	int			philo_num;
	int			philo_index;
	int			meal_num;
	int			death_time;

}	t_table;

/* check_arguments utils */
int			ft_isdigit(int c);
int			ft_isdigit_str(char *str);
int			check_is_positive(char *str);
int			check_input_num(char *str);
int			check_philo_num(char *str);
/* check arguments */
int			check_args(int argc, char **argv);
/* init table */
int			init_table(char **argv, t_table *table);
/* check if is one philo */
int			check_is_one(t_table *table);
/* main utils*/
long		ft_atol(char *str);
long long	get_time(void);

#endif
