/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:22 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/17 14:38:56 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	*parsing_arg(char **av, int size)
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
		if (!character_to_long(av[i], &new[i]))
		{
			free(new);
			return (0);
		}
		i++;
	}
	return (new);
}
