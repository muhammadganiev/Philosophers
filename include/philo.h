/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:28 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/11 18:49:23 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h> //gettimeofday()
# include <stdlib.h>
# include <unistd.h>

# define WHITE   "\033[37m"      /* White */
# define RED  "\x1B[31m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define RESET   "\033[0m"
# define BLUE    "\033[34m"      /* Blue */
# define CYAN    "\033[36m"      /* Cyan */
# define MAGENTA "\033[35m"      /* Magenta */

typedef struct philo
{
	int				id;
	int				time_to_eat;
	int				time_to_sleap;
	int				time_to_die;
	int				how_many_eat;
	int				left;
	int				right;
	long long		time_start;
	long long		last_eat;
	struct table	*arg;
}	t_philo;

typedef struct table
{
	int				count_philo;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				count_lanch;
	int				flg_of_dead;
	long long		time_start;
	pthread_t		*thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t	eat;
	pthread_mutex_t	dead;
	pthread_mutex_t	six;
	pthread_mutex_t	print;
	t_philo			*philo;
}	t_table;

long long	ft_atoi(const char *str);
t_table		*init(int ac, char **av);
int			init_time(t_table *all);
int			ft_free(t_table	*all);
int			init_phiolo(t_table *table);
int			parse(int ac, char **av);
long long	get_timestamp(void);
void		print_philo(t_table *table, t_philo *philo, char *str);
void		thinking(t_table *table, t_philo *philo);
void		sleepeng(t_table *table, t_philo *philo);
int			eating(t_table *tb, t_philo *philo);
void		ft_usleep(int time_ms);
void		ft_destroy_mutex(t_table *all);
int			ft_free(t_table *all);
void		*hell(t_table *table, t_philo *philo);
void		*check_dead(t_table *table, t_philo *pholo);
void		hi_norminnate(t_table *tb, t_philo *philo);

#endif