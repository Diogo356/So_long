/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:40:32 by dbelarmi          #+#    #+#             */
/*   Updated: 2022/09/29 18:10:07 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_count_word(char const *s, char c)
{
	int		count;
	size_t	i;
	int		findword;

	findword = 0;
	count = 0;
	i = 0;
	while (s[i] && s[i] != '\0')
	{
		if (s[i] != c && findword == 0)
		{
			findword = 1;
			count++;
		}
		else if (s[i] == c && findword == 1)
			findword = 0;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t		size;
	size_t		n;
	char		**new_str;

	size = 0;
	n = 0;
	new_str = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!new_str || !s)
		return (NULL);
	while (*s)
	{
		if (*s != c)
			size++;
		if (*s == c && size > 0)
		{
			new_str[n] = ft_substr((s - size), 0, size);
			n++;
			size = 0;
		}
		s++;
	}
	if (size > 0)
			new_str[n++] = ft_substr((s - size), 0, size);
	new_str[n] = NULL;
	return (new_str);
}
