/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:40:56 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/03/01 12:19:41 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*str_dest;
	int		sd;
	int		i;

	sd = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	str_dest = (char *)malloc(sizeof(char) * (sd));
	if (str_dest == 0)
		return (NULL);
	i = 0;
	sd = 0;
	while (s1[i] != '\0')
	{
		str_dest[sd] = s1[i];
		sd++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str_dest[sd] = s2[i];
		sd++;
		i++;
	}
	free(s1);
	str_dest[sd] = '\0';
	return (str_dest);
}
