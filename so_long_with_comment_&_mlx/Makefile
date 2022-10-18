NAME = so_long

SOURCES = $(SRC_GNL) main.c checker.c textures.c paint.c utils.c \
					 move_one.c move_two.c \
					 bonus.c enemy.c

GNL = get_next_line_bonus.c get_next_line_utils_bonus.c
SRC_GNL = $(addprefix gnl/, $(GNL))

OBJECTS = $(SOURCES:.c=.o)

CC			= gcc
# -fsanitize=address -g
FLAGS		= -Wall -Wextra -Werror 
HEADER		= -I.
RM			= rm -rf
MLX 		=  -Lmlx -lmlx -framework OpenGL -framework AppKit
LIB_FT		= libft/libft.a
# LIB_FT		= -Llibft -lft

# LINKS = -I libft -L libft \
# 	-I /usr/local/include -L /usr/local/lib \
# 	-l mlx -l ft -framework OpenGL -framework Appkit

all:	${NAME}

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

# -Imlx

$(NAME)::
	@cd ./mlx && make
	@mv ./mlx/libmlx.dylib ./libmlx.dylib

$(NAME):: $(OBJECTS)
	@make -C ./libft
	@$(CC) $(FLAGS) $(HEADER) $(MLX) $(OBJECTS) $(LIB_FT) -o $(NAME)

# ${OBJECTS} : ${HEADER} Makefile

clean::
	@cd ./mlx && make clean

clean::	
	@make clean -C ./libft
	$(RM) $(OBJECTS)

fclean:	clean
	@rm -f libmlx.dylib
	@make fclean -C ./libft
	$(RM) so_long

re:		fclean all bonus

.PHONY:	all bonus clean fclean re
