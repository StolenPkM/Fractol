CC =		gcc
CCO =		gcc -c
FLAGS =		-Wall -Wextra -Werror -fsanitize=address
NAME =		fractol
LIB =		libft.a
LIB_DOS =	libft
INC =		./src/fractol.h
SRC_PATH =	./src
OPENGL = -lmlx -framework OpenGL -framework AppKit
SRC =	main.c\
		mandel.c\
		julia.c\
		sword.c\
		key_hook.c\
		key_hook_tool.c\
		mouse_hook.c\
		redraw.c\
		tool.c\

SRCS =	$(addprefix $(SRC_PATH)/, $(SRC))
OBJS =	main.o\
		mandel.o\
		julia.o\
		sword.o\
		key_hook.o\
		key_hook_tool.o\
		mouse_hook.o\
		redraw.o\
		tool.o\

C_NO =		"\033[00m"
C_OK =		"\033[32m"
C_GOOD	=	"\033[32m"
C_ERROR =	"\033[31m"
C_WARN =	"\033[31m"
SUCCESS =	$(C_OK)SUCCESS$(C_NO)
OK =		$(C_OK)OK$(C_NO)

all: $(NAME)

$(NAME):	$(LIB) $(OBJS)
		$(CC) $(SRCS) libft/libft.a  -o fractol $(FLAGS) $(OPENGL)
		@echo "Compiling & indexing" [ $(NAME) ] $(SUCCESS)
$(LIB):
	@make -C $(LIB_DOS)
$(OBJS):
	$(CCO) $(FLAGS) $(SRCS)
clean:
	rm -f $(OBJS)
	rm -f ./libft/*.o
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)

fclean:	clean
	rm -f $(NAME)
	rm -f libft/libft.a
re:	fclean all

.PHONY:	all clean fclean re
