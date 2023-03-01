/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:47:46 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/03/01 17:17:08 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_map *map)
{
	map->position_pl.x = -1;
	map->position_pl.y = -1;
	map->map = NULL;
	map->line = 0;
	map->col = 0;
	map->item = 0;
}

void	init_validate_map(t_valmp *vmap)
{
	vmap->c = 0;
	vmap->p = 0;
	vmap->e = 0;
}
