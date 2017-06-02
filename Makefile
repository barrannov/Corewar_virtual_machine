# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/29 11:45:35 by oklymeno          #+#    #+#              #
#    Updated: 2017/06/03 00:17:08 by oklymeno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=corewar
LIBFT=libft/libft.a
SOURCES=src/controller/main.c\
		src/controller/vm_validation.c\
		src/controller/vm_flags.c\
		src/view/usage.c\
		src/view/visualize.c\
		src/view/status.c\
		src/model/logic.c\
		src/model/create_map.c\
		src/model/operations/ld.c\
		src/model/operations/lld.c\
		src/model/operations/lldi.c\
		src/model/operations/st.c\
		src/model/operations/add.c\
		src/model/operations/and.c\
		src/model/operations/sub.c\
		src/model/operations/fork.c\
		src/model/operations/lfork.c\
		src/model/operations/live.c\
		src/model/operations/or.c\
		src/model/operations/xor.c\
		src/model/operations/ldi.c\
		src/model/operations/sti.c\
		src/model/operations/zjmp.c\
		src/model/operations/aff.c\
		src/model/help.c\
		src/model/get_processes.c\
		src/model/handle_check.c\
		src/model/steps.c\
		src/model/dir_ind.c

FLAGS=-Wall -Wextra -Werror
OBJECTS=$(SOURCES:.c=.o)

all: $(NAME)

$(NAME):$(OBJECTS)
	gcc -g -o $(NAME) -lncurses $(OBJECTS) -L. $(LIBFT)

%.o:%.c
	gcc -g -c $(FLAGS) -o $@ $<

clean:
	rm -Rf $(OBJECTS)

fclean: clean
	rm -Rf $(NAME)

re: fclean all
