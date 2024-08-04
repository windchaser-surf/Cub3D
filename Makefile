NAME = cub3D
NAME_BONUS = cub3D_bonus
SOURCES = main.c src/events.c src/init.c src/rendering.c src/raycasting.c \
			utils_parser/ft_parse_map.c utils_parser/ft_atoi_cub3d.c \
			utils_parser/ft_parse_map_utils.c utils_parser/ft_parse_map_utils2.c \
			utils_parser/ft_validate_map.c utils_parser/ft_parse_map_utils3.c utils_parser/ft_parse_map_utils4.c src/textures.c \
			utils_parser/ft_parse_map_utils5.c src/directions.c src/error.c src/directions_utils.c src/drawing.c
SRC_BONUS = main_bonus.c src/events_bonus.c src/init_bonus.c src/rendering_bonus.c src/raycasting.c \
			utils_parser/ft_parse_map.c utils_parser/ft_atoi_cub3d.c utils_parser/ft_parse_map_utils3.c utils_parser/ft_parse_map_utils4.c \
			utils_parser/ft_parse_map_utils.c utils_parser/ft_parse_map_utils2.c \
			utils_parser/ft_parse_map_utils5.c utils_parser/ft_validate_map.c src/textures.c src/directions.c \
			src/error.c src/directions_utils.c src/drawing.c src/draw_minimap_bonus.c src/draw_minimap_bonus_utils.c
OBJS = $(SOURCES:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LIBXFLAGS = -L minilibx-linux/ -lmlx -lm -lX11 -lXext
MATHFLAG = -lm
RM = rm -rf

all: $(NAME) 

$(NAME): $(OBJS) 
	@echo "\033[0;32mCube3d is compiling...\033[0m"
	@$(MAKE) -C libft all --no-print-directory
	@$(MAKE) -C minilibx-linux all --no-print-directory
	@$(CC) $(CFLAGS) $(OBJS) $(LIBXFLAGS) -L. libft/libft.a -o $(NAME) 
	@echo "\033[0;32mCube3d is compiled!\033[0m"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	@echo "\033[0;32mCube3d_bonus is compiling...\033[0m"
	@$(MAKE) -C libft all --no-print-directory
	@$(MAKE) -C minilibx-linux all --no-print-directory
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBXFLAGS) -L. libft/libft.a -o $(NAME_BONUS) 
	@echo "\033[0;32mCube3d_bonus is compiled!\033[0m"

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@$(MAKE) -C libft clean --no-print-directory
	@$(MAKE) -C minilibx-linux clean
	@echo "\033[0;32mRemoved objects!\033[0m"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@$(RM) libft/libft.a
	
	@echo "\033[0;32mEverything is cleaned!\033[0m"

re_bonus:	fclean bonus

re: fclean all

.PHONY:	all clean fclean re re_bonus
