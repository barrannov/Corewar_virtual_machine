/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:17:51 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/07 20:26:40 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

int					amount_lst_el_players(t_player *player)
{
	int i;

	i = 0;
	while (player)
	{
		i++;
		player = player->next;
	}
	return (i);
}

int					amount_lst_el(t_processor *procs)
{
	int i;

	i = 0;
	while (procs)
	{
		i++;
		procs = procs->next;
	}
	return (i);
}

void				special_for_denchik(t_param *params, t_fl *flags)
{
	t_processor *temp_proc;

	temp_proc = params->processors;
	while (temp_proc)
	{
   //     if(temp_proc && temp_proc->pc > 4096)
     //   {
       //     temp_proc->pc = temp_proc->pc % MEM_SIZE;
        //}
  //      if (temp_proc->index == 87 && params->cycle == 7210)
   //     {
//
  //      }
		if (params->cycle == flags->dump && params->cycle > 0)
		{
			print_map(params->map);
			exit(1);
		}
		set_command_for_proc(temp_proc, params);
		execute_process(temp_proc, params);
		temp_proc = temp_proc->next;
	}
	if (params->cycle % params->cycle_to_die == 0 && params->cycle > 0)
	{
		handle_check(params);
		unset_is_alive_process(params->processors);
		unset_live_amount(params);
	}
}

void				algorithm(t_param *params, t_fl *flags)
{
	params->cycle = 0;
	while (params->cycle_to_die > 0 && params->amount_proc > 0) {
        if (params->cycle == 7300) {

        }
        if (flags->vis == 1 && params->cycle >  2480)
        {
            visualize(params);
          // usleep(800000);
    }
		special_for_denchik(params, flags);
		params->cycle++;
//		ft_putstr("cycle: ");
//		ft_putnbr(params->cycle);
//		ft_putchar('\n');
//        ft_putstr("camount_proc : ");
//        ft_putnbr(params->amount_proc);
//        ft_putchar('\n');
	}
	endwin();
	if (params->cycle < flags->dump)
		print_map(params->map);
	output_the_winner(params->players);
}

void				logic(t_player *players, t_fl *flags)
{
	t_param *param;

	param = malloc(sizeof(t_param));
	param->processors = NULL;
	param->amount_champs = count_champs(players);
	param->amount_proc = 1;
	create_map(players, param);
	get_processes(param);
	param->amount_champs = 0;
	param->cycle_to_die = CYCLE_TO_DIE;
	algorithm(param, flags);
	//print_map(param->map);
}
