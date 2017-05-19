# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/29 11:45:35 by oklymeno          #+#    #+#              #
#    Updated: 2017/05/19 19:42:28 by oklymeno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=corewar
LIBFT=libft/libft.a
SOURCES=controller/main.c\
		controller/validation_vm.c
HEADER=includes/controller.h
FLAGS=-Wall -Wextra -Werror
OBJECTS=$(SOURCES:.c=.o)

all: $(NAME)

$(NAME):$(OBJECTS)
	gcc -g -o $(NAME) $(OBJECTS) -L. $(LIBFT)

%.o:%.c
	gcc -g -c $(FLAGS) -o $@ $<

clean:
	rm -Rf $(OBJECTS)

fclean: clean
	rm -Rf $(NAME)

re: fclean all
