/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:04:38 by aleger            #+#    #+#             */
/*   Updated: 2021/12/19 18:59:26 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_malloc_str(char *src, char sep)
{
	int		i;
	int		size;
	char	*dest;

	size = 0;
	while (src[size] && src[size] != sep)
		size++;
	dest = malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != sep)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_nb_str(char *s, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == sep)
			i++;
		while (s[i] && s[i] != sep)
		{
			count++;
			while (s[i] && s[i] != sep)
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		size;
	int		i;

	size = ft_nb_str((char *)s, c);
	split = (char **)malloc(sizeof(char *) * (size + 1));
	if (!split || !s)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			split[i] = ft_malloc_str((char *)s, c);
			if (!(split[i]))
				return (NULL);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	split[i] = 0;
	return (split);
}
