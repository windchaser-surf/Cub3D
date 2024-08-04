/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:28:50 by felix             #+#    #+#             */
/*   Updated: 2024/02/27 16:44:03 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

double	calc_angle(t_mlx *data)
{
	data->pos.rad = atan2(data->pos.view_y, data->pos.view_x);
	if (data->pos.rad < 0)
		data->pos.rad += 2 * PI;
	if (data->pos.rad > 2 * PI)
		data->pos.rad -= 2 * PI;
	data->pos.rad = 2 * PI - data->pos.rad;
	return (data->pos.rad);
}

void	turn_left(t_mlx *data, double rotSpeed)
{
	double	old_dir;
	double	old_planex;

	old_planex = data->m.plane_x;
	old_dir = data->pos.view_x;
	data->pos.view_x = data->pos.view_x * cos(-rotSpeed) - \
			data->pos.view_y * sin(-rotSpeed);
	data->pos.view_y = old_dir * sin(-rotSpeed) + data->pos.view_y * \
			cos(-rotSpeed);
	data->m.plane_x = data->m.plane_x * cos(-rotSpeed) - \
			data->m.plane_y * sin(-rotSpeed);
	data->m.plane_y = old_planex * sin(-rotSpeed) + data->m.plane_y * \
			cos(-rotSpeed);
	calc_angle(data);
}

void	turn_right(t_mlx *data, double rotSpeed)
{
	double	old_dir;
	double	old_planex;

	old_planex = data->m.plane_x;
	old_dir = data->pos.view_x;
	data->pos.view_x = data->pos.view_x * cos(rotSpeed) - \
			data->pos.view_y * sin(rotSpeed);
	data->pos.view_y = old_dir * sin(rotSpeed) + data->pos.view_y * \
			cos(rotSpeed);
	data->m.plane_x = data->m.plane_x * cos(rotSpeed) - \
			data->m.plane_y * sin(rotSpeed);
	data->m.plane_y = old_planex * sin(rotSpeed) + data->m.plane_y * \
			cos(rotSpeed);
	calc_angle(data);
}
