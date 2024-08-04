NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs
LDFLAGS = -lbsd
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c \
ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstlast.c ft_lstnew.c ft_lstsize.c get_next_line/get_next_line.c

OBJS = $(SRCS:.c=.o)
# Execute when run make
all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

# Build object files from .c files	
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Remove object files
clean:
	@rm -rf $(OBJS)
	
# Remove object files and rush-02
fclean: clean
	@rm -rf $(NAME)
	
# Rebuild program
re: fclean all

# These targets are always executed
.PHONY: all clean fclean re
