/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:44:06 by fwechsle          #+#    #+#             */
/*   Updated: 2024/02/26 15:43:04 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char	*s)
{
	size_t		length;

	length = 0;
	if (s == NULL)
		return (length);
	while (*s != '\0')
	{
		s++;
		length++;
	}
	return (length);
}
