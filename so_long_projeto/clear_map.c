/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:47:38 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/03/01 10:57:10 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrix_map(s_long *game)
{
	int	i;

	i = 0;
	if (game->map.map == NULL)
		return ;
	while (game->map.map[i] && game->map.b_map[i])
	{
		free(game->map.map[i]);
		free(game->map.b_map[i]);
		i++;
	}
	free(game->map.map);
	free(game->map.b_map);
}
