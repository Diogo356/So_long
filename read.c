/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:48:02 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/01/09 16:48:02 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**make_map(char *map, int ck_line)
{
	char	**temp;

	temp = NULL;
	if (ck_line >= 3)
		temp = ft_split(map, '\n');
	free(map);
	return (temp);
}

char	**read_maps(char **argv)
{
	int		fd;
	int		ck_line;
	char	*gnl_line;
	char	*map;

	fd = open (argv[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	gnl_line = get_next_line(fd);
	map = ft_strdup("");
	ck_line = ft_strlen(gnl_line);
	while (gnl_line)
	{
		map = ft_strjoin(map, gnl_line);
		free (gnl_line);
		gnl_line = get_next_line(fd);
		if ((ck_line < 3 && gnl_line != NULL) || gnl_line == NULL )
			continue ;
		ck_line = ft_strlen(gnl_line);
	}
	close(fd);
	return (make_map(map, ck_line));
}
