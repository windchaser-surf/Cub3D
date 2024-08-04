/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:16:11 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/05 10:55:08 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

int	release_key(int key, t_mlx *data)
{
	if (key == 'w' || key == 'W')
		data->events.forward = 0;
	if (key == 's' || key == 'S')
		data->events.backward = 0;
	if (key == 'a' || key == 'A')
		data->events.left = 0;
	if (key == 'd' || key == 'D')
		data->events.right = 0;
	if (key == 65361)
		data->events.turn_left = 0;
	if (key == 65363)
		data->events.turn_right = 0;
	return (0);
}

int	press_key(int key, t_mlx *data)
{
	if (key == 'w')
		data->events.forward = 1;
	if (key == 's')
		data->events.backward = 1;
	if (key == 'a')
		data->events.left = 1;
	if (key == 'd')
		data->events.right = 1;
	if (key == 65363)
		data->events.turn_right = 1;
	if (key == 65361)
		data->events.turn_left = 1;
	if (key == 65307)
		close_window(data);
	return (0);
}

void	events(t_mlx *data)
{
	mlx_hook(data->win, 2, 1L << 0, press_key, data);
	mlx_hook(data->win, 3, 1L << 1, release_key, data);
	mlx_hook(data->win, 17, 0L, close_window, data);
}
