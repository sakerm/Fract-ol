NAME = fractol

CPL = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework Appkit

SRC = src/burningship.c src/main.c src/julia.c src/mandelbrot.c src/julio.c

OBJ = $(SRC:.c=.o)

all = $(NAME)

$(NAME) : $(OBJ)
	@make -C inc/libft/
	@gcc -o $(NAME) $(CPL) $(OBJ)  inc/libft/libft.a

clean :
	@rm -f $(OBJ)
	make clean -C inc/libft

fclean : clean
	@rm -f $(NAME)
	make fclean -C inc/libft

re : fclean $(NAME)
