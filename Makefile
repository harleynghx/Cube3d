NAME = cub3d

CC = cc

SRC = $(wildcard src/*/*.c)

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -g3 -O3

ifeq ($(shell uname), Linux)
	MLX = lib/minilibx-linux
	LINKER_FLAGS = -lXext -lX11 -lz
else
	MLX = lib/minilibx_opengl
	LINKER_FLAGS = -framework OpenGL -framework AppKit
endif

INCLUDES = -I includes -I $(MLX) -I ./lib/libft

LINKER = -L./lib/libft -L $(MLX) -L./lib/gnl -lgnl -lft -lm -lmlx $(LINKER_FLAGS)

all : lib $(NAME)
	@echo $(NAME) complied !

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LINKER)

%.o : %.c
	@echo Compiling $<
	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C lib/libft
	@make fclean -C lib/gnl

re : fclean all

lib	:
	@make -C $(MLX)
	@make -C lib/libft
	@make -C lib/gnl

DEF_COLOR = \033[0;39m
CYAN3 = \033[1;4;96m
YELLOW = \033[1;33m
PURPLE = \033[1;35m
BWhite = \033[1;37m
RED = \033[1;4;91m
GREEN = \033[4;92m
CYAN2 = \x1B[1;36m
CYAN = \033[1;96m

.PHONY : all clean fclean re lib