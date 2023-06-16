/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:22 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/16 19:15:24 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	*parse_arg(char **av, int size)
{
	int		i;
	size_t	*new;

	if (!size)
		return (0);
	new = malloc(sizeof(size_t) * size);
	if (!new)
		return (0);
	i = 0;
	while (i < size)
	{
		if (!ft_atol(av[i], &new[i]))
		{
			free(new);
			return (0);
		}
		i++;
	}
	return (new);
}
