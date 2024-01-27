/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   failure.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:16:33 by fvaliyak          #+#    #+#             */
/*   Updated: 2024/01/26 18:17:18 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_failure(int errorcode)
{
	if (errorcode == 1)
		printf("Please check the number of arguments\n");
	else if (errorcode == 2)
		printf("Please check if the arguments are valid\n");
	else if (errorcode == 3)
		printf("Please check the number of philosophers\n");
	else if (errorcode == 4)
		printf("Please check the number of meals\n");
	else if (errorcode == 8)
		printf("malloc failed\n");
	else if (errorcode == 9)
		printf("Invalid Number\n");
	else if (errorcode == 10)
		printf("1 philo means 1 fork...2 forks needed to eat\n");
	exit(errorcode);
}

void	failure_and_free(int errorcode, t_input *input)
{
	if (errorcode == 5)
	{
		printf("Mutex initialization failed\n");
	}
	else if (errorcode == 6)
	{
		free(input->forks);
		printf("Thread creation failed\n");
	}
	else if (errorcode == 7)
	{
		free(input->forks);
		free(input->all_philos);
		printf("Thread join failed\n");
	}
	exit(errorcode);
}
