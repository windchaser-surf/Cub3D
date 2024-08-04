/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:15:26 by fwechsle          #+#    #+#             */
/*   Updated: 2023/09/12 19:03:38 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*little == 0)
		return ((char *) big);
	while (len > i && big[i])
	{
		while (big[i + j] == little[j] && big[i + j] != 0
			&& (size_t) i + j < len)
			j++;
		if (little[j] == 0)
			return ((char *) big + i);
		else
			j = 0;
		i++;
	}
	return (0);
}
