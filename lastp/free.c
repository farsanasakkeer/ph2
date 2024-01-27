/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:22:17 by fvaliyak          #+#    #+#             */
/*   Updated: 2024/01/26 18:15:04 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_input *input)
{
	free(input->thread_ids);
	free(input->all_philos);
	free(input->forks);
}

void	unlock_and_destroy_mutex(t_input *input)
{
	int	philo_nbr;

	philo_nbr = input->philo_nbr;
	while (philo_nbr--)
	{
		pthread_mutex_unlock(&input->forks[philo_nbr]);
		pthread_mutex_destroy(&input->forks[philo_nbr]);
	}
	pthread_mutex_unlock(&(*input).lock_print);
	pthread_mutex_destroy(&(*input).lock_print);
}

void	end_threads(t_input *input)
{
	int	philo_nbr;

	philo_nbr = input->philo_nbr;
	if (philo_nbr == 1)
		pthread_mutex_unlock(&input->forks[0]);
	while (philo_nbr)
	{
		philo_nbr--;
		pthread_join(input->thread_ids[philo_nbr], NULL);
	}
}
