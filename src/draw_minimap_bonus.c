/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:21:29 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/05 20:35:38 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

void	ft_draw_minimap_bg(t_mlx *data, int center, int radius, int color)
{
	int	x;
	int	y;

	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
				my_mlx_pixel_put(&data->img, center + x, center + y, color);
			x++;
		}
		y++;
	}
}

/*
//double angle = calc_angle(data) - PI / 2;
rotated.x = (new_coord.x * cos(angle) - new_coord.y * sin(angle) + MM_POS);
rotated.y = (new_coord.x * sin(angle) + new_coord.y * cos(angle) + MM_POS);
*/

void	ft_draw_line(t_mlx *data, int i)
{
	int		dx;
	int		dy;
	int		steps;
	double	start_x;
	double	start_y;

	dx = cos(data->pos.rad) * 20;
	dy = -sin(data->pos.rad) * 20;
	i = 0;
	start_x = MM_POS;
	start_y = MM_POS;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	while (i <= steps)
	{
		my_mlx_pixel_put(&data->img, start_x, start_y, 0x0000FF);
		start_x += (double)dx / steps;
		start_y += (double)dy / steps;
		i++;
	}
}

void	ft_draw_minimap_block(t_mlx *data, int x, int y, int color)
{
	t_dot	block;
	t_dot	dist;
	t_dot	new_pix;

	block.y = 0;
	while (block.y < MM_BLOCK)
	{
		block.x = 0;
		while (block.x < MM_BLOCK)
		{
			dist.x = (x - data->pos.x) * MM_BLOCK + block.x;
			dist.y = (y - data->pos.y) * MM_BLOCK + block.y;
			if (pow(dist.x, 2) + pow(dist.y, 2) <= pow(MM_RADIUS, 2))
			{
				new_pix.x = (x - data->pos.x) * MM_BLOCK + block.x + MM_POS;
				new_pix.y = (y - data->pos.y) * MM_BLOCK + block.y + MM_POS;
				my_mlx_pixel_put(&data->img, new_pix.x, new_pix.y, color);
			}
			block.x++;
		}
		block.y++;
	}
}

void	ft_draw_player(t_mlx *data)
{
	int	p_x;
	int	p_y;
	int	half_block;

	half_block = MM_BLOCK / 2;
	p_x = -half_block;
	while (p_x < half_block)
	{
		p_y = -half_block;
		while (p_y < half_block)
		{
			my_mlx_pixel_put(&data->img, 0 + p_x + MM_POS,
				0 + p_y + MM_POS, 0x0000FF);
			p_y++;
		}
		p_x++;
	}
	ft_draw_line(data, 0);
}

/* void	ft_draw_minimap(t_mlx *data)
{
	int	y;
	int	x;

	y = 0;
	ft_draw_minimap_bg(data, MM_POS, MM_RADIUS, 0x000000);
	while (y < data->mapinfo->map_height)
	{
		x = 0;
		while (x < (int)ft_strlen(data->mapinfo->map[y]))
		{
			if (data->mapinfo->map[y][x] == '1')
				ft_draw_minimap_block(data, x, y, 0xFF0000);
			else if (data->mapinfo->map[y][x] == '0'
				|| ft_isalpha(data->mapinfo->map[y][x]))
				ft_draw_minimap_block(data, x, y, 0x00FF00);
			x++;
		}
		y++;
	}
} */

void	ft_draw_minimap(t_mlx *data)
{
	t_dot	sta;
	t_dot	end;

	sta.y = (int)data->pos.y - (int)((float)MM_RADIUS / MM_BLOCK + 0.5);
	end.y = (int)data->pos.y + (int)((float)MM_RADIUS / MM_BLOCK + 1.5);
	if (sta.y < 0)
		sta.y = 0;
	if (end.y > data->mapinfo->map_height)
		end.y = data->mapinfo->map_height;
	while (sta.y < end.y)
	{
		sta.x = (int)data->pos.x - (int)((float)MM_RADIUS / MM_BLOCK + 0.5);
		end.x = (int)data->pos.x + (int)((float)MM_RADIUS / MM_BLOCK + 1.5);
		if (sta.x < 0)
			sta.x = 0;
		if (end.x > (int)ft_strlen(data->mapinfo->map[sta.y]))
			end.x = ft_strlen(data->mapinfo->map[sta.y]);
		while (sta.x < end.x)
		{
			ft_normie_drawmap(data, sta);
			sta.x++;
		}
		sta.y++;
	}
}
