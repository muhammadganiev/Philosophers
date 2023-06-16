/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thred_s_t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:22 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/16 19:19:22 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thsize_t_init(t_thsize_t *data, size_t value)
{
	data->value = value;
	return (pthread_mutex_init(&data->mutex, NULL));
}

void	thsize_t_set(t_thsize_t *data, size_t value)
{
	pthread_mutex_lock(&data->mutex);
	data->value = value;
	pthread_mutex_unlock(&data->mutex);
}

size_t	thsize_t_get(t_thsize_t *data)
{
	size_t	value;

	pthread_mutex_lock(&data->mutex);
	value = data->value;
	pthread_mutex_unlock(&data->mutex);
	return (value);
}

int	thsize_t_destroy(t_thsize_t *data, size_t value)
{
	data->value = value;
	return (pthread_mutex_destroy(&data->mutex));
}
