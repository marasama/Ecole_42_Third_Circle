/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:04:38 by adurusoy          #+#    #+#             */
/*   Updated: 2023/11/02 21:56:04 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>
#include <unistd.h>

/*
** tv_sec is in seconds, 1 second = 1000 milliseconds
** tv_usec is in microseconds, 1 microsecond = 0.001 milliseconds
*/

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

long long	delta_time(long long time)
{
	if (time > 0)
		return (get_time() - time);
	return (0);
}

void	ft_usleep(long long time)
{
	long long	start;

	start = get_time() + time;
	while (get_time() <= start)
		usleep(500);
}

void	exec_action(long long time)
{
	ft_usleep(time);
}
