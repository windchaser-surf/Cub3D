/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:26:30 by rluari            #+#    #+#             */
/*   Updated: 2024/03/05 20:40:16 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

void	ft_normie_drawmap(t_mlx *data, t_dot sta)
{
	if (data->mapinfo->map[sta.y][sta.x] == '1')
		ft_draw_minimap_block(data, sta.x, sta.y, 0xFF0000);
	else if (data->mapinfo->map[sta.y][sta.x] == '0'
		|| ft_isalpha(data->mapinfo->map[sta.y][sta.x]))
		ft_draw_minimap_block(data, sta.x, sta.y, 0x00FF00);
}
