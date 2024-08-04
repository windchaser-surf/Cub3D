/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:27:04 by fwechsle          #+#    #+#             */
/*   Updated: 2023/09/11 11:56:38 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	char	*buffer;

	buffer = (char *)malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (!buffer)
		return (0);
	dest = buffer;
	while (*s)
	{
		*buffer = *s;
		s++;
		buffer++;
	}
	*buffer = 0;
	return (dest);
}
