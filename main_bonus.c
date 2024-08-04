/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:18:17 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/05 10:54:45 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/cub3D.h"
#include "utils_parser/cub3d_parser.h"

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
	init_struct_bonus(&data, map);
	ft_init_mlx_bonus(&data);
	return (0);
}
