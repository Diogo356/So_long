/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:47:50 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/03/03 12:47:27 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	s_long	game; // declaramos o uso da struct game

	if (check_arguments(argc, argv) == 0) // se der erro na checagem dos argumentos
		return (0); //erro encontrado, para a execução aqui
	if (check_maps (argv, &game) == 0) //// se der erro na checagem do mapa
	{
		free_matrix_map(&game); //liberamos os ponteiros do mapa
		return (0); //erro encontrado, para a execução aqui
	}
	game.steps = 0;  // passos andados inicia-se zerado
	game.end_game = 0;// possibilidade de finalizar o jogo é zero (e se mantém assim até se coletar tudo e chegar na saída)
	game_work(&game); // função que faz tudo acontecer na tele.
	return (0); // fim de tudo
}
