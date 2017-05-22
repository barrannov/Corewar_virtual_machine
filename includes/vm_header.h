/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:37:58 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/22 20:00:33 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_HEADER_H
# define VM_HEADER_H

# include "controller.h"
# include "view.h"
# include "libft.h"
# include <stdio.h>

typedef struct			s_param
{
	int					cycle;
	int					cycle_to_die;
	struct s_player		*player;
}						t_param;

typedef struct			s_player
{
	header_t			*header;
	struct s_processor	*processors;
	int					reg[REG_SIZE];
	int					numb;
	char				*commands;
	struct s_player		*next;
}						t_player;

typedef	struct			s_processor
{
	int					prog_counter;
	struct s_processor	*next;
}						t_processor;

typedef	struct			s_fl
{
	int	dump;
	int vis;
}						t_fl;

void					logic(t_player *player);

t_player        		*read_file_vm(char *file, int numb);
void					vm_get_flags(t_fl *flags, char **argv);

#endif
