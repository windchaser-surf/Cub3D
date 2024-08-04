/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:41:58 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/05 19:36:27 by fwechsle         ###   ########.fr       */
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

	x = 0;
	y = 0;
	color = data->mapinfo->ceiling_color;
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

int	rendering(t_mlx *data)
{
	directions(data);
	draw_background(data);
	raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.image, 0, 0);
	return (0);
}
