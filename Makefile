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

INCLUDES = -I includes -I $(MLX) -I ./lib/Libft

LINKER = -L./lib/Libft -L $(MLX) -L./lib/gnl -lgnl -lft -lm -lmlx $(LINKER_FLAGS)

all : lib $(NAME)
	@echo $(NAME) complied !

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LINKER)

%.o : %.c
	@echo Compiling $<
	$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

lib	:
	@make -C $(MLX)
	@make -C lib/Libft
	@make -C lib/gnl

lclean:
	@make clean -C lib/Libft
	@make clean -C lib/gnl
	@make clean -C $(MLX)

lfclean :
	@make fclean -C lib/Libft
	@make fclean -C lib/gnl
	@make clean -C $(MLX)

lre :
	@make re -C $(MLX)
	@make re -C lib/Libft
	@make re -C lib/gnl

.PHONY : all clean fclean re lib lclean lfclean