/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:47:23 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/01/09 16:47:23 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char	*str;
	const char	*to_find;
	size_t		i;
	size_t		p;

	i = 0;
	str = s1;
	to_find = s2;
	if (to_find[i] == '\0')
		return ((char *)str);
	p = 0;
	while (str[i] != '\0')
	{
		p = 0;
		while (str[i + p] == to_find[p] && str[i + p] != '\0')
		{
			if (to_find[p + 1] == '\0')
				return (&((char *)str)[i]);
			p++;
		}
		i++;
	}
	return (NULL);
}
