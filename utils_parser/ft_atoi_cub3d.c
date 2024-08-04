/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_cub3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:09:43 by rluari            #+#    #+#             */
/*   Updated: 2024/02/28 15:43:38 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"

int	ft_atoi_cub3d(char *str, int sign)
{
	long	res;

	res = 0;
	if (!str)
		return (0);
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (ft_strlen(str) > 10 || sign == -1)
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		res *= 10;
		res += (int)((*str) - '0');
		str++;
	}
	ft_skip_spaces(&str);
	if ((res > INT_MAX) || (sign == -1) || (*str && *str != '\n'))
		return (-1);
	return (res);
}

//get position of a character in a string (0th, 1th...)
int	ft_strchr_cub3d(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (i + 1);
}
