/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:47:30 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/03/04 14:02:35 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	map_square(s_long *game)
{
	int	l;

	l = 0;
	game->map.col = ft_strlen(game->map.map[0]);
	while (game->map.map[l] && (game->map.col == ft_strlen(game->map.map[l]))) 
		l++;
	if (game->map.map[l] == NULL)
	{
		game->map.col -= 1;
		game->map.line = l - 1;
		return (1);
	}
	write(1, "Error\nmap is not square\n", 25);
	return (0);
}

static int	check_vertical(s_long *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map.map[y] && game->map.map[y][x] == '1')
		y++;
	if (y - 1 != game->map.line)
	{
		write(1, "Error\nvertical left wall map is broken\n", 40);
		return (0);
	}
	x = game->map.col;
	y = 0;
	while (game->map.map[y] && game->map.map[y][x] == '1')
		y++;
	if (y - 1 != game->map.line)
	{
		write(1, "Error\nvertical rigth wall map is broken\n", 41);
		return (0);
	}
	return (1);
}

static int	check_horizontal(s_long *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map.map[y] && game->map.map[y][x] == '1')
		x++;
	if (x - 1 != game->map.col)
	{
		write(1, "Error\nhorizontal top wall map is broken\n", 41);
		return (0);
	}
	x = 0;
	y = game->map.line;
	while (game->map.map[y] && game->map.map[y][x] == '1')
		x++;
	if (x - 1 != game->map.col)
	{
		write(1, "Error\nhorizontal bottom wall map is broken\n", 44);
		return (0);
	}
	return (1);
}

int	check_wall(s_long *game)
{
	if (validate_caracters_map(game) == 0)
		return (0);
	if (validate_itens_map(game) == 0)
		return (0);
	if (map_square(game) == 0)
		return (0);
	if (check_vertical(game) == 0)
		return (0);
	if (check_horizontal(game) == 0)
	if (valid_way(game) == 0)
		return (0);
	return (1);
}
