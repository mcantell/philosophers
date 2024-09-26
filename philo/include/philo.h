/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:09:15 by mcantell          #+#    #+#             */
/*   Updated: 2024/09/26 15:19:21 by mcantell         ###   ########.fr       */
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

/* check_arguments utils */
int		ft_isdigit(int c);
int		ft_isdigit_str(char *str);
int		check_is_positive(char *str);
int		check_input_num(char *str);
int		check_philo_num(char *str);
/* check arguments */
int		check_args(int argc, char **argv);
/* main utils*/
long	ft_atol(char *str);

#endif
