/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:57:57 by rluari            #+#    #+#             */
/*   Updated: 2024/02/27 15:35:10 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"
#include "cub3d_parser.h"

/* void	ft_print_list(t_list *map)
{
	while (map)
	{
		ft_putstr_fd((char *)map->content, 1);
		map = map->next;
	}
} */

_Bool	ft_handle_game_vars(t_parse_map *map_data, char *str)
{
	int	err;

	err = 0;
	ft_skip_spaces(&str);
	if (*str == 'N' && *(++str) == 'O')
		err += ft_fill_struct_with_texture(&map_data->no_texture, str);
	else if (*str == 'S' && *(++str) == 'O')
		err += ft_fill_struct_with_texture(&map_data->so_texture, str);
	else if (*str == 'W' && *(++str) == 'E')
		err += ft_fill_struct_with_texture(&map_data->we_texture, str);
	else if (*str == 'E' && *(++str) == 'A')
		err += ft_fill_struct_with_texture(&map_data->ea_texture, str);
	else if (*str == 'C')
		err += ft_fill_struct_with_color(&map_data->ceiling_color, str);
	else if (*str == 'F')
		err += ft_fill_struct_with_color(&map_data->floor_color, str);
	else if (*str != '\n')
		return (ft_putstr_fd("Error\ninvalid game variable\n", 2), 1);
	if (err > 0)
		return (1);
	return (0);
}

char	**ft_make_map_into_char_arr(t_list *map, t_parse_map *map_data,
	int i, bool just_map)
{
	char	**map_arr;
	char	*str;

	map_arr = (char **)malloc((map_data->map_height + 1) * sizeof(char *));
	if (map_arr == NULL)
		return (ft_mallfail(), NULL);
	map_arr[0] = NULL;
	while (map)
	{
		str = (char *)map->content;
		if (ft_starts_with_number(str))
		{
			map_arr[i++] = ft_strdup(str);
			if (!map_arr[i - 1])
				return (free_array(map_arr), NULL);
			map_arr[i] = NULL;
		}
		else if (!just_map && ft_handle_game_vars(map_data, str))
			return (free_array(map_arr), NULL);
		map = map->next;
	}
	if (ft_missing_textures(map_data))
		return (free_array(map_arr), NULL);
	return (map_arr);
}

_Bool	ft_make_map_struct_and_check(t_list *map, t_parse_map *map_data)
{
	map_data->map_height = ft_get_map_size(map);
	if (map_data->map_height == -1)
		return (1);
	map_data->map = ft_make_map_into_char_arr(map, map_data, 0, 0);
	if (map_data->map == NULL)
		return (1);
	if (ft_map_is_valid(map_data))
		return (1);
	free_array(map_data->map);
	map_data->map = ft_make_map_into_char_arr(map, map_data, 0, 1);
	if (map_data->map == NULL)
		return (1);
	return (0);
}

void	ft_init_map_struct(t_parse_map *map_data)
{
	map_data->no_texture = NULL;
	map_data->so_texture = NULL;
	map_data->we_texture = NULL;
	map_data->ea_texture = NULL;
	map_data->map_height = 0;
	map_data->ceiling_color = -1;
	map_data->floor_color = -1;
	map_data->map = NULL;
}

_Bool	ft_parse_map(char *filename, t_parse_map *map_data, t_list *tmp)
{
	int		fd;
	char	*line;
	t_list	*map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\nCan't open file\n", 2), 1);
	map = NULL;
	ft_init_map_struct(map_data);
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_lstnew((void *)line);
		if (tmp == NULL)
			return (free_gnl_lstclear(line, fd, map), ft_mallfail(), 1);
		ft_lstadd_back(&map, tmp);
		if (ft_strchr((char *)line, '\n') == NULL)
			break ;
		line = get_next_line(fd);
		if (line == NULL)
			return (normie_errhandl(map, fd, "Last line is not map\n"), 1);
	}
	if (ft_make_map_struct_and_check(map, map_data))
		return (normie_errhandl(map, fd, NULL), free_struct(map_data), 1);
	return (close(fd), ft_lstclear(&map, free), 0);
}
