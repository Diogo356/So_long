/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:47:41 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/03/06 15:21:36 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	open_images(t_long *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game->image.collect.img = mlx_xpm_file_to_image(game->pt_mlx.mlx, \
	"./imgs/collect.xpm", &x, &y);
	game->image.player.img = mlx_xpm_file_to_image(game->pt_mlx.mlx, \
	"./imgs/player.xpm", &x, &y);
	game->image.empty.img = mlx_xpm_file_to_image(game->pt_mlx.mlx, \
	"./imgs/empty.xpm", &x, &y);
	game->image.wall.img = mlx_xpm_file_to_image(game->pt_mlx.mlx, \
	"./imgs/wall.xpm", &x, &y);
	game->image.exit.img = mlx_xpm_file_to_image(game->pt_mlx.mlx, \
	"./imgs/exit.xpm", &x, &y);
	if (game->image.collect.img == NULL || game->image.player.img == NULL || \
	game->image.empty.img == NULL || game->image.wall.img == NULL || \
	game->image.exit.img == NULL )
		destroyer_window(game);
	return (1);
}

static	int	recipe_key(int keycode, t_long *game)
{
	int	line;
	int	col;

	line = game->map.position_pl.x;
	col = game->map.position_pl.y;
	if (keycode == ESC)
		destroyer_window(game);
	if (keycode == W || keycode == AW_UP)
		line--;
	if (keycode == S || keycode == AW_DN)
		line++;
	if (keycode == A || keycode == AW_L)
		col--;
	if (keycode == D || keycode == AW_R)
		col++;
	if (!game->end_game)
		move_player(game, keycode, col, line);
	return (1);
}

static void	put_one_image(s_long *game, int line, int col)
{
	if (game->map.map[line] && game->map.map[line][col] == '1')
		mlx_put_image_to_window(game->pt_mlx.mlx, game->pt_mlx.mlx_window, \
		game->image.wall.img, IMG_SIZE * col, IMG_SIZE * line);
	else if (game->map.map[line] && game->map.map[line][col] == '0')
		mlx_put_image_to_window(game->pt_mlx.mlx, game->pt_mlx.mlx_window, \
		game->image.empty.img, IMG_SIZE * col, IMG_SIZE * line);
	else if (game->map.map[line] && game->map.map[line][col] == 'P')
		mlx_put_image_to_window(game->pt_mlx.mlx, game->pt_mlx.mlx_window, \
		game->image.player.img, IMG_SIZE * col, IMG_SIZE * line);
	else if (game->map.map[line] && game->map.map[line][col] == 'C')
		mlx_put_image_to_window(game->pt_mlx.mlx, game->pt_mlx.mlx_window, \
		game->image.collect.img, IMG_SIZE * col, IMG_SIZE * line);
	else if (game->map.map[line] && game->map.map[line][col] == 'E')
		mlx_put_image_to_window(game->pt_mlx.mlx, game->pt_mlx.mlx_window, \
		game->image.exit.img, IMG_SIZE * col, IMG_SIZE * line);
}

static int	game_draw(s_long *game)
{
	int	line;
	int	col;

	line = 0;
	while (line <= game->map.line)
	{
		col = 0;
		while (col <= game->map.col)
		{
			put_one_image(game, line, col);
			col++;
		}
		line++;
	}
	if (game->end_game)
		mlx_string_put(game->pt_mlx.mlx, game->pt_mlx.mlx_window, \
		game->w_width / 2 - 25, game->w_heigth / 2, 0x000000, "You Win!!!");
	return (1);
}

void	game_work(s_long *game)
{
	int	check_win;

	check_win = window(game);
	if (check_win)
	{
		open_images(game);
		mlx_hook(game->pt_mlx.mlx_window, KEYPRESS, 1L << 0, &recipe_key, game);
		mlx_hook(game->pt_mlx.mlx_window, ON_DESTROY, 1L << 2, \
		&destroyer_window, game);
		mlx_loop_hook(game->pt_mlx.mlx, &game_draw, game);
		mlx_loop(game->pt_mlx.mlx);
	}
	write(1, "Error\nXlaunch not found\n", 24);
}
