# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 23:17:16 by pabonnin          #+#    #+#              #
#    Updated: 2017/06/29 14:02:25 by pabonnin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC = libft.h

ALLO = *.o
ALLC = ft_*.c \
	   get_next_line.c \

CCO = gcc -c -Wall -Wextra -Werror
CCC = gcc -Wall -Wextra -Werror -o

all: $(NAME)

$(NAME):
	$(CCO) $(ALLC)
	ar rc $(NAME) $(ALLO) 
	ranlib $(NAME)

clean:
	    /bin/rm -rf $(ALLO)

fclean: clean
	    /bin/rm -rf $(NAME)

re: fclean all
