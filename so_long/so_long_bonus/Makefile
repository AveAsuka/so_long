NAME = so_long_bonus

SOURCES = $(SRC_GNL) main_bonus.c checker_bonus.c checker_two_bonus.c  \
					paint_bonus.c utils_bonus.c \
					textures_bonus.c textures_two_bonus.c \
					move_one_bonus.c move_one_two_bonus.c move_two_bonus.c\
					enemy_bonus.c enemy_two_bonus.c bonus_bonus.c

GNL = get_next_line_bonus.c get_next_line_utils_bonus.c
SRC_GNL = $(addprefix ../gnl/, $(GNL))

OBJECTS = $(SOURCES:.c=.o)

CC			= cc
FLAGS		= -Wall -Wextra -Werror 
HEADER		= -I.
RM			= rm -rf
MLX 		= -lmlx -framework OpenGL -framework AppKit
LIB_FT		= ../libft/libft.a

bonus:	${NAME}

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
	$(RM) so_long_bonus

re:		fclean all bonus

.PHONY:	all bonus clean fclean re
