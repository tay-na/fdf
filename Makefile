NAME = fdf

SRC = main.c map.c draw.c

OBJ = $(SRC:%.c=%.o)

FLAGS = -Wall -Werror -Wextra

INCL = libft/includes

MLX_MAC = minilibx_macos

LFT = libft -lft

MLX_LIB = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C $(MLX_MAC)
	gcc $(FLAGS) -o $(NAME) $(OBJ) -L$(LFT) -L$(MLX_MAC) $(MLX_LIB)
%.o: %.c 
	gcc $(FLAGS) -I$(INCL) -I$(MLX_MAC) -o $@ -c $<

clean:
	/bin/rm -f $(OBJ)
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean
	make -C $(MLX_MAC) clean

re: fclean all