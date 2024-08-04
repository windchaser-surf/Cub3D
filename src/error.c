/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:33:58 by felix             #+#    #+#             */
/*   Updated: 2024/02/27 17:01:53 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

void	destroy_textures_img(t_mlx *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->text[i].img)
			mlx_destroy_image(data->mlx, data->text[i].img);
		i++;
	}
}

void	destroy_err(t_mlx *data, char *err_msg)
{
	ft_putstr_fd(err_msg, 2);
	if (data->img.image)
		mlx_destroy_image(data->mlx, data->img.image);
	destroy_textures_img(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data -> mlx);
	free_struct(data->mapinfo);
	free(data->mapinfo);
	exit(1);
}

int	close_window(t_mlx *data)
{
	if (data->img.image)
		mlx_destroy_image(data->mlx, data->img.image);
	destroy_textures_img(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data -> mlx);
	free_struct(data->mapinfo);
	free(data->mapinfo);
	exit(0);
}
