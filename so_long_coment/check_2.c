/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:47:30 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/03/02 22:07:16 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	map_square(s_long *game)
{
	int	l;

	l = 0;
	game->map.col = ft_strlen(game->map.map[0]); //pega o tamanho da primeira linha contida na primeira posição do meu map.
	while (game->map.map[l] && (game->map.col == ft_strlen(game->map.map[l]))) //verifica se a linha não é nula, e se o tamnho da linha é igual as outras. 
		l++;
	if (game->map.map[l] == NULL) // verifica se a ultima linha é nula
	{
		game->map.col -= 1; //para ajustar o indice da coluna em 0
		game->map.line = l - 1; // para ajustar o indice da linha em 0
		return (1);
	}
	write(1, "Error\nmap is not square\n", 25); // se não entrar no loop, ele retorna que o mapa não é quarado.
	return (0);
}

static int	check_vertical(s_long *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map.map[y] && game->map.map[y][x] == '1') // faço a contagem de qual o tamanho da parede da primeira coluna
		y++;
	if (y - 1 != game->map.line) // verifico se o tamanho está correto.
	{
		write(1, "Error\nvertical left wall map is broken\n", 40);
		return (0);
	}
	x = game->map.col; // o x vai receber a posição da ultima coluna.
	y = 0; // zero o y.
	while (game->map.map[y] && game->map.map[y][x] == '1') // faço a contagem do tamanho da ultima parede
		y++;
	if (y - 1 != game->map.line) //verifico se o tamnho esta correto.
	{
		write(1, "Error\nvertical rigth wall map is broken\n", 41);
		return (0);
	}
	return (1);// retorna 1 para informar que está tudo correto.
}

static int	check_horizontal(s_long *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map.map[y] && game->map.map[y][x] == '1') // faço a contagem da primeira linha.
		x++;
	if (x - 1 != game->map.col) // verifco se o tamnho está correto.
	{
		write(1, "Error\nhorizontal top wall map is broken\n", 41);
		return (0);
	}
	x = 0; // zero o x.
	y = game->map.line; // o y vai receber a posição da ultima linha.
	while (game->map.map[y] && game->map.map[y][x] == '1') // faço a contagem da ultima linha.
		x++;
	if (x - 1 != game->map.col) // verifico se o tamnho está correto.
	{
		write(1, "Error\nhorizontal bottom wall map is broken\n", 44);
		return (0);
	}
	return (1); // retorna 1 para informar que está tudo correto.
}

int	check_wall(s_long *game)
{
	if (validate_caracters_map(game) == 0) // verifica se os caracteres no mapa são validos e se existem.
		return (0);
	if (validate_itens_map(game) == 0) // valida os itens do mapa
		return (0);
	if (map_square(game) == 0) //valida se o mapa é quadrado
		return (0);
	if (check_vertical(game) == 0) // verifico se na primeira coluna e se na ultima coluna do mapa tem paredes.
		return (0);
	if (check_horizontal(game) == 0) // verifico se na parte superior e inferior do mapa tem pardes
		return (0);
	if (valid_way(game) == 0) // valida o caminho do mapa;
		return (0);
	return (1);
}
