/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:47:50 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/03/02 09:17:41 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	s_long	game;

	if (check_arguments(argc, argv) == 0) // verifico se os 
		return (0);
	if (check_maps (argv, &game) == 0)
	{
		free_matrix_map(&game);
		return (0);
	}
	game.steps = 0;
	game.end_game = 0;
	game_work(&game);
	return (0);
}
