/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:30:16 by rluari            #+#    #+#             */
/*   Updated: 2024/03/05 19:46:01 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"
#include <stdbool.h>

int	ft_get_num_of_zeros(char **map, int height, int *first_x, int *first_y)
{
	int	i;
	int	j;
	int	zeros;

	i = -1;
	zeros = 0;
	while (++i < height)
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
			{
				if (*first_x == -1)
				{
					*first_x = j;
					*first_y = i;
				}
				zeros++;
			}
			j++;
		}
	}
	return (zeros);
}

bool	ft_check_4_dirs(t_parse_map *map_data, t_parser_helper h)
{
	int	orig_x;
	int	orig_y;

	orig_x = h.x;
	orig_y = h.y;
	if (ft_is_player_char(map_data->map[h.y][h.x]))
	{
		if (*(h.found_player) == true)
			return (ft_putstr_fd("Error\nMultiple players on map\n", 2), 1);
		map_data->direction = map_data->map[h.y][h.x];
		map_data->playerinfo.x = (double)h.x + 0.5;
		map_data->playerinfo.y = (double)h.y + 0.5;
		*(h.found_player) = true;
	}
	if (check_north(map_data->map, h))
		return (1);
	if (check_south(map_data->map, h))
		return (1);
	if (check_west(map_data->map, h))
		return (1);
	if (check_east(map_data->map, h))
		return (1);
	return (0);
}

int	ft_is_walkable(t_parse_map *map_data, t_parser_helper h)
{
	h.y = 0;
	while (h.y < h.rows - 1)
	{
		h.x = 0;
		h.cols = ft_strlen(map_data->map[h.y]);
		while (h.x < h.cols - 1)
		{
			if (map_data->map[h.y][h.x] == '0'
				|| ft_is_player_char(map_data->map[h.y][h.x]))
			{
				*(h.found_zeros) += 1;
				if (ft_check_4_dirs(map_data, h))
					return (-1);
			}
			else if (map_data->map[h.y][h.x] != '1'
				&& map_data->map[h.y][h.x] != ' ')
				return (ft_putstr_fd("Error\nInvalid map character\n", 2), -1);
			h.x++;
		}
		h.y++;
	}
	return (1);
}

_Bool	init_parser_helper(t_parser_helper *h, int height)
{
	h->rows = height;
	h->cols = 0;
	h->all_zeros = 0;
	h->x = -1;
	h->y = -1;
	h->found_zeros = malloc(sizeof(int));
	h->found_player = malloc(sizeof(_Bool));
	if (!h->found_zeros || !h->found_player)
	{
		ft_mallfail();
		free(h->found_zeros);
		free(h->found_player);
		return (1);
	}
	*(h->found_player) = false;
	*(h->found_zeros) = 0;
	return (0);
}

_Bool	ft_map_is_valid(t_parse_map *map_data)
{
	t_parser_helper	h;

	if (init_parser_helper(&h, map_data->map_height))
		return (1);
	if (h.rows > 90)
		ft_putstr_fd("Big map, please wait\n", 1);
	if (h.rows > 400)
		return (ft_putstr_fd("Error\nMap too big\n", 2), 1);
	h.all_zeros = ft_get_num_of_zeros(map_data->map, h.rows,
			&(h.x), &(h.y));
	if (h.all_zeros == 0)
		return (ft_putstr_fd("Error\nNo floor (0) on map\n", 2),
			free(h.found_zeros), free(h.found_player), 1);
	h.rows = map_data->map_height;
	h.cols = ft_strlen(map_data->map[h.y]);
	if (ft_is_walkable(map_data, h) == -1)
		return (free(h.found_zeros), free(h.found_player), 1);
	if (*h.found_player == false)
		return (ft_putstr_fd("Error\nNo player found\n", 2),
			free(h.found_zeros), free(h.found_player), 1);
	free(h.found_zeros);
	free(h.found_player);
	return (0);
}
