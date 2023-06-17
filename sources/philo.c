/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:22 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/17 14:38:52 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_app(t_pinfo *pinfo, t_philo *philos)
{
	size_t	i;

	i = 0;
	while (i < pinfo->amount)
	{
		thsize_t_destroy(&pinfo->forks[i], 0);
		i++;
	}
	thsize_t_destroy(&pinfo->finish, 0);
	thsize_t_destroy(&pinfo->write, 0);
	thsize_t_destroy(&pinfo->quit, 0);
	free(philos);
	free(pinfo->forks);
	free(pinfo);
}

static int	init_threads(t_pinfo *pinfo, t_philo *philos)
{
	size_t	i;

	i = 0;
	while (i < pinfo->amount)
	{
		if (pthread_create(&philos[i].thid, NULL,
				&philo_routine, init_thdata(pinfo, &philos[i])))
			return (1);
		usleep(100);
		i++;
	}
	i = 0;
	while (i < pinfo->amount)
	{
		if (pthread_join(philos[i].thid, NULL))
			return (1);
		i++;
	}
	return (0);
}

static int	run_app(size_t *params, int size)
{
	t_pinfo	*pinfo;
	t_philo	*philos;
	int		status;

	pinfo = init_philosopher_info(params, size);
	if (!pinfo || !pinfo->amount_to_eat)
		return (1);
	philos = init_philo(pinfo);
	if (!philos)
		return (1);
	status = init_threads(pinfo, philos);
	free_app(pinfo, philos);
	return (status);
}

int	main(int ac, char **av)
{
	size_t	*params;
	int		len;

	len = ac - 1;
	params = parsing_arg(av + 1, len);
	if (params && !run_app(params, len))
	{
		free(params);
		return (0);
	}
	printf("Error\n");
	free(params);
	return (1);
}
