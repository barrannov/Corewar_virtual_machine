/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:37:58 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/19 22:20:57 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_HEADER_H
# define VM_HEADER_H

# include "controller.h"
# include "view.h"
# include "libft.h"
# include "model.h"
# include <stdio.h>

typedef struct			s_param
{
	int					cycle;
	int					cycle_to_die;
	char				*map;
	struct s_player		*player;
	struct s_processor	*processors;
}						t_param;

typedef struct			s_player
{
	header_t			*header;
	char				*commands;
	struct s_player		*next;
}						t_player;

typedef	struct			s_processor
{
	int					reg[REG_NUMBERG][REG_SIZE];
	int					prog_counter;
	int 				waite_cycles; //How many cycles left to wait
	struct s_processor	*next;
}						t_processor;

void					logic(t_param *params);

t_player        		*read_file_vm(header_t *header, char *file);

#endif
