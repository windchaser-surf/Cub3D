/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:00:00 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/05 10:57:29 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

void	init_start_position_utils(t_mlx *data)
{
	if (data->mapinfo->direction == 'W')
	{
		data->pos.view_x = -1.0;
		data->pos.view_y = 0.0;
		data->m.plane_x = 0.0;
		data->m.plane_y = -0.66;
	}
	else if (data->mapinfo->direction == 'E')
	{
		data->pos.view_x = 1.0;
		data->pos.view_y = 0.0;
		data->m.plane_x = 0.0;
		data->m.plane_y = 0.66;
	}
}

void	init_start_position(t_mlx *data)
{
	if (data->mapinfo->direction == 'N')
	{
		data->pos.view_x = 0.0;
		data->pos.view_y = -1.0;
		data->m.plane_x = 0.66;
		data->m.plane_y = 0.0;
	}
	else if (data->mapinfo->direction == 'S')
	{
		data->pos.view_x = 0.0;
		data->pos.view_y = 1.0;
		data->m.plane_x = -0.66;
		data->m.plane_y = 0.0;
	}
	if (data->mapinfo->direction == 'W' || data->mapinfo->direction == 'E')
		init_start_position_utils(data);
	calc_angle(data);
}

void	init_struct(t_mlx *data, t_parse_map *map)
{
	int	i;

	i = 0;
	data->mlx = NULL;
	data->win = NULL;
	data->img.image = NULL;
	data->pos.x = map->playerinfo.x;
	data->pos.y = map->playerinfo.y;
	data->pos.movespeed = 0.03;
	data->events.forward = 0;
	data->events.backward = 0;
	data->events.left = 0;
	data->events.right = 0;
	data->events.turn_left = 0;
	data->events.turn_right = 0;
	data->mapinfo = map;
	data->check_mouse = 1;
	while (i < 4)
	{
		data->text[i].addr = NULL;
		data->text[i].img = NULL;
		i++;
	}
	init_start_position(data);
}

void	ft_init_mlx(t_mlx *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		destroy_err(data, "Error\nInit mlx\n");
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cube3D");
	if (data->win == NULL)
		destroy_err(data, "Error\nCreate Window\n");
	data->img.image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->img.image == NULL)
		destroy_err(data, "Error\nCreate Image\n");
	data->img.addr = mlx_get_data_addr(data->img.image, &data->img.bbp, \
		&data->img.line_length, &data->img.endian);
	if (data->img.addr == NULL)
		destroy_err(data, "Error\nGet Address of Image");
	get_images(data);
	events(data);
	mlx_loop_hook(data->mlx, rendering, data);
	mlx_loop(data->mlx);
	mlx_do_sync(data->mlx);
}
