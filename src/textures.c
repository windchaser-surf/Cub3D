/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:26:40 by fwechsle          #+#    #+#             */
/*   Updated: 2024/02/27 17:41:23 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

void	get_textures_address(t_mlx *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->text[i].addr = mlx_get_data_addr(data->text[i].img, \
			&data->text[i].bbp, \
			&data->text[i].line_length, &data->text[i].endian);
		if (data->text[i].addr == NULL)
			destroy_err(data, "Error\nGet Address of Textures\n");
		i++;
	}
}

void	get_images(t_mlx *data)
{
	int	size;

	size = SIZE_CUBE;
	data->text[0].img = mlx_xpm_file_to_image(data->mlx, \
							data->mapinfo->no_texture, &size, &size);
	if (data->text[0].img == NULL)
		destroy_err(data, "Error\nTexture North\n");
	data->text[1].img = mlx_xpm_file_to_image(data->mlx, \
							data->mapinfo->so_texture, &size, &size);
	if (data->text[1].img == NULL)
		destroy_err(data, "Error\nTexture South\n");
	data->text[2].img = mlx_xpm_file_to_image(data->mlx, \
							data->mapinfo->we_texture, &size, &size);
	if (data->text[2].img == NULL)
		destroy_err(data, "Error\nTexture West\n");
	data->text[3].img = mlx_xpm_file_to_image(data->mlx, \
							data->mapinfo->ea_texture, &size, &size);
	if (data->text[3].img == NULL)
		destroy_err(data, "Error\nTexture East\n");
	get_textures_address(data);
}

void	my_mlx_pixel_put_text(t_mlx *data, int x, int y, int i)
{
	char	*dst;
	int		color;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	color = *(int *)(data->text[i].addr + (data->ray_pos.tex_y * \
		data->text[i].line_length + data->ray_pos.tex_x * \
		(data->text[i].bbp / 8)));
	dst = data->img.addr + (y * data->img.line_length + \
		x * (data->img.bbp / 8));
	*(unsigned int *)dst = color;
}
