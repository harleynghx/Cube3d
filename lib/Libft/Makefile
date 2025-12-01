SRCS = $(wildcard *.c)

NAME = libft.a

OBJS = $(SRCS:.c=.o)

OBJS_DIR = objs/
OBJS_PREF = $(addprefix $(OBJS_DIR), $(OBJS))

INCLUDES = -I./

CC = gcc

FLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : %.c
	@mkdir -p objs
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS_PREF)
	@ar rc $(NAME) $(OBJS_PREF)
	@echo "$(NAME) Complied!"

all: $(NAME)

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo Libft fclean!

re: fclean all

.PHONY : all clean fclean re