/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:22 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/17 14:38:53 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	philo_current_time(t_philo *philo)
{
	return (ft_get_time() - philo->createdt);
}

void	set_forks_status(t_pinfo *pinfo, t_philo *philo, size_t value)
{
	pthread_mutex_lock(&pinfo->forks[philo->lfork].mutex);
	pthread_mutex_lock(&pinfo->forks[philo->rfork].mutex);
	pinfo->forks[philo->lfork].value = value;
	pinfo->forks[philo->rfork].value = value;
	pthread_mutex_unlock(&pinfo->forks[philo->rfork].mutex);
	pthread_mutex_unlock(&pinfo->forks[philo->lfork].mutex);
}

static int	check_status(size_t status, t_philo *philo)
{
	return (status != philo->id && status != philo->maskout_fork);
}

int	get_forks_status(t_pinfo *pinfo, t_philo *philo)
{
	size_t	status[2];

	pthread_mutex_lock(&pinfo->forks[philo->lfork].mutex);
	pthread_mutex_lock(&pinfo->forks[philo->rfork].mutex);
	status[0] = pinfo->forks[philo->lfork].value;
	status[1] = pinfo->forks[philo->rfork].value;
	pthread_mutex_unlock(&pinfo->forks[philo->rfork].mutex);
	pthread_mutex_unlock(&pinfo->forks[philo->lfork].mutex);
	return (status[0] && status[1]
		&& (check_status(status[0], philo) || check_status(status[1], philo)));
}

void	update_meals(t_pinfo *pinfo, t_philo *philo)
{
	philo->meals++;
	if (pinfo->amount_to_eat == -1)
		return ;
	pthread_mutex_lock(&pinfo->finish.mutex);
	if (philo->meals == pinfo->amount_to_eat && !--pinfo->finish.value)
		pstate_transition(pinfo, philo, FINISHED);
	pthread_mutex_unlock(&pinfo->finish.mutex);
}
