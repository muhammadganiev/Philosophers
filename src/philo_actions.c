/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:22 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/11 19:06:10 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//Printing what philosopher doing

void	print_philo(t_table *table, t_philo *philo, char *str)
{
	int	i;

	pthread_mutex_lock(&table->dead);
	i = table->flg_of_dead;
	pthread_mutex_unlock(&table->dead);
	if (i)
		return ;
	pthread_mutex_lock(&table->print);
	if (i)
	{
		pthread_mutex_unlock(&table->print);
		return ;
	}
	printf("%lld %d %s\n", get_timestamp() - philo->time_start, philo->id, str);
	pthread_mutex_unlock(&table->print);
}

void	thinking(t_table *table, t_philo *philo)
{
	int	i;

	pthread_mutex_lock(&table->dead);
	i = table->flg_of_dead;
	pthread_mutex_unlock(&table->dead);
	if (i)
		return ;
	print_philo(table, philo, GRN"is thinking"RESET);
}

void	sleepeng(t_table *table, t_philo *philo)
{
	int	i;

	pthread_mutex_lock(&table->dead);
	i = table->flg_of_dead;
	pthread_mutex_unlock(&table->dead);
	if (i)
		return ;
	print_philo(table, philo, YEL"is sleeping"RESET);
	ft_usleep(table->time_to_sleep);
}

int	eating(t_table *tb, t_philo *philo)
{
	int	i;

	pthread_mutex_lock(&tb->dead);
	i = tb->flg_of_dead;
	pthread_mutex_unlock(&tb->dead);
	if (i)
		return (1);
	if (philo->id == tb->count_philo)
		pthread_mutex_lock(&tb->fork[philo->right]);
	else
		pthread_mutex_lock(&tb->fork[philo->left]);
	print_philo(tb, philo, BLUE"has taken a fork"RESET);
	if (tb->count_philo == 1)
		return (pthread_mutex_unlock(\
			&tb->fork[tb->philo->left]), 1);
	if (philo->id == tb->count_philo)
		pthread_mutex_lock(&tb->fork[philo->left]);
	else
		pthread_mutex_lock(&tb->fork[philo->right]);
	hi_norminnate(tb, philo);
	pthread_mutex_unlock(&tb->fork[philo->left]);
	pthread_mutex_unlock(&tb->fork[philo->right]);
	return (0);
}

void	hi_norminnate(t_table *tb, t_philo *philo)
{
	print_philo(tb, philo, BLUE"has taken a fork"RESET);
	print_philo(tb, philo, MAGENTA"is eating"RESET);
	pthread_mutex_lock(&tb->six);
	philo->how_many_eat++;
	pthread_mutex_unlock(&tb->six);
	pthread_mutex_lock(&tb->eat);
	philo->last_eat = get_timestamp();
	pthread_mutex_unlock(&tb->eat);
	ft_usleep(philo->time_to_eat);
}
