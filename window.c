/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:48:16 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/03/01 11:01:50 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	window(s_long *game)
{
	game->w_width = IMG_SIZE * (game->map.col + 1);
	game->w_heigth = IMG_SIZE * (game->map.line + 1);
	game->pt_mlx.mlx = mlx_init();
	if (game->pt_mlx.mlx == NULL)
	{
		free_matrix_map(game);
		return (0);
	}
	game->pt_mlx.mlx_window = mlx_new_window(game->pt_mlx.mlx, game->w_width, \
	game->w_heigth, "So_long - dbelarmi");
	if (game->pt_mlx.mlx_window == NULL )
		return (0);
	return (1);
}

int	destroyer_window(s_long *game)
{
	free_matrix_map(game);
	if (!game->pt_mlx.mlx)
		exit (0);
	mlx_clear_window(game->pt_mlx.mlx, game->pt_mlx.mlx_window);
	mlx_loop_end(game->pt_mlx.mlx);
	if (game->image.collect.img != NULL)
		mlx_destroy_image(game->pt_mlx.mlx, game->image.collect.img);
	if (game->image.empty.img != NULL)
		mlx_destroy_image(game->pt_mlx.mlx, game->image.empty.img);
	if (game->image.player.img != NULL)
		mlx_destroy_image(game->pt_mlx.mlx, game->image.player.img);
	if (game->image.wall.img != NULL)
		mlx_destroy_image(game->pt_mlx.mlx, game->image.wall.img);
	if (game->image.exit.img != NULL)
		mlx_destroy_image(game->pt_mlx.mlx, game->image.exit.img);
	mlx_destroy_window(game->pt_mlx.mlx, game->pt_mlx.mlx_window);
	mlx_destroy_display(game->pt_mlx.mlx);
	free(game->pt_mlx.mlx);
	exit (0);
	return (0);
}
