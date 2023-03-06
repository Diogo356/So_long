/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:41:07 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/02/28 10:51:22 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	char	*str;

	str = (char *)src;
	if (size == 0)
		return (ft_strlen(str));
	i = 0;
	while (str[i] && i < size - 1)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(str));
}
