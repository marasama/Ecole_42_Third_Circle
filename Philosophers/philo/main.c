/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:04:45 by adurusoy          #+#    #+#             */
/*   Updated: 2023/11/02 19:30:36 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <stdio.h>

void	just_one_philo(t_main *main)
{
	long long	now;

	main->t0 = get_time();
	now = delta_time(main->t0);
	printf("%s%-10lld %-3d %-30s%s\n", B_BLUE, now, 1, FORK, RESET);
	exec_action(main->input.time_to_die);
	now = delta_time(main->t0);
	printf("%s%-10lld %-3d %-30s%s\n", PINK, now, 1, DIED, RESET);
	philo_free(main);
}

int	create_info(int argc, char **argv, t_main *main)
{
	int	i;

	i = 0;
	if (error_handling(argc, argv, main) == FALSE)
		return (1);
	if (create_philos(main) == FALSE)
		return (1);
	i = create_forks(main);
	if (i == 2 || i == 3)
	{
		free(main->philo);
		if (i == 3)
			free(main->forks);
		return (1);
	}
	if (main->input.num_philo == 1)
	{
		just_one_philo(main);
		return (2);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_main	main;
	int		i;

	i = create_info(argc, argv, &main);
	if (i == 1 || i == 2)
		return (1);
	if (create_threads(&main) == FALSE)
		return (1);
	if (destroy_threads(&main) == FALSE)
		return (1);
	philo_free(&main);
	return (0);
}
