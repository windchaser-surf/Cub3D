/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:35:33 by fwechsle          #+#    #+#             */
/*   Updated: 2023/09/12 19:07:14 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char src1, char const *set)
{
	while (*set)
	{
		if (*set == src1)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	end;
	unsigned int	start;
	char			*dest;

	start = 0;
	if (s1 == 0 || set == 0)
		return (0);
	while (s1[start] != 0 && (is_in_set(s1[start], set)))
		start++;
	end = ft_strlen(s1);
	while (start < end && (is_in_set(s1[end - 1], set)))
		end--;
	dest = (char *)malloc((end - start + 1) * sizeof(char));
	if (dest == 0)
		return (0);
	ft_strlcpy(dest, s1 + start, end - start + 1);
	return (dest);
}
