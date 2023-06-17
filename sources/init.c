/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:22 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/17 14:38:53 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_thsize_t(t_pinfo *pinfo)
{
	if (init_forks(pinfo, pinfo->amount))
		return (1);
	if (thsize_t_init(&pinfo->finish, pinfo->amount))
		return (1);
	if (thsize_t_init(&pinfo->write, 0))
		return (1);
	if (thsize_t_init(&pinfo->quit, 0))
		return (1);
	return (0);
}

t_pinfo	*init_philosopher_info(size_t *params, int size)
{
	t_pinfo	*pinfo;

	if (size < 4)
		return (0);
	pinfo = malloc(sizeof(t_pinfo));
	if (!pinfo)
		return (0);
	pinfo->amount = params[0];
	pinfo->time_to_die = params[1];
	pinfo->time_to_eat = params[2];
	pinfo->time_to_sleep = params[3];
	if (size > 4)
		pinfo->amount_to_eat = params[4];
	else
		pinfo->amount_to_eat = -1;
	if (init_thsize_t(pinfo))
	{
		free(pinfo);
		return (0);
	}
	return (pinfo);
}

t_thdata	*init_thdata(t_pinfo *pinfo, t_philo *philo)
{
	t_thdata	*data;

	data = malloc(sizeof(t_thdata));
	if (!data)
		exit(1);
	data->pinfo = pinfo;
	data->philo = philo;
	return (data);
}

t_philo	*init_philo(t_pinfo *pinfo)
{
	size_t	i;
	t_philo	*philos;

	philos = malloc(sizeof(t_philo) * pinfo->amount);
	if (!philos)
		return (0);
	i = 0;
	while (i < pinfo->amount)
	{
		philos[i].id = i + 1;
		init_set_forks(&philos[i], i, pinfo->amount);
		philos[i].meals = 0;
		philos[i].state = START;
		philos[i].createdt = 0;
		philos[i].last_eatt = 0;
		i++;
	}
	return (philos);
}
