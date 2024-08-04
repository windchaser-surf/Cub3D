/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:11:03 by rluari            #+#    #+#             */
/*   Updated: 2024/03/05 19:44:02 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSER_H
# define CUB3D_PARSER_H

# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../incl/cub3D.h"
# include <limits.h>

typedef struct s_parser_helper
{
	int		rows;
	int		cols;
	int		x;
	int		y;
	int		all_zeros;
	int		*found_zeros;
	bool	*found_player;
}				t_parser_helper;

int		ft_atoi_cub3d(char *str, int sign);
_Bool	ft_ends_with_cub(char *str);
void	free_array(char **str);
_Bool	ft_correct_map_line(char *str);
_Bool	ft_starts_with_number(char *str);
void	ft_skip_spaces(char **str);

_Bool	ft_map_is_valid(t_parse_map *map_data);
int		ft_get_map_size(t_list *map);
bool	ft_ends_with_xpm(char *str);
int		ft_strchr_cub3d(char *str, char c);

int		ft_fill_struct_with_color(int *rgb_value, char *str);
int		ft_fill_struct_with_texture(char **map_data, char *str);

void	ft_mallfail(void);

//utils 3
void	free_gnl_lstclear(char *line, int fd, t_list *map);
void	normie_errhandl(t_list	*map, int fd, char *str);
void	ft_closer(int *files, int size);
bool	ft_missing_textures(t_parse_map *map_d);
void	free_struct(t_parse_map *map_data);

//utils 4
int		ft_count_occur(char *str, char c);
bool	ft_is_player_char(char c);
int		ft_count_words(char *str, char c);

//utils 5
bool	check_north(char **map, t_parser_helper h);
bool	check_south(char **map, t_parser_helper h);
bool	check_west(char **map, t_parser_helper h);
bool	check_east(char **map, t_parser_helper h);

#endif