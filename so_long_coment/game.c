/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:47:41 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/03/03 12:43:57 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	open_images(s_long *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game->image.collect.img = mlx_xpm_file_to_image(game->pt_mlx.mlx, \
	"./imgs/collect.xpm", &x, &y); // uso essa função para fazer o arquivo collect.xpm virar uma imagem.
	game->image.player.img = mlx_xpm_file_to_image(game->pt_mlx.mlx, \
	"./imgs/player.xpm", &x, &y);// uso essa função para fazer o arquivo player.xpm virar uma imagem.
	game->image.empty.img = mlx_xpm_file_to_image(game->pt_mlx.mlx, \
	"./imgs/empty.xpm", &x, &y); // uso essa função para fazer o arquivo empty.xpm virar uma imagem.
	game->image.wall.img = mlx_xpm_file_to_image(game->pt_mlx.mlx, \
	"./imgs/wall.xpm", &x, &y);// uso essa função para fazer o arquivo collect.xpm virar uma imagem.
	game->image.exit.img = mlx_xpm_file_to_image(game->pt_mlx.mlx, \
	"./imgs/exit.xpm", &x, &y); // // uso essa função para fazer o arquivo exit.xpm virar uma imagem.
	if (game->image.collect.img == NULL || game->image.player.img == NULL || \
	game->image.empty.img == NULL || game->image.wall.img == NULL || \
	game->image.exit.img == NULL ) // verifica se está está tudo correto.
		destroyer_window(game); // se não estiver, eu uso essa func para fechar as janelas
	return (1); // retorna que ocorreu tudo bem.
}

static int	recipe_key(int keycode, s_long *game)
{
	int	line;
	int	col;

	line = game->map.position_pl.x;
	col = game->map.position_pl.y;
	if (keycode == ESC) // se o jogador precionar o ESC o jogo fecha
		destroyer_window(game);
	if (keycode == W || keycode == AW_UP) // move o player para cima 
		line--; 
	if (keycode == S || keycode == AW_DN) // move o player para baixo
		line++;
	if (keycode == A || keycode == AW_L) // move o player para a esquerda 
		col--; 
	if (keycode == D || keycode == AW_R) // move o player para a DIREITA
		col++; 
	if (!game->end_game) // se for igual a 0, significa que ainda não coletou tudo e a movimentação ainda é possivel, só sera 1 ao coletar todos os itens do mapa.
		move_player(game, keycode, col, line); // função que move o palyer
	return (1);
}

// posiciona cada imagem em seu lugar, de acordo com o caracter do mapa
// coloca uma imagem por vez.
static void	put_one_image(s_long *game, int line, int col)
{
	if (game->map.map[line] && game->map.map[line][col] == '1') // se a linha existir e o conteúdo da coluna for 1
		mlx_put_image_to_window(game->pt_mlx.mlx, game->pt_mlx.mlx_window, \
		game->image.wall.img, IMG_SIZE * col, IMG_SIZE * line); // a função mlx_put_image_to_window coloca a imagem da parede
	else if (game->map.map[line] && game->map.map[line][col] == '0') // se a linha existir e o conteúdo da coluna for 0
		mlx_put_image_to_window(game->pt_mlx.mlx, game->pt_mlx.mlx_window, \
		game->image.empty.img, IMG_SIZE * col, IMG_SIZE * line); // a função mlx_put_image_to_window coloca a imagem do caminho / empty
	else if (game->map.map[line] && game->map.map[line][col] == 'P')  // se a linha existir e o conteúdo da coluna for P
		mlx_put_image_to_window(game->pt_mlx.mlx, game->pt_mlx.mlx_window, \
		game->image.player.img, IMG_SIZE * col, IMG_SIZE * line); // a função mlx_put_image_to_window coloca a imagem do player
	else if (game->map.map[line] && game->map.map[line][col] == 'C') // se a linha existir e o conteúdo da coluna for C
		mlx_put_image_to_window(game->pt_mlx.mlx, game->pt_mlx.mlx_window, \
		game->image.collect.img, IMG_SIZE * col, IMG_SIZE * line);  // a função mlx_put_image_to_window coloca a imagem do coletável
	else if (game->map.map[line] && game->map.map[line][col] == 'E') // se a linha existir e o conteúdo da coluna for E
		mlx_put_image_to_window(game->pt_mlx.mlx, game->pt_mlx.mlx_window, \
		game->image.exit.img, IMG_SIZE * col, IMG_SIZE * line); // a função mlx_put_image_to_window coloca a imagem da saída
}

//função que le o mapa e coloca a imagem adequa
static int	game_draw(s_long *game)
{
	int	line;
	int	col;

	line = 0;
	while (line <= game->map.line) // enquanto ainda tiver linha para ler
	{
		col = 0;
		while (col <= game->map.col) // enquanto ainda tiver coluna na linha pra ler
		{
			put_one_image(game, line, col); // coloca-se a imagem adequada
			col++; //proxima coluna
		}
		line++; // proxima linha
	}
	if (game->end_game)  // se o game->end_game for diferente de zero, o jogador ganhou o jogo
		mlx_string_put(game->pt_mlx.mlx, game->pt_mlx.mlx_window, \
		game->w_width / 2 - 25, game->w_heigth / 2, 0x000000, "You Win!!!");// usamos essa função 'mlx_string_put' para escrever na tela
	return (1);
}

//função que abre a janela, abre as imagens, recebe os cliques das teclas(movimentação do player)
void	game_work(s_long *game)
{
	int	check_win;

	check_win = window(game);
	if (check_win)
	{
		open_images(game); // abro as imagens
		mlx_hook(game->pt_mlx.mlx_window, KEYPRESS, 1L << 0, &recipe_key, game); // clique das teclas para movimentar o personagem
		mlx_hook(game->pt_mlx.mlx_window, ON_DESTROY, 1L << 2, \
		&destroyer_window, game); // clique do ESC para fechar a janela
		mlx_loop_hook(game->pt_mlx.mlx, &game_draw, game); // desenha o jogo
		mlx_loop(game->pt_mlx.mlx); //mantém as func da mlx em loop
	}
	write(1, "Error\nXlaunch not found\n", 24); // se ele não achar o xlauch, ele retorna esse erro.
}
