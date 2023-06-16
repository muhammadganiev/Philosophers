/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_exit_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:22 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/16 19:16:55 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pstate_died(t_pinfo *pinfo, t_philo *philo)
{
	log_philo(pinfo, philo, RED, "died");
	thsize_t_set(&pinfo->quit, 1);
	return (1);
}

int	pstate_finished(t_pinfo *pinfo, t_philo *philo)
{
	thsize_t_set(&pinfo->quit, 1);
	log_philo_woid(pinfo, philo, ORANGE, "everyone has finished their meals");
	return (1);
}
