/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:59:18 by fwechsle          #+#    #+#             */
/*   Updated: 2024/02/28 10:47:21 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

void	move_forward(t_mlx *data)
{
	double	buffer_x;
	double	buffer_y;

	if (data->pos.view_x > 0)
		buffer_x = 0.1;
	else
		buffer_x = -0.1;
	if (data->pos.view_y > 0)
		buffer_y = 0.1;
	else
		buffer_y = -0.1;
	if (data->mapinfo->map[(int)(data->pos.y + (-1) * buffer_y)][(int) \
			(data->pos.x + data->pos.view_x * data->pos.movespeed + buffer_x)] \
			!= '1' && data->mapinfo->map[(int)(data->pos.y + buffer_y)][(int) \
			(data->pos.x + data->pos.view_x * data->pos.movespeed + buffer_x)] \
			!= '1')
		data->pos.x += data->pos.view_x * data->pos.movespeed;
	if (data->mapinfo->map[(int)(data->pos.y + buffer_y + data->pos.view_y * \
			data->pos.movespeed)][(int)(data->pos.x + (-1) * buffer_x)] != '1' \
			&& data->mapinfo->map[(int)(data->pos.y + buffer_y + \
			data->pos.view_y * data->pos.movespeed)][(int)(data->pos.x + \
			buffer_x)] != '1')
		data->pos.y += data->pos.view_y * data->pos.movespeed;
}

void	move_backwards(t_mlx *data)
{
	double	buffer_x;
	double	buffer_y;

	if (data->pos.view_x > 0)
		buffer_x = 0.1;
	else
		buffer_x = -0.1;
	if (data->pos.view_y > 0)
		buffer_y = 0.1;
	else
		buffer_y = -0.1;
	if (data->mapinfo->map[(int)(data->pos.y + (-1) * buffer_y)][(int) \
			(data->pos.x - data->pos.view_x * data->pos.movespeed - buffer_x)] \
			!= '1' && data->mapinfo->map[(int)(data->pos.y + buffer_y)][(int) \
			(data->pos.x - data->pos.view_x * data->pos.movespeed - buffer_x)] \
			!= '1')
		data->pos.x -= data->pos.view_x * data->pos.movespeed;
	if (data->mapinfo->map[(int)(data->pos.y - buffer_y - data->pos.view_y * \
			data->pos.movespeed)][(int)(data->pos.x + (-1) * buffer_x)] != '1' \
			&& data->mapinfo->map[(int)(data->pos.y - buffer_y - \
			data->pos.view_y * data->pos.movespeed)][(int)(data->pos.x + \
			buffer_x)] != '1')
		data->pos.y -= data->pos.view_y * data->pos.movespeed;
}

void	move_left(t_mlx *data)
{
	double	side_x;
	double	side_y;
	double	buffer_x;
	double	buffer_y;

	side_x = data->pos.view_x * cos(-PI / 2) - data->pos.view_y * sin(-PI / 2);
	side_y = data->pos.view_x * sin(-PI / 2) + data->pos.view_y * cos(-PI / 2);
	if (side_x > 0)
		buffer_x = 0.10;
	else
		buffer_x = -0.10;
	if (side_y > 0)
		buffer_y = 0.10;
	else
		buffer_y = -0.10;
	if (data->mapinfo->map[(int)(data->pos.y + (-1) * buffer_y)][(int) \
			(data->pos.x + side_x * data->pos.movespeed + buffer_x)] != '1' && \
			data->mapinfo->map[(int)(data->pos.y + buffer_y)][(int) \
			(data->pos.x + side_x * data->pos.movespeed + buffer_x)] != '1')
		data->pos.x += side_x * data->pos.movespeed ;
	if (data->mapinfo->map[(int)(data->pos.y + buffer_y + side_y * \
			data->pos.movespeed)][(int)(data->pos.x + (-1) * buffer_x)] != '1' \
			&& data->mapinfo->map[(int)(data->pos.y + buffer_y + side_y * \
			data->pos.movespeed)][(int)(data->pos.x + buffer_x)] != '1')
		data->pos.y += side_y * data->pos.movespeed ;
}

void	move_right(t_mlx *data)
{
	double	side_x;
	double	side_y;
	double	buffer_x;
	double	buffer_y;

	side_x = data->pos.view_x * cos(PI / 2) - data->pos.view_y * sin(PI / 2);
	side_y = data->pos.view_x * sin(PI / 2) + data->pos.view_y * cos(PI / 2);
	if (side_x > 0)
		buffer_x = 0.1;
	else
		buffer_x = -0.1;
	if (side_y > 0)
		buffer_y = 0.1;
	else
		buffer_y = -0.1;
	if (data->mapinfo->map[(int)(data->pos.y + (-1) * buffer_y)][(int) \
			(data->pos.x + side_x * data->pos.movespeed + buffer_x)] != '1' && \
				data->mapinfo->map[(int)(data->pos.y + buffer_y)][(int) \
				(data->pos.x + side_x * data->pos.movespeed + buffer_x)] != '1')
		data->pos.x += side_x * data->pos.movespeed;
	if (data->mapinfo->map[(int)(data->pos.y + buffer_y + side_y * \
			data->pos.movespeed)][(int)(data->pos.x + (-1) * buffer_x)] != '1' \
			&& data->mapinfo->map[(int)(data->pos.y + buffer_y + side_y * \
			data->pos.movespeed)][(int)(data->pos.x + buffer_x)] != '1')
		data->pos.y += side_y * data->pos.movespeed ;
}

void	directions(t_mlx *data)
{
	if (data->events.forward == 1)
		move_forward(data);
	if (data->events.backward == 1)
		move_backwards(data);
	if (data->events.left == 1)
		move_left(data);
	if (data->events.right == 1)
		move_right(data);
	if (data->events.turn_left == 1)
		turn_left(data, ROT_KEY);
	if (data->events.turn_right == 1)
		turn_right(data, ROT_KEY);
}
