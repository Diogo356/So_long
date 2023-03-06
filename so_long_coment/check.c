/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:47:34 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/03/06 14:46:32 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_arguments(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2) // verifica se a quantidade de argumentos é valido.
	{
		i = ft_strlen(argv[1]); // variavel i recebe o tamanho do nome do arquivo
		if ((argv[1][i - 4] == '.') && (argv[1][i - 3] == 'b') && \
		(argv[1][i - 2] == 'e') && (argv[1][i - 1] == 'r')) // verifica se a extensão do arquivo é .ber
			return (1);
		else //caso o contrario ele retorna erro.
		{
			write (1, "Error\nInvalid file format!\n", 28);
			return (0);
		}
	}
	write (1, "Error\nInvalid argument number!\n", 32);
	return (0);
}

static int	msg_error_itens(s_long *game)
{
	if (game->vmap.e != 1 || game->vmap.p != 1 || game->vmap.c == 0) // verifica se a quantidade de itens são validos;
	{
		if (game->vmap.e != 1) // se a saida for mair que 1
		{
			write(1, "Error\ninvalid number of exit in map\n", 37);
			return (0);
		}
		if (game->vmap.p != 1) // se o personagem é maior que 1
		{
			write(1, "Error\ninvalid number of player in map\n", 39);
			return (0);
		}
		if (game->vmap.c == 0) //se exite coletaveis no mapa.
		{
			write(1, "Error\ninvalid number of collectable on map\n", 44);
			return (0);
		}
	}
	return (1);
}

int	validate_caracters_map(s_long *game)
{
	int	l;
	int	c;

	l = 0;
	while (game->map.map[l])// enquando a linha não for nula
	{
		c = 0;
		while (game->map.map[l] && game->map.map[l][c]) // enaquanto a linha e coluna não forem nulos.
		{
			if (game->map.map[l][c] && (game->map.map[l][c] != 'P' && \
			game->map.map[l][c] != 'C' && game->map.map[l][c] != 'E' && \
			game->map.map[l][c] != '0' && game->map.map[l][c] != '1')) // se não existir algum desses caracteres no mapa, ele retorna erro. 
			{
				write(1, "Error\nCaracter invalid in map\n", 31);
				return (0);
			}
			c++;
		}
		l++;
	}
	return (1);
}

int	validate_itens_map(s_long *game)
{
	int	l;
	int	c;

	l = 0;
	while (game->map.map[l])
	{
		c = 0;
		while (game->map.map[l] && game->map.map[l][c])
		{
			if (game->map.map[l][c] && game->map.map[l][c] == 'P') // verifica quantos personagens existem no mapa
				game->vmap.p++;
			if (game->map.map[l][c] && game->map.map[l][c] == 'C') //verifica quantos coletaveis existem no mapa
				game->vmap.c++;
			if (game->map.map[l][c] && game->map.map[l][c] == 'E')// verifica quantas saidas exitem no mapa
				game->vmap.e++;
			c++;
		} >= 3
		l++;
	}
	return (msg_error_itens(game)); // retorna a mensagem de erro
}

//this function will call some functions to check some parameters of my map.
int	check_maps(char **argv, s_long *game)
{
	game->map.map = read_maps(argv);
	if (game->map.map == NULL)
	{
		write (1, "Error\nmap error\n", 16);
		return (0);
	}
	game->map.b_map = read_maps(argv);
	if (game->map.b_map == NULL)
	{
		write (1, "Error\nmap error\n", 16);
		return (0);
	}
	init_validate_map(&game->vmap); // inicializa os itens do mapa
	if (check_wall(game) == 0) // faz todas as checagens do mapa.
		return (0);
	return (1);
}
