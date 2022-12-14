/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:06:14 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/18 23:34:15 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo	t_philo;

enum e_errors
{
	ERR_NB_ARGUMENTS = 1,
	ERR_INVALID_VALUE,
	ERR_THREAD_CREATION,
	ERR_MUTEX_INIT,
	ERR_MALLOC,
	ERR_JOIN_THREAD,
	ERR_MUTEX_DESTROY,
};

typedef struct s_args
{
	int			nb_philos;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	int			nb_of_times_they_must_eat;
}	t_args;

typedef struct s_rules
{
	int				all_alive;
	int				all_meals_eaten;
	long long		start_time;
	pthread_mutex_t	*fork_array;
	pthread_mutex_t	msg_log;
	t_args			args;
	t_philo			*philos_array;
}	t_rules;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	long long		last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_rules			*rules;
}	t_philo;

// mini_libft.c : because entire libft is not allowed
int			ft_atoi(const char *str);

// init.c : init structures' variables
void		init_args(int argc, char **argv, t_rules *rules);
int			init_rules(t_rules *rules);

// utils.c : fonctions utiles propre à ce projet
int			error(t_rules *rules, int type_of_error);
int			check_args(int argc, char **argv);
long long	get_time_in_ms(void);

// start_simulation.c : le démarrage du tout
int			start_simulation(t_rules *rules);

// routine.c : la routine, vie de philosophes
void		*routine(void *philo);
#endif
