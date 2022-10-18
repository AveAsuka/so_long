NAME = so_long_mandatory

SOURCES = $(SRC_GNL) main.c checker.c checker_two.c paint.c utils.c \
					textures.c textures_two.c \
					move_one.c move_one_two.c move_two.c\

GNL = get_next_line_bonus.c get_next_line_utils_bonus.c
SRC_GNL = $(addprefix ../gnl/, $(GNL))

OBJECTS = $(SOURCES:.c=.o)

CC			= cc
FLAGS		= -Wall -Wextra -Werror 
HEADER		= -I.
RM			= rm -rf
MLX 		= -lmlx -framework OpenGL -framework AppKit
LIB_FT		= ../libft/libft.a

all:	${NAME}

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJECTS)
	make -C ../libft
	$(CC) $(FLAGS) $(HEADER) $(OBJECTS) $(LIB_FT) $(MLX) -o $(NAME)

clean:	
	make -C ../libft clean
	$(RM) $(OBJECTS)
		
fclean:	clean
	make -C ../libft fclean
	$(RM) so_long_mandatory

re:		fclean all

.PHONY:	all clean fclean re
