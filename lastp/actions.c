/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:13:52 by fvaliyak          #+#    #+#             */
/*   Updated: 2024/01/26 19:55:04 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking_forks_odd_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->lock_print);
	if (philo->stop != 1)
	{
		printf("%ld philosopher %d has taken the fork\n", \
			ft_time() - philo->time_start, philo->philo_id + 1);
		printf("%ld philosopher %d has taken the fork\n", \
			ft_time() - philo->time_start, philo->philo_id + 1);
	}
	pthread_mutex_unlock(&philo->lock_print);
}

void	taking_forks(t_philo *philo)
{
	if ((philo->philo_id) % 2 == 0 && philo->philo_id + 1 != philo->philo_nbr)
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(&philo->lock_print);
		if (philo->stop != 1)
		{
			printf("%ld philosopher %d has taken the fork\n", \
				ft_time() - philo->time_start, philo->philo_id + 1);
			printf("%ld philosopher %d has taken the fork\n", \
				ft_time() - philo->time_start, philo->philo_id + 1);
		}
		pthread_mutex_unlock(&philo->lock_print);
	}
	else
		taking_forks_odd_philo(philo);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock_print);
	printf("%ld philosopher %d is eating\n", \
		ft_time() - philo->time_start, philo->philo_id + 1);
	pthread_mutex_unlock(&philo->lock_print);
	philo->total_nbr_meals += 1;
	philo->time_of_last_meal = ft_time();
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock_print);
	printf("%ld philosopher %d is sleeping\n", \
		ft_time() - philo->time_start, philo->philo_id + 1);
	pthread_mutex_unlock(&philo->lock_print);
	ft_usleep(philo->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock_print);
	printf("%ld philosopher %d is thinking\n", \
		ft_time() - philo->time_start, philo->philo_id + 1);
	pthread_mutex_unlock(&philo->lock_print);
}
