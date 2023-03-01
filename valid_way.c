/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:48:11 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/03/01 17:17:57 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_position(s_long *game)
{
	int	l;
	int	c;

	l = 0;
	c = 0;
	while (game->map.map[l])
	{
		c = 0;
		while (game->map.map[l] && game->map.map[l][c])
		{
			if (game->map.map[l][c] && game->map.map[l][c] == 'P')
			{
				game->map.position_pl.x = l;
				game->map.position_pl.y = c;
				return ;
			}
			c++;
		}
		l++;
	}
}

static void	flood_fill(s_long *game, int px, int py)
{
	if (!game->map.b_map || !game->map.b_map[px])
		return ;
	if (game->map.b_map[px][py] == '1' || game->map.b_map[px][py] == 'W')
		return ;
	if (game->map.b_map[px][py] == 'C')
		game->vmap.c--;
	if (game->map.b_map[px][py] == 'E')
		game->vmap.e--;
	game->map.b_map[px][py] = 'W';
	flood_fill(game, px + 1, py);
	flood_fill(game, px - 1, py);
	flood_fill(game, px, py + 1);
	flood_fill(game, px, py - 1);
	return ;
}

int	valid_way(s_long *game)
{
	game->collect = game->vmap.c;
	game->exit = game->vmap.e;
	player_position(game);
	flood_fill(game, game->map.position_pl.x, game->map.position_pl.y);
	if (game->vmap.c == 0 && game->vmap.e == 0)
	{
		game->vmap.c = game->collect;
		game->vmap.e = game->exit;
		return (1);
	}
	write(1, "Error\ninvalid path\n", 20);
	return (0);
}
