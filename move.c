/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:47:56 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/03/03 11:08:53 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_be_ok(s_long *game, int keycode, int line, int col)
{
	if (game->map.map[line][col] == '1') // verifica se para onde o player quer ir, é parede
		return (0);
	if (game->map.map[line][col] == 'E' && game->vmap.c == 0) // se for saída e tiver coletado tudo
		game->end_game = 1; // a permissão passa a ser 1
	if (game->map.map[line][col] == 'E') // se for a saída
		return (0); ;//n permite andar, optei pelo personagem não passar sobre o desenho da saída e o jogo finaliza com ele posicionado ao lado da saída
	if (game->end_game) // com a permissão dada
		return (0);//não pode mais mexer
	if (keycode == W || keycode == S || keycode == A || keycode == D || \
	keycode == AW_UP || keycode == AW_DN || keycode == AW_L || \
	keycode == AW_R)  // se for alguma dessas teclas e o movimento não tiver impedido
		return (1); // movimentação autorizada
	return (0); // senão, movimentação impedida
}

void	move_player(s_long *game, int keycode, int col, int line)
{
	char	*temp;
	int		px;
	int		py;
	int		move_ok;

	px = game->map.position_pl.x; // recebe a posição do player
	py = game->map.position_pl.y; // recebe a posição do player
	move_ok = move_be_ok(game, keycode, line, col); // função que valida o movimento do player
	if (move_ok > 0) // se a movimentação for permitida.
	{
		if (game->map.map[line][col] == 'C') // se a posição que o usuarioi estiver for coletavel
			game->vmap.c--; //vou diminuindo a quantidade de coletaveis
		game->map.map[px][py] = '0'; // a posição atual vira caminha
		game->map.map[line][col] = 'P'; // a posição em que se está indo vira o player P
		game->map.position_pl.y = col; // a posição do player é atualizada
		game->map.position_pl.x = line; // a posição do player é atualizada
		game->steps++; // conta-se mais um passo
		temp = ft_itoa(game->steps); // o int game->steps é transformado em string
		ft_putstr("Steps move: "); // imprimo a mensagem
		ft_putstr(temp); // imprimo o numero de passos 
		ft_putstr("\n"); // quebro a linha
		free(temp); // libero o ponteiro da string temporaria
	}
}
