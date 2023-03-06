/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:48:11 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/03/02 22:06:53 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_position(s_long *game)
{
	int	l;
	int	c;

	l = 0;
	while (game->map.map[l]) // verifica se a linha é valida
	{
		c = 0;
		while (game->map.map[l] && game->map.map[l][c]) // vai procurar dentro do mapa a posição do personagem.
		{
			if (game->map.map[l][c] && game->map.map[l][c] == 'P') //se encontrar a posição do personagem
			{
				game->map.position_pl.x = l; // eu passo a posição da linha para a position_pl.x
				game->map.position_pl.y = c; // eu passo a posição da coluna para a position_pl.y
				return ; //saio da função porque já encontrei a posição do player;
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
	player_position(game); // função para encontrar a posição do player.
	flood_fill(game, game->map.position_pl.x, game->map.position_pl.y);
	if (game->vmap.c == 0 && game->vmap.e == 0) // se todos os itens forão coletados
	{
		game->vmap.c = game->collect; // o collect recebe o valor dos coletaveis 
		game->vmap.e = game->exit; // o exit recebe o valor da saida
		return (1); // e retrona positivo;
	}
	write(1, "Error\ninvalid path\n", 20); // se algo der errado, ele retorna erro;
	return (0);
}
