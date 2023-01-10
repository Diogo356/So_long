/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:41:07 by dbelarmi          #+#    #+#             */
/*   Updated: 2022/09/28 20:57:56 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
