/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:19:22 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/05 19:39:06 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/cub3D.h"
#include "utils_parser/cub3d_parser.h"

/* void	ft_print_struct(t_parse_map *map)
{
	printf("NO: %s\n", map->no_texture);
	printf("SO: %s\n", map->so_texture);
	printf("WE: %s\n", map->we_texture);
	printf("EA: %s\n", map->ea_texture);
	printf("C: %d\n", map->ceiling_color);
	printf("F: %d\n", map->floor_color);

	int i = 0;
	//printf("map[6][2] = %c\n", map->map[5][2]);
	while (map->map[i])
	{
		printf("%s", map->map[i]);
		i++;
	}
} */

bool	ft_basic_check(int argc, char **argv)
{
	if (argc != 2)
		return (ft_putstr_fd("Error\nWrong number of arguments\n", 2), 1);
	if (ft_ends_with_cub(argv[1]) == 0)
		return (ft_putstr_fd("Error\nFile must end with .cub\n", 2), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_parse_map	*map;
	t_mlx		data;

	if (ft_basic_check(argc, argv))
		return (1);
	map = malloc(sizeof(t_parse_map));
	if (!map)
		return (ft_mallfail(), 1);
	if (ft_parse_map(argv[1], map, NULL))
		return (free(map), 1);
	init_struct(&data, map);
	ft_init_mlx(&data);
	return (0);
}
