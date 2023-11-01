/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 08:37:57 by ivaliev           #+#    #+#             */
/*   Updated: 2023/11/01 13:24:23 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	ft_atoi(const char *str)
{
	long long int	c;
	int				b;
	int				d;

	b = 0;
	c = 0;
	d = 0;
	while (str[b] == 32 || (str[b] <= 13 && str[b] >= 9))
		b++;
	if (str[b] == '-' || str[b] == '+')
	{
		d = b;
		b++;
	}
	while (str[b] == 48)
		b++;
	while (str[b] < 58 && str[b] > 47)
	{
		c = (c * 10) + (str[b] - 48);
		b++;
	}
	if (str[d] == '-')
		c = -c;
	return (c);
}

int	ft_strlen(char *a)
{
	int	b;

	if (!a)
		return (0);
	b = 0;
	while (a[b])
		b++;
	return (b);
}

void	print(t_philo *philo, int id, char *is_doing)
{
	pthread_mutex_lock(&(philo->info->printig));
	if (!ft_check_died(philo))
	{
		printf("%lli %i %s\n", get_time() - philo->info->start_time,
			id + 1, is_doing);
	}
	pthread_mutex_unlock(&(philo->info->printig));
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
