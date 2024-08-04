/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:18:47 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/06 13:02:28 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
//# include "../minilibx-linux/mlx_int.h"
//# include "../minilibx-linux/mlx.h"
# include <stdbool.h>
# include <sys/time.h>
# include <math.h>
# include "../libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>

# define MODE 1	//1 = Texture 0 = color
# define PI 3.1415926535
# define WIDTH 1000
# define HEIGHT 1000
# define SIZE_L 2
# define SIZE_CUBE 64
# define MAX_DBL 1.797693e+308
# define MINI_L 3
# define MM_BLOCK 8
# define MM_RADIUS 100
# define MM_POS 110 //MM_RADIUS + 10
# define ROT_MOUSE 0.04
# define ROT_KEY 0.06

typedef struct s_player
{
	double	x;
	double	y;
	double	view_x;
	double	view_y;
	double	rad;
	double	movespeed;
	double	rot_speed;
}			t_player;

typedef struct s_move
{
	int	forward;
	int	backward;
	int	left;
	int	right;
	int	turn_left;
	int	turn_right;
}			t_move;

typedef struct s_dot
{
	int	x;
	int	y;
}			t_dot;

typedef struct s_calc
{
	int	start;
	int	end;
}			t_calc;

typedef struct s_map
{
	double	camera_x;
	double	plane_x;
	double	plane_y;
	double	raydir_x;
	double	raydir_y;
	double	dx_dist;
	double	dy_dist;
	double	side_dist_x;
	double	side_dist_y;
	double	step_x;
	double	step_y;
	int		side;
	double	perp_wall_dist;
}			t_map;

typedef struct s_parse_map
{
	char		**map;
	int			map_height;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	int			floor_color;
	int			ceiling_color;
	char		direction;
	t_player	playerinfo;
}			t_parse_map;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bbp;
	int		line_length;
	int		endian;
	char	*path_tex;
}			t_texture;

typedef struct s_ray_text
{
	int	tex_x;
	int	tex_y;
}			t_ray_text;

typedef struct s_image
{
	void	*image;
	char	*addr;
	int		bbp;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	long int	prev_time;
	t_player	pos;
	t_image		img;
	t_map		m;
	t_move		events;
	t_parse_map	*mapinfo;
	t_texture	text[4];
	t_ray_text	ray_pos;
	int			check_mouse;
}			t_mlx;

//ft_parse_map.c
_Bool			ft_parse_map(char *filename, t_parse_map *map_data, \
					t_list *tmp);

//init.c
void			ft_init_mlx(t_mlx *data);
void			init_struct(t_mlx *data, t_parse_map *map);

//init_bonus.c
void			ft_init_mlx_bonus(t_mlx *data);
void			init_struct_bonus(t_mlx *data, t_parse_map *map);

//events.c
void			events(t_mlx *data);
int				press_key(int key, t_mlx *data);
int				close_window(t_mlx *data);

//rendering.c
int				rendering(t_mlx *data);
void			my_mlx_pixel_put(t_image *img, int x, int y, int color);

//rendering_bonus.c
long long int	get_time(void);
int				buffer_drawing(t_mlx *data);
int				rendering_bonus(t_mlx *data);

//raycasting.c
void			put_texture(t_mlx *data, int x, int y);

//error.c
void			destroy_err(t_mlx *data, char *err_msg);
void			destroy_textures_img(t_mlx *data);

//textures.c
void			get_images(t_mlx *data);
void			my_mlx_pixel_put_text(t_mlx *data, int x, int y, int color);

//directions.c
void			move_forward(t_mlx *data);
void			directions(t_mlx *data);

//directions_utils.c
void			turn_left(t_mlx *data, double rotSpeed);
void			turn_right(t_mlx *data, double rotSpeed);
double			calc_angle(t_mlx *data);

//raycasting.c 
void			raycasting(t_mlx *data);

//drawing.c
void			put_texture(t_mlx *data, int x, int y);
void			draw_texture(t_mlx *data, int x_Pixel, int lineHeight, \
					t_calc pos);
void			draw_color(t_mlx *data, int x_Pixel, t_calc pos);

//ft_parse_map.c
void			free_struct(t_parse_map *map_data);

//draw_minimap_bonus.c
void			ft_draw_minimap(t_mlx *data);
void			ft_draw_player(t_mlx *data);
void			ft_draw_line(t_mlx *data, int i);
void			ft_draw_minimap_bg(t_mlx *data, int center, int radius, \
					int color);
void			ft_draw_minimap_block(t_mlx *data, int x, int y, int color);

//draw_minimap_bonus_utils.c

void			ft_normie_drawmap(t_mlx *data, t_dot sta);

#endif