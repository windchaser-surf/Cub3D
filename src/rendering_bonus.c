/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:08:37 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/05 20:41:56 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img -> addr + (y * img -> line_length + x * (img -> bbp / 8));
	*(unsigned int *)dst = color;
}

void	draw_background(t_mlx *data)
{
	int	x;
	int	y;
	int	color;

	color = data->mapinfo->ceiling_color;
	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		if (y > HEIGHT / 2)
			color = data->mapinfo->floor_color;
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(&data->img, x, y, color);
			x++;
		}
		y++;
	}
}

long long int	get_time(void)
{
	struct timeval	time;
	int				res;

	if (gettimeofday(&time, NULL))
		return (-1);
	res = (time.tv_sec * 1000) + (time.tv_usec + 500) / 1000;
	return (res);
}

int	buffer_drawing(t_mlx *data)
{
	long int	start;

	start = get_time();
	if (start - data->prev_time > 24)
	{
		rendering_bonus(data);
		data->prev_time = start;
	}
	return (0);
}

int	rendering_bonus(t_mlx *data)
{
	directions(data);
	draw_background(data);
	raycasting(data);
	ft_draw_minimap_bg(data, MM_POS, MM_RADIUS, 0x000000);
	ft_draw_minimap(data);
	ft_draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.image, 0, 0);
	return (0);
}
