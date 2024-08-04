/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:58:02 by fwechsle          #+#    #+#             */
/*   Updated: 2023/09/12 19:05:21 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*src;
	size_t	result;

	result = nmemb * size;
	if (nmemb != 0 && size != 0 && (result / nmemb != size))
		return (NULL);
	src = malloc(result);
	if (!src)
		return (NULL);
	ft_bzero(src, result);
	return (src);
}
