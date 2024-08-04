/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_utils5.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:33:21 by rluari            #+#    #+#             */
/*   Updated: 2024/03/05 19:33:32 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"

bool	check_north(char **map, t_parser_helper h)
{
	int	orig_y;

	orig_y = h.y;
	while (--h.y >= 0)
	{
		if ((int)ft_strlen(map[h.y]) < h.x)
			return (ft_putstr_fd("Error\nMap not properly walled\n", 2), 1);
		if (map[h.y][h.x] == '1')
			break ;
		if (map[h.y][h.x] == ' ')
			return (ft_putstr_fd("Error\nMap not properly walled\n", 2), 1);
	}
	if (h.y < 0)
		return (ft_putstr_fd("Error\nMap not properly walled\n", 2), 1);
	h.y = orig_y;
	return (0);
}

bool	check_south(char **map, t_parser_helper h)
{
	int	orig_y;

	orig_y = h.y;
	while (++h.y < h.rows)
	{
		if ((int)ft_strlen(map[h.y]) < h.x)
			return (ft_putstr_fd("Error\nMap not properly walled\n", 2), 1);
		if (map[h.y][h.x] == '1')
			break ;
		if (map[h.y][h.x] == ' ')
			return (ft_putstr_fd("Error\nMap not properly walled\n", 2), 1);
	}
	if (h.y == h.rows)
		return (ft_putstr_fd("Error\nMap not properly walled\n", 2), 1);
	h.y = orig_y;
	return (0);
}

bool	check_east(char **map, t_parser_helper h)
{
	int	orig_x;

	orig_x = h.x;
	while (++h.x < h.cols)
	{
		if (map[h.y][h.x] == '1')
			break ;
		if (map[h.y][h.x] == ' ')
			return (ft_putstr_fd("Error\nMap not properly walled\n", 2), 1);
	}
	if (h.x == h.cols)
		return (ft_putstr_fd("Error\nMap not properly walled\n", 2), 1);
	h.x = orig_x;
	return (0);
}

bool	check_west(char **map, t_parser_helper h)
{
	int	orig_x;

	orig_x = h.x;
	while (--h.x >= 0)
	{
		if (map[h.y][h.x] == '1')
			break ;
		if (map[h.y][h.x] == ' ')
			return (ft_putstr_fd("Error\nMap not properly walled\n", 2), 1);
	}
	if (h.x < 0)
		return (ft_putstr_fd("Error\nMap not properly walled\n", 2), 1);
	h.x = orig_x;
	return (0);
}
