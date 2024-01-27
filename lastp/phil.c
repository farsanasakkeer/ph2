/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:41:32 by fvaliyak          #+#    #+#             */
/*   Updated: 2024/01/27 18:00:04 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_args(int ac, char **av)
{
	size_t	i;

	if (ac < 5 || ac > 6)
		ft_failure(1);
	i = 1;
	while (av[i])
	{
		if ((!ft_is_digit(av[i])) || (!ft_atoi(av[i])))
			ft_failure(2);
		i++;
	}
	// if (ft_atoi(av[1]) == 1)
	// 	ft_failure(10);
}

int	main(int ac, char **av)
{
	t_input	input;

	check_args(ac, av);
	init_args(&input, ac, av);
	init_mutex(&input);
	init_philosophers(&input, 0);
	init_threads(&input);
	end_threads(&input);
	unlock_and_destroy_mutex(&input);
	ft_free(&input);
	return (0);
}
