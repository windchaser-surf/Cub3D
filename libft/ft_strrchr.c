/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:44:15 by fwechsle          #+#    #+#             */
/*   Updated: 2023/09/13 11:22:31 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*buffer;
	int		check;

	check = 0;
	buffer = (char *) s;
	if ((char)c == 0)
	{
		while (*s)
			s++;
		return ((char *) s);
	}
	while (*buffer)
	{
		if (*buffer == (unsigned char) c)
		{
			s = buffer;
			check = 1;
			buffer++;
		}
		else
			buffer++;
	}
	if (check == 0)
		return (0);
	return ((char *) s);
}
