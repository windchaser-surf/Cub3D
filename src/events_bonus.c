/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:24:47 by felix             #+#    #+#             */
/*   Updated: 2024/03/05 10:55:15 by fwechsle         ###   ########.fr       */
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

int	mouse_move(int x, int y, t_mlx *data)
{
	double	delta_x;

	(void)y;
	if (data->check_mouse == -1)
		mlx_mouse_move(data->mlx, data->win, WIDTH / 2, HEIGHT / 2);
	else
		return (0);
	if (x > WIDTH / 2)
	{
		delta_x = (double)(x - WIDTH / 2) / 100.0;
		turn_right(data, delta_x);
	}
	else if (x < WIDTH / 2)
	{
		delta_x = (double)(WIDTH / 2 - x) / 100.0;
		turn_left(data, delta_x);
	}
	return (0);
}

int	check_mouse(int key, int x, int y, t_mlx *data)
{
	(void)x;
	(void)y;
	if (key == 1)
		data->check_mouse *= -1;
	return (0);
}

void	events(t_mlx *data)
{
	mlx_hook(data->win, ButtonPress, ButtonPressMask, check_mouse, data);
	mlx_hook(data->win, 6, PointerMotionMask, mouse_move, data);
	mlx_hook(data->win, 2, 1L << 0, press_key, data);
	mlx_hook(data->win, 3, 1L << 1, release_key, data);
	mlx_hook(data->win, 17, 0L, close_window, data);
}
