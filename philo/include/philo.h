/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:09:15 by mcantell          #+#    #+#             */
/*   Updated: 2024/11/12 16:47:06 by mcantell         ###   ########.fr       */
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

typedef struct s_philo
{
	int				time_death;
	int				index_philo;
	int				time_dinner;
	int				time_sleep;
	long long		last_meal;
	int				index_meal;
	t_bool			sleeping;
	t_bool			eating;
	t_bool			thinking;
	t_bool			is_dead;
	pthread_mutex_t	fork;
	struct s_philo *next;
	struct s_philo *prev;
}	t_philo;

typedef struct s_table
{
	long long		dinner_end;
	long long		dinner_start;
	t_bool			philo_is_dead;
	t_bool			dinner_is_end;
	int				philo_num;
	int				philo_index;
	int				meal_num;
	int				death_time;
	pthread_mutex_t	writing;
	pthread_mutex_t sitting;
	pthread_mutex_t	eating;
	t_philo			*philo;
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
/* init philo list */
int			create_new_philo(t_philo **philo, char **av);
int			init_philo(t_philo *philo, char **argv, int i);
/* check if is one philo */
int			one_philo(t_table *table, t_philo *philo);
/* main utils*/
long		ft_atol(char *str);
long long	get_time(void);
void		destroy_mutex(t_table *table);
void		free_list(t_philo **philo);
/* routine */
void		multiple_philo(t_table *table, t_philo *philo);
int			routine(t_table *table, pthread_t *thread);
void		*start_routine(void *);
/* action */
void		thinking(t_table *table, t_philo *philo);
void		sleeping(t_table *table, t_philo *philo);
void		eating(t_table *table, t_philo *philo);
/* observer */
void		*observer_routine(void *arg);
void		observer_check(t_table *table);
void		death_check(t_table *table);
void		meal_check(t_table *table);
#endif
