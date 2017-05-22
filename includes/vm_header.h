/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:37:58 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/22 17:23:14 by oklymeno         ###   ########.fr       */
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
	unsigned char				*commands;
	struct s_player		*next;
}						t_player;

typedef	struct			s_processor
{
	int					prog_counter;
	struct s_processor	*next;
}						t_processor;

void					logic(t_player *player);

t_player        		*read_file_vm(header_t *header, char *file);

#endif
