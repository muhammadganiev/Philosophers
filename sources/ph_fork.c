/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:22 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/16 19:17:09 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_pinfo *pinfo, size_t size)
{
	size_t			i;

	pinfo->forks = malloc(sizeof(t_thsize_t) * size);
	if (!pinfo->forks)
		return (1);
	i = 0;
	while (i < size)
	{
		if (thsize_t_init(&pinfo->forks[i], 1))
		{
			free(pinfo->forks);
			return (1);
		}
		i++;
	}
	return (0);
}

void	init_set_forks(t_philo *philo, int i, int amount)
{
	if (philo->id % 2)
	{
		philo->lfork = i;
		philo->rfork = (i + 1) % amount;
	}
	else
	{
		philo->lfork = (i - 1) % amount;
		philo->rfork = i;
	}
	if (amount % 2 == 0)
		philo->maskout_fork = philo->id;
	else if (i == 0)
		philo->maskout_fork = 2;
	else if (i == 1)
		philo->maskout_fork = amount;
	else if (i == amount - 1)
		philo->maskout_fork = 1;
	else
		philo->maskout_fork = philo->id;
}
