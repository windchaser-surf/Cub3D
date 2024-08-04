/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:42:51 by rluari            #+#    #+#             */
/*   Updated: 2024/03/04 12:06:40 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"

int	ft_get_map_size(t_list *map)
{
	int		size;
	_Bool	was_map_line;
	char	*str;

	was_map_line = 0;
	size = 0;
	while (map)
	{
		str = (char *)map->content;
		ft_skip_spaces(&str);
		if (ft_isdigit(*str))
		{
			if (ft_correct_map_line(str) == 0)
				return (-1);
			was_map_line = 1;
			size++;
		}
		else if (was_map_line)
			return (ft_putstr_fd("Error\nInconsistent map rows\n", 2), -1);
		map = map->next;
	}
	if (was_map_line == 0)
		return (ft_putstr_fd("Error\nNo map found\n", 2), -1);
	return (size);
}

bool	ft_ends_with_xpm(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 5)
		return (0);
	if (str[len - 1] != 'm' || str[len - 2] != 'p' || str[len - 3] != 'x'
		|| str[len - 4] != '.')
		return (0);
	return (1);
}

int	ft_fill_struct_with_color(int *rgb_value, char *str)
{
	int		rgb_color[3];
	char	**rgb;

	if (*rgb_value != -1)
		return (ft_putstr_fd("Error\nduplicate color\n", 2), 1);
	*rgb_value = -1;
	str++;
	ft_skip_spaces(&(str));
	if (ft_count_occur(str, ',') != 2)
		return (ft_putstr_fd("Error\nWrong rgb format\n", 2), 1);
	rgb = ft_split(str, ',');
	if (!rgb)
		return (ft_mallfail(), 1);
	if (!rgb[0] || !rgb[1] || !rgb[2])
		return (ft_putstr_fd("Error\nwrong rgb format\n", 2), 1);
	rgb_color[0] = ft_atoi_cub3d(rgb[0], 1);
	rgb_color[1] = ft_atoi_cub3d(rgb[1], 1);
	rgb_color[2] = ft_atoi_cub3d(rgb[2], 1);
	free_array(rgb);
	if (rgb_color[0] < 0 || rgb_color[0] > 255 || rgb_color[1] < 0
		|| rgb_color[1] > 255 || rgb_color[2] < 0 || rgb_color[2] > 255)
		return (ft_putstr_fd("Error\ninvalid color\n", 2), 1);
	*rgb_value = (rgb_color[0] << 16) | (rgb_color[1] << 8) | rgb_color[2];
	return (0);
}

int	ft_fill_struct_with_texture(char **map_data, char *str)
{
	if (*map_data)
		return (ft_putstr_fd("Error\nduplicate texture\n", 2), 1);
	str++;
	ft_skip_spaces(&(str));
	if (*str && *str != '\n')
	{
		if (ft_count_occur(str, ' ') || ft_count_occur(str, '\t'))
			return (ft_putstr_fd("Error\nInconsistent texture path\n", 2), 1);
		*map_data = ft_substr(str, 0, ft_strchr_cub3d(str, ' ') - 1);
		if (*map_data == NULL)
			return (ft_mallfail(), 1);
		if (ft_ends_with_xpm(*map_data) == 0)
			return (ft_putstr_fd("Error\nTexture must end with .xpm\n", 2), 1);
	}
	else if (*str == '\n')
		ft_fill_struct_with_texture(map_data, str + 1);
	else
		return (ft_putstr_fd("Error\nEmpty texture path\n", 2), 1);
	return (0);
}

void	ft_mallfail(void)
{
	ft_putstr_fd("Error\nMalloc failed\n", 2);
}
