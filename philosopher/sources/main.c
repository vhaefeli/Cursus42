/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:31:39 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/11 14:16:25 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_args 			args;
	t_rules			rules;
	t_philo			*philos;
	struct timeval	tp;

	if (argc < 5 || argc > 6)
		return (error(NB_ARGUMENTS));
	if (!are_args_valid(argc, argv))
		return (error(INVALID_VALUE));
	init_args(argc, argv, &args);
	gettimeofday(&tp, NULL);
	global.prog_start = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	get_time_in_ms(&tp, &global);
	philos = create_philos(&args, &global);
	forks = create_forks(&args);
	global.philos = philos;
	global.forks = forks;
	int i = 0;
	while (i < args.nb_of_philos)
	{
		printf("philosophe : %d\n", global.philos->id);
		++i;
	}
/* 	if (args.nb_of_philos == 1)
		return (one_philo_routine(&rules));
	return (philos_routine(&rules)); */
}
