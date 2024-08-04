/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:29:25 by felix             #+#    #+#             */
/*   Updated: 2024/02/27 17:28:26 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

void	init_values(t_mlx *data, int x_pixel)
{
	data->m.camera_x = 2 * x_pixel / (double)WIDTH -1;
	data->m.raydir_x = data->pos.view_x + data->m.plane_x * data->m.camera_x;
	data->m.raydir_y = data->pos.view_y + data->m.plane_y * data->m.camera_x;
	if (data->m.raydir_x == 0)
		data->m.dx_dist = MAX_DBL;
	else
		data->m.dx_dist = fabs(1 / data->m.raydir_x);
	if (data->m.raydir_y == 0)
		data->m.dy_dist = MAX_DBL;
	else
		data->m.dy_dist = fabs(1 / data->m.raydir_y);
}

t_dot	calc_steps(t_mlx *data, t_dot map)
{
	map.x = (int)data->pos.x;
	map.y = (int)data->pos.y;
	if (data->m.raydir_x < 0)
	{
		data->m.step_x = -1;
		data->m.side_dist_x = (data->pos.x - map.x) * data->m.dx_dist;
	}
	else
	{
		data->m.step_x = 1;
		data->m.side_dist_x = (map.x + 1 - data->pos.x) * data->m.dx_dist;
	}
	if (data->m.raydir_y < 0)
	{
		data->m.step_y = -1;
		data->m.side_dist_y = (data->pos.y - map.y) * data->m.dy_dist;
	}
	else
	{
		data->m.step_y = 1;
		data->m.side_dist_y = (map.y + 1 - data->pos.y) * data->m.dy_dist;
	}
	return (map);
}

void	calc_hit_wall(t_mlx *data, t_dot map, int hit)
{
	if (data->mapinfo->map[map.y][map.x] == '1' || map.x < 0 || map.y < 0)
		hit = 1;
	while (hit == 0)
	{
		if (data->m.side_dist_x < data->m.side_dist_y)
		{
			data->m.side_dist_x += data->m.dx_dist;
			map.x += data->m.step_x;
			data->m.side = 0;
		}
		else
		{
			data->m.side_dist_y += data->m.dy_dist;
			map.y += data->m.step_y;
			data->m.side = 1;
		}
		if (data->mapinfo->map[map.y][map.x] == '1' || map.x < 0 || map.y < 0)
			hit = 1;
	}
}

void	calc_draw_wall(t_mlx *data, int x_pixel)
{
	int		line_height;
	t_calc	pos;

	if (data->m.side == 0)
		data->m.perp_wall_dist = data->m.side_dist_x - data->m.dx_dist;
	else
		data->m.perp_wall_dist = data->m.side_dist_y - data->m.dy_dist;
	line_height = (int)(HEIGHT / data->m.perp_wall_dist);
	pos.start = -line_height / 2 + HEIGHT / 2;
	if (pos.start < 0)
		pos.start = 0;
	pos.end = line_height / 2 + HEIGHT / 2;
	if (pos.end >= HEIGHT)
		pos.end = HEIGHT - 1;
	if (MODE == 1)
		draw_texture(data, x_pixel, line_height, pos);
	else if (MODE == 0)
		draw_color(data, x_pixel, pos);
}

void	raycasting(t_mlx *data)
{
	int		x_pixel;
	int		hit;
	t_dot	map;

	x_pixel = 0;
	while (x_pixel < WIDTH)
	{
		init_values(data, x_pixel);
		map = calc_steps(data, map);
		hit = 0;
		calc_hit_wall(data, map, hit);
		calc_draw_wall(data, x_pixel);
		x_pixel++;
	}
}
