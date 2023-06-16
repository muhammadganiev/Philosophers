/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:22 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/16 19:19:35 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atol(const char *str, size_t *dst)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '+')
		i++;
	*dst = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		*dst = *dst * 10 + (str[i] - '0');
		if (*dst > __INT_MAX__)
			return (0);
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return (1);
}

size_t	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(size_t ms)
{
	size_t	end;

	end = ft_get_time() + ms;
	while (ft_get_time() < end)
		usleep(ms);
}
