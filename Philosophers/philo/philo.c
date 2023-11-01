/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 08:40:24 by ivaliev           #+#    #+#             */
/*   Updated: 2023/11/01 14:37:58 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check(int ac, char **av)
{
	int			i;
	int			j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	atoi_check(char *s)
{
	int		b;

	b = 0;
	if (s[b] == '-' || s[b] == '+')
		b++;
	while (s[b] < 58 && s[b] > 47)
		b++;
	if (b == 1 && (s[0] == '+' || s[0] == '-'))
		return (0);
	return (b);
}

int	check_int(char **a, int b)
{
	int		c;
	int		d;

	if (!a[b])
		return (0);
	while (a[b])
	{
		if (!a[b][0])
			return (0);
		c = ft_strlen(a[b]);
		d = atoi_check(a[b]);
		if (c != d || d > 11)
			return (0);
		if (ft_atoi(a[b]) < 0 || ft_atoi(a[b]) > 2147483647)
			return (0);
		b++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_philo		philo;
	t_info		info;

	if (ac > 6 || ac < 5)
	{
		printf("Invalid arguments\n");
		return (0);
	}
	if (check_int(av, 1) == 0)
	{
		printf("Error found letter in arguments\n");
		return (0);
	}
	info_init(&philo, &info, ac, av);
	return (0);
}
