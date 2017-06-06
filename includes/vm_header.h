/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:37:58 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/03 18:07:50 by oklymeno         ###   ########.fr       */
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
# include <ncurses.h>

typedef struct			s_param
{
	int					cycle;
	int					cycle_to_die;
	unsigned char		*map;
	unsigned char		*map_c;
	struct s_player		*players;
	struct s_processor	*processors;
	int					amount_checks;
	int					amount_champs;
	int					amount_proc;
}						t_param;

typedef struct			s_player
{
	header_t			*header;
	int					live;
	int					live_amount;
	int					pos;
	int					numb;
	unsigned char		*commands;
	struct s_player		*next;
}						t_player;

typedef	struct			s_processor
{
	int					is_alive;
	int					player;
	int					reg[REG_NUMBER];
	int					pc;
	char				carry;
	int					waite_cycles;
    unsigned int       temp_command;
    struct s_processor	*next;
}						t_processor;

typedef struct			s_val
{
	char	val1;
	char	val2;
	char	val3;
}						t_val;

typedef	struct			s_fl
{
	int	dump;
	int vis;
}						t_fl;

/*
** main logic
*/
void					sort_players(t_param *param);
void					handle_check(t_param *param);
int						check_args(t_val *val);
void					add_process(t_param *params, short pc, int numb);
void					logic(t_player *players, t_fl *flags);
void					set_cycles_ld(t_processor *pro);
int						amount_lst_el(t_processor *procs);
void					set_cycles_live(t_processor *proc);
void					create_map(t_player *players, t_param *param);
void					print_map(t_param *param);
void					get_vis(t_fl *flags, char **argv);
void					get_processes(t_param *param);
/*
** commands
*/
void					handle_ld(t_param *params, t_processor *proc);
void					handle_st(t_param *params, t_processor *proc);
void					handle_add(t_param *params, t_processor *proc);
void					handle_sub(t_param *params, t_processor *proc);
void					handle_and(t_param *params, t_processor *proc);
void					handle_live(t_param *params, t_processor *proc);
void					handle_or(t_param *params, t_processor *proc);
void					handle_xor(t_param *params, t_processor *proc);
void					handle_ldi(t_param *params, t_processor *proc);
void					handle_sti(t_param *params, t_processor *proc);
void					handle_fork(t_param *player, t_processor *proc);
void					handle_lfork(t_param *param, t_processor *proc);
void					handle_lldi(t_param *params, t_processor *proc);
void					handle_lld(t_param *params, t_processor *proc);
void					handle_zjmp(t_param *params, t_processor *proc);
void					handle_aff(t_param *params, t_processor *proc);
/*
** operation support
*/
int						get_arg_or_xor_and(t_param *params, t_processor
		*proc, char val, int pos);
int						get_move_or_xor_and(char val);
int						check_args_or_xor_and(t_val *val);
short int				count_steps(t_val *val, short int opcode);
int						handle_dir(t_param *param, t_processor *proc,
		short int am_byte, short int pos);
int						handle_ind(t_param *param, t_processor *proc, int pos,
		char idx, char label);
/*
** controller
*/
void					vm_get_flags(t_fl *flags, char **argv);
int						vm_get_numb(char **argv, int n, int *numb);
void					get_args(t_val *val, unsigned char *map,
		t_processor *proc);
t_player				*read_file_vm(char *file, int numb);
void					vm_get_flags(t_fl *flags, char **argv);
int						digit(char *str);

void					visualize(t_param *param);
void					print_status(t_param *param, WINDOW *status);
void					key_hook(int flag);
#endif
