NAME	= so_long

CFLAGS	= -Wall -Wextra -Werror

CC		= gcc

HEADER		= so_long.h

RM			= rm -f

SRCS	= main.c bl.c init_image.c on_click.c validation.c free.c cop.c on_click_checker.c coin.c read_file.c \
		  get_next_line/get_next_line.c get_next_line/get_next_line_utils.c


OBJS 		= ${SRCS:.c=.o}

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS}  -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			$(CC) $(OBJS) $(CFLAGS) libft/libft.a   -Lminilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus:		all

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean ree