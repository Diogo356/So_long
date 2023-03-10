/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:47:56 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/03/06 13:53:00 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_be_ok(s_long *game, int keycode, int line, int col)
{
	if (game->map.map[line][col] == '1')
		return (0);
	if (game->map.map[line][col] == 'E' && game->vmap.c == 0)
		game->end_game = 1;
	if (game->map.map[line][col] == 'E')
		return (0);
	if (game->end_game)
		return (0);
	if (keycode == W || keycode == S || keycode == A || keycode == D || \
	keycode == AW_UP || keycode == AW_DN || keycode == AW_L || \
	keycode == AW_R)
		return (1);
	return (0);
}

void	move_player(s_long *game, int keycode, int col, int line)
{
	char	*temp;
	int		px;
	int		py;
	int		move_ok;

	px = game->map.position_pl.x;
	py = game->map.position_pl.y;
	move_ok = move_be_ok(game, keycode, line, col);
	if (move_ok > 0)
	{
		if (game->map.map[line][col] == 'C')
			game->vmap.c--;
		game->map.map[px][py] = '0';
		game->map.map[line][col] = 'P';
		game->map.position_pl.y = col;
		game->map.position_pl.x = line;
		game->steps++;
		temp = ft_itoa(game->steps);
		ft_putstr("Steps move: ");
		ft_putstr(temp);
		ft_putstr("\n");
		free(temp);
	}
}
