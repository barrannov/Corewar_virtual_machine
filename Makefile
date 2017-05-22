# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/29 11:45:35 by oklymeno          #+#    #+#              #
#    Updated: 2017/05/22 18:02:19 by oklymeno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=corewar
LIBFT=libft/libft.a
SOURCES=src/controller/main.c\
		src/controller/vm_validation.c\
		src/controller/vm_flags.c\
		src/view/usage.c\
		src/model/logic.c
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
