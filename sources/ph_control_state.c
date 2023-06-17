/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_control_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:22 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/17 14:32:32 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_pstate_valid(t_pinfo *pinfo, t_philo *philo)
{
	if (philo_current_time(philo) - philo->last_eatt >= pinfo->time_to_die)
	{
		philo->state = DIED;
		return (0);
	}
	return (1);
}

int	pstate_transition(t_pinfo *pinfo, t_philo *philo, t_state next_state)
{
	philo->state = next_state;
	return (is_pstate_valid(pinfo, philo));
}
