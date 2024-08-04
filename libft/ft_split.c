/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felix <felix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:18:45 by fwechsle          #+#    #+#             */
/*   Updated: 2024/02/18 21:52:45 by felix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c && *s != 0)
			s++;
		if (*s == 0)
			return (count);
		count++;
		while (*s != c && *s != 0)
			s++;
	}
	return (count);
}

static int	splitlen(char const *s, char c)
{
	int	count;

	count = 0;
	while (s[count] && s[count] != c)
		count++;
	return (count);
}

static const char	*str_cpy(char const *s, char c, char **dest, int i)
{
	int	j;

	j = 0;
	while (*s && *s != c)
	{
		dest[i][j] = *s;
		j++;
		s++;
	}
	dest[i][j] = 0;
	return (s);
}

static char	**inner_alloc(char const *s, char **dest, char c, int *i)
{
	while (*s)
	{
		dest[*i] = (char *)malloc((splitlen(s, c) + 1) * sizeof(char));
		if (dest[*i] == 0)
		{
			while (*i >= 0)
			{
				free(dest[*i]);
				*i -= 1;
			}
			free(dest);
			return (0);
		}
		s = str_cpy(s, c, dest, *i);
		while (*s != 0 && *s == c)
			s++;
		*i += 1;
	}
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;

	i = 0;
	if (s == 0)
		return (0);
	while (*s != 0 && *s == c)
		s++;
	dest = (char **)malloc((count(s, c) + 1) * sizeof(char *));
	if (dest == 0)
		return (0);
	dest = inner_alloc(s, dest, c, &i);
	if (dest == 0)
		return (0);
	dest[i] = NULL;
	return (dest);
}
