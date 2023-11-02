/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_forks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:04:14 by adurusoy          #+#    #+#             */
/*   Updated: 2023/11/02 15:52:46 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

int	create_forks(t_main *main)
{
	int	i;

	main->forks = malloc(sizeof(pthread_mutex_t) * main->input.num_philo + 1);
	if (main->forks == NULL)
		return (2);
	i = 0;
	while (i < main->input.num_philo)
	{
		if (pthread_mutex_init(&main->forks[i], NULL) != 0)
			return (3);
		i++;
	}
	return (1);
}

void	unlock_forks(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->input.num_philo)
	{
		pthread_mutex_unlock(&main->forks[i]);
		i++;
	}
}
