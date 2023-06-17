/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:22 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/17 14:32:32 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

void	log_philo(t_pinfo *info, t_philo *philo, char *prefix, char *suffix)
{
	pthread_mutex_lock(&info->write.mutex);
	if (thsize_t_get(&info->quit))
	{
		pthread_mutex_unlock(&info->write.mutex);
		return ;
	}
	printf("%s%zu %zu %s\n", prefix, philo_current_time(philo), philo->id, suffix);
	pthread_mutex_unlock(&info->write.mutex);
}

void	log_philo_woid(t_pinfo *info, t_philo *philo,
	char *prefix, char *suffix)
{
	pthread_mutex_lock(&info->write.mutex);
	printf("%s%zu %s\n", prefix, philo_current_time(philo), suffix);
	pthread_mutex_unlock(&info->write.mutex);
}
