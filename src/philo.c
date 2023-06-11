/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:22 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/11 19:45:22 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//Check: Philo dead or not

void	*near_to_die(void *tmp)
{
	t_table			*table;
	t_philo			*philo;
	int				i;
	long long int	test;

	test = 0;
	table = tmp;
	philo = table->philo;
	while (1)
	{
		i = -1;
		while (++i < table->count_philo)
		{	
			pthread_mutex_lock(&table->eat);
			test = philo->last_eat;
			pthread_mutex_unlock(&table->eat);
			if (table->count_lanch)
				check_dead(table, philo);
			if (get_timestamp() - test > philo[i].time_to_die)
				if (hell(table, philo) == NULL)
					return (NULL);
		}
	}
	return (NULL);
}

// Parse arguments

int	parse(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		printf(RED "Error: Wrong number of arguments.\n");
		return (1);
	}
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0
		|| ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0
		|| (ac == 6 && ft_atoi(av[5]) <= 0))
	{
		printf(RED "Error: Wrong arguments.\n");
		return (1);
	}
	return (0);
}

void	*start_action(void *ag)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)ag;
	table = philo->arg;
	if (philo->id % 2 == 0)
		usleep(100);
	pthread_mutex_lock(&table->dead);
	while (!table->flg_of_dead)
	{
		pthread_mutex_unlock(&table->dead);
		if (table->count_lanch)
			if (philo->how_many_eat == table->count_lanch)
				return (NULL);
		if (eating(table, philo))
			return (NULL);
		sleepeng(table, philo);
		thinking(table, philo);
		pthread_mutex_lock(&table->dead);
	}
	pthread_mutex_unlock(&table->dead);
	return (NULL);
}

// Init philos time and processes

int	philo_init_time_and_processes(t_table *ph)
{
	pthread_t	check;
	int			i;

	i = -1;
	ph->time_start = get_timestamp();
	while (++i < ph->count_philo)
	{
		ph->philo[i].time_start = ph->time_start;
		ph->philo[i].last_eat = ph->time_start;
	}
	i = -1;
	while (++i < ph->count_philo)
		pthread_create(&ph->thread[i], NULL, &start_action, &ph->philo[i]);
	pthread_create(&check, NULL, &near_to_die, ph);
	pthread_join(check, NULL);
	i = -1;
	while (++i < ph->count_philo)
		pthread_join(ph->thread[i], NULL);
	return (0);
}

int	main(int ac, char **av)
{
	t_table	*all;

	if (parse(ac, av))
		return (1);
	all = init(ac, av);
	if (!all)
		return (ft_free(all));
	if (init_time(all))
		return (ft_free(all));
	if (init_pilo(all))
		return (ft_free(all));
	philo_init_time_and_processes(all);
	ft_destroy_mutex(all);
	ft_free(all);
	return (0);
}
