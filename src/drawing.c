/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:16:01 by fwechsle          #+#    #+#             */
/*   Updated: 2024/02/27 17:41:30 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

void	draw_color(t_mlx *data, int x_Pixel, t_calc pos)
{
	while (pos.start <= pos.end)
	{
		if (data->m.side == 0)
			my_mlx_pixel_put(&data->img, x_Pixel, pos.start, 0xEE2C2C);
		else
			my_mlx_pixel_put(&data->img, x_Pixel, pos.start, 0x8B1A1A);
		pos.start++;
	}
}

void	draw_texture(t_mlx *data, int x_Pixel, int lineHeight, t_calc pos)
{
	double	step;
	double	tex_pos;
	double	wall_x;

	if (data->m.side == 0)
		wall_x = data->pos.y + data->m.perp_wall_dist * data->m.raydir_y;
	else
		wall_x = data->pos.x + data->m.perp_wall_dist * data->m.raydir_x;
	wall_x -= floor(wall_x);
	data->ray_pos.tex_x = (int)(wall_x * (double)(SIZE_CUBE));
	if (data->m.side == 0 && data->m.raydir_x < 0)
		data->ray_pos.tex_x = SIZE_CUBE - data->ray_pos.tex_x -1;
	if (data->m.side == 1 && data->m.raydir_y > 0)
		data->ray_pos.tex_x = SIZE_CUBE - data->ray_pos.tex_x -1 ;
	step = 1.0 * (double)SIZE_CUBE / (double)lineHeight;
	tex_pos = (pos.start - HEIGHT / 2 + lineHeight / 2) * step;
	while (pos.start <= pos.end)
	{
		data->ray_pos.tex_y = (int)tex_pos & (SIZE_CUBE - 1);
		tex_pos += step;
		put_texture(data, x_Pixel, pos.start);
		pos.start++;
	}
}

void	put_texture(t_mlx *data, int x, int y)
{
	if (data->m.side && data->m.raydir_y < 0)
		my_mlx_pixel_put_text(data, x, y, 0);
	else if (data->m.side && data->m.raydir_y > 0)
		my_mlx_pixel_put_text(data, x, y, 1);
	else if (!data->m.side && data->m.raydir_x < 0)
		my_mlx_pixel_put_text(data, x, y, 2);
	else if (!data->m.side && data->m.raydir_x > 0)
		my_mlx_pixel_put_text(data, x, y, 3);
}
