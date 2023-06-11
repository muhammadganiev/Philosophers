/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:22 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/11 19:07:08 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	ft_atoi(const char *str)
{
	int					i;
	int					flag;
	unsigned long long	nbr;

	i = 0;
	nbr = 0;
	flag = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-')
		flag = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	if (str[i] && (str[i] < '0' || str[i] > '9'))
		return (-1);
	if (flag == 1 && nbr >= 9223372036854775807u)
		return (-1);
	if (flag == -1 && nbr >= 9223372036854775808u)
		return (0);
	return (nbr * flag);
}

//geting current time
//struct timeval ... {time_t tv_sec(seconds); tv_usec(microseconds)}

long long	get_timestamp(void)
{
	struct timeval	time;
	long long		now;

	gettimeofday(&time, NULL);
	now = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (now);
}

//Destoing mutexs;

void	ft_destroy_mutex(t_table *all)
{
	int	i;

	i = -1;
	while (++i < all->count_philo)
		if (pthread_mutex_destroy(&all->fork[i]))
			printf("Error destroy mutex %d.\n", i);
	pthread_mutex_destroy(&all->print);
	pthread_mutex_destroy(&all->eat);
	pthread_mutex_destroy(&all->dead);
	pthread_mutex_destroy(&all->six);
}

int	ft_free(t_table *all)
{
	if (all->philo)
		free(all->philo);
	if (all->fork)
		free(all->fork);
	if (all->thread)
		free(all->thread);
	free(all);
	return (1);
}

void	ft_usleep(int time_ms)
{
	long long	start;

	start = get_timestamp();
	while (get_timestamp() - start < time_ms)
		usleep(100);
}
