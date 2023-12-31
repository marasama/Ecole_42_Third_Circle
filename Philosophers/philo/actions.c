/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:03:57 by adurusoy          #+#    #+#             */
/*   Updated: 2023/11/02 21:54:57 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

int	philo_eat(t_main *main, int i)
{
	usleep(100);
	if (pthread_mutex_lock(&main->forks[main->philo[i].fork.left]) != 0)
		return (FALSE);
	if (philo_print(main, main->philo[i].id, B_BLUE, FORK) == FALSE)
		return (FALSE);
	if (pthread_mutex_lock(&main->forks[main->philo[i].fork.right]) != 0)
		return (FALSE);
	if (philo_print(main, main->philo[i].id, B_BLUE, FORK) == FALSE)
		return (FALSE);
	if (philo_print(main, main->philo[i].id, G_CYAN, EAT) == FALSE)
		return (FALSE);
	main->philo[i].time_to_die = get_time();
	exec_action(main->input.time_to_eat);
	drop_forks(main, i);
	return (TRUE);
}

int	philo_sleep(t_main *main, int i)
{
	if (philo_print(main, main->philo[i].id, BLUE, SLEEP) == FALSE)
		return (FALSE);
	exec_action(main->input.time_to_sleep);
	return (TRUE);
}

int	philo_think(t_main *main, int i)
{
	if (philo_print(main, main->philo[i].id, G_BLUE, THINK) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	philo_is_dead(t_main *main, int *i)
{
	int	time;

	if (*i == main->input.num_philo)
		*i = 0;
	time = delta_time(main->philo[*i].time_to_die);
	if (time > main->input.time_to_die)
	{
		philo_print(main, main->philo[*i].id, PINK, DIED);
		main->philo_dead = TRUE;
		return (TRUE);
	}
	(*i)++;
	return (FALSE);
}

int	drop_forks(t_main *main, int i)
{
	if (pthread_mutex_unlock(&main->forks[main->philo[i].fork.left]))
		return (FALSE);
	if (pthread_mutex_unlock(&main->forks[main->philo[i].fork.right]))
		return (FALSE);
	main->philo[i].num_of_times_ate++;
	return (TRUE);
}
