/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:37:58 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/26 16:43:24 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_HEADER_H
# define VM_HEADER_H

# include "controller.h"
# include "view.h"
# include "op.h"
# include "libft.h"
# include "model.h"
# include <stdio.h>


typedef struct			s_param
{
	int					cycle;
	int					cycle_to_die;
	unsigned char		*map;
	struct s_player		*players;

	int					amount_champs;
}						t_param;

typedef struct			s_player
{
	header_t			*header;
	struct s_processor	*processors;
	int					reg[REG_SIZE];
	int					numb;
	unsigned char		*commands;
	struct s_player		*next;
}						t_player;

typedef	struct			s_processor
{
	int					reg[REG_NUMBER];
	int					pc;
	char				carry;
	int 				waite_cycles; //How many cycles left to wait
	struct s_processor	*next;
}						t_processor;

typedef struct			s_val
{
	char	val1;
	char	val2;
	char	val3;
}						t_val;

void					logic(t_player *players);
//void logic(t_param *params);
void 					set_cycles_ld(t_processor *pro);
//operations
void 					handle_ld(t_param *params, t_processor *proc);
void 					handle_st(t_param *params, t_processor *proc);
void 					handle_add(t_param *params, t_processor *proc);
void 					handle_sub(t_param *params, t_processor *proc);
//
void 					create_map(t_player *players, t_param *param);
void					print_map(t_param *param);
void					get_processes(t_param *param);
void handle_fork(t_param *player, t_processor *processor);
void set_cycles_fork(t_processor *processor);
typedef	struct			s_fl
{
	int	dump;
	int vis;
}						t_fl;

void					print_reg(t_processor *proc);//for testing, delete it

void					get_vis(t_fl *flags, char **argv);
int						digit(char *str);
void					vm_get_flags(t_fl *flags, char **argv);
int						vm_get_numb(char **argv, int n, int *numb);
void					get_args(t_val *val, unsigned char *map, t_processor *proc);
t_player        		*read_file_vm(char *file, int numb);
void					vm_get_flags(t_fl *flags, char **argv);
unsigned int			handle_dir(t_param *param, t_processor *proc, int am_byte, int pos);
unsigned int			handle_ind(t_param *param, t_processor *proc, int pos);
#endif
