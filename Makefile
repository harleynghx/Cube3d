NAME = test
SRC = test.c
MLX_DIR = minilibx
MLX = $(MLX_DIR)/libmlx.a
INCLUDES = -I$(MLX_DIR)
FRAMEWORKS = -framework OpenGL -framework AppKit

all:
	gcc $(SRC) $(MLX) $(INCLUDES) $(FRAMEWORKS) -o $(NAME)

clean:
	rm -f $(NAME)

.PHONY: all clean fclean re