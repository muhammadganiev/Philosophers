/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:22 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/11 18:49:23 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Inicialization stuctures of philosopher

int	init_phiolo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->count_philo)
	{
		table->philo[i].id = i + 1;
		table->philo[i].time_to_eat = table->time_to_eat;
		table->philo[i].time_to_die = table->time_to_die;
		table->philo[i].time_to_sleap = table->time_to_sleep;
		table->philo[i].how_many_eat = 0;
		table->philo[i].left = i;
		if (i < table->count_philo - 1)
			table->philo[i].right = i + 1;
		else
			table->philo[i].right = 0;
		table->philo[i].last_eat = 0;
		table->philo[i].arg = table;
		i++;
	}
	i = 0;
	while (i < table->count_philo)
		if (pthread_mutex_init(&table->fork[i++], NULL))
			return (1);
	return (0);
}

t_table	*init(int ac, char **av)
{
	t_table	*arg;

	arg = malloc(sizeof(t_table));
	if (!arg)
		return (NULL);
	arg->count_philo = ft_atoi(av[1]);
	arg->time_to_die = ft_atoi(av[2]);
	arg->time_to_eat = ft_atoi(av[3]);
	arg->time_to_sleep = ft_atoi(av[4]);
	arg->count_lanch = 0;
	if (ac == 6)
		arg->count_lanch = ft_atoi(av[5]);
	arg->flg_of_dead = 0;
	arg->time_start = 0;
	pthread_mutex_init(&arg->print, NULL);
	pthread_mutex_init(&arg->eat, NULL);
	pthread_mutex_init(&arg->dead, NULL);
	pthread_mutex_init(&arg->six, NULL);
	arg->philo = NULL;
	arg->thread = NULL;
	arg->fork = NULL;
	return (arg);
}

int	init_time(t_table *all)
{
	all->philo = malloc(sizeof(t_philo) * all->count_philo);
	if (!all->philo)
		return (1);
	all->fork = malloc(sizeof(pthread_mutex_t) * all->count_philo);
	if (!all->fork)
		return (1);
	all->thread = malloc(sizeof(pthread_t) * (all->count_philo + 1));
	if (!all->thread)
		return (1);
	return (0);
}

void	*hell(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&table->dead);
	table->flg_of_dead = 1;
	pthread_mutex_unlock(&table->dead);
	pthread_mutex_lock(&table->print);
	printf("%lld %d" RED " is died\n"RESET,
		get_timestamp() - philo->time_start, philo->id);
	pthread_mutex_unlock(&table->print);
	return (NULL);
}

void	*check_dead(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&table->six);
	if (philo->how_many_eat == table->count_lanch)
	{
		pthread_mutex_unlock(&table->six);
		return (NULL);
	}
	pthread_mutex_unlock(&table->six);
	return (NULL);
}
