/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_utils3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:31:16 by rluari            #+#    #+#             */
/*   Updated: 2024/02/27 21:33:39 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"

void	free_gnl_lstclear(char *line, int fd, t_list *map)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	ft_lstclear(&map, free);
	close(fd);
}

void	normie_errhandl(t_list	*map, int fd, char *str)
{
	ft_lstclear(&map, free);
	close(fd);
	if (str)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(str, 2);
	}
}

void	ft_closer(int *files, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (files[i] > 0)
		{
			close(files[i]);
			files[i] = 0;
		}
		else
			i++;
	}
}

bool	ft_missing_textures(t_parse_map *map_d)
{
	int	files[4];

	if (map_d->no_texture == NULL || map_d->so_texture == NULL
		|| map_d->we_texture == NULL || map_d->ea_texture == NULL)
		return (ft_putstr_fd("Error\nMissing texture\n", 2), 1);
	files[0] = open(map_d->no_texture, O_RDONLY);
	if (files[0] == -1)
		return (ft_putstr_fd("Error\nTexture file not found\n", 2),
			ft_closer(files, 0), 1);
	files[1] = open(map_d->so_texture, O_RDONLY);
	if (files[1] == -1)
		return (ft_putstr_fd("Error\nTexture file not found\n", 2),
			ft_closer(files, 1), 1);
	files[2] = open(map_d->we_texture, O_RDONLY);
	if (files[2] == -1)
		return (ft_putstr_fd("Error\nTexture file not found\n", 2),
			ft_closer(files, 2), 1);
	files[3] = open(map_d->ea_texture, O_RDONLY);
	if (files[3] == -1)
		return (ft_putstr_fd("Error\nTexture file not found\n", 2),
			ft_closer(files, 3), 1);
	ft_closer(files, 4);
	return (0);
}

void	free_struct(t_parse_map *map_data)
{
	if (map_data->no_texture)
		free(map_data->no_texture);
	if (map_data->so_texture)
		free(map_data->so_texture);
	if (map_data->we_texture)
		free(map_data->we_texture);
	if (map_data->ea_texture)
		free(map_data->ea_texture);
	if (map_data->map)
		free_array(map_data->map);
}
