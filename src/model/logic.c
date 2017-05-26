/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:17:51 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/24 18:25:03 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm_header.h"

void execute_command(t_processor *process, t_param *param)
{
	//	if ( process->waite_cycles!= 0)
	//		return;
//	if (process->prog_counter == 0) //delete it
//		process->prog_counter = 3;
	if (param->map[process->pc] == 2)
		handle_ld(param, process);
	else if (param->map[process->pc] == 3)
		handle_st(param, process);
    else if (param->map[process->pc] == 4)
        handle_fork(param, process);

}

void set_command_for_proc(t_processor *process, t_param *param)
{
	if (process->waite_cycles != 0)
		return;
	if (param->map[process->pc] == 2)
		set_cycles_ld(process);
    if (param->map[process->pc] == 3)
        set_cycles_fork(process);
}

void execute_process(t_processor *process, t_param *param)
{
/*
 * At the beginning we are checking waite_cycles, if waite_cycles > 0, it means that process needs to wait this cycles
 * if waite_cycles == 0, it means that the machine is ready to execute command
 * */
	if (process->waite_cycles > 0)
	{
		process->waite_cycles--;
		if (process->waite_cycles > 0)
			return;
	}
	execute_command(process, param);
	/*execute command here
	 * */
}

//void execute_champ(t_processor *processors)
//{
//	t_processor *temp_process;
//
//	temp_process = processors;
//	while (temp_process)
//	{
//		execute_process(temp_process);
//		temp_process = temp_process->next;
//	}
//}

int		count_champs(t_player *players)
{
	int			res;
	t_player	*tmp;

	res = 0;
	tmp = players;
	while (tmp)
	{
		res++;
		tmp = tmp->next;
	}
	return (res);
}

void	print_map(t_param *param)//this func must be in view
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if (i % 64 == 0)
		{
			printf("\n");
			printf("row # ");
		}
		if (param->map[i] == 0)
			printf("%.2x ", (unsigned char)param->map[i]);
		else
			printf("\033[32;1m%.2x\033[0m ", (unsigned char)param->map[i]);
	}
	printf("\n");

}

void	logic(t_player *players)
{
	t_param *param;

	param = malloc(sizeof(t_param));
	players->processors = NULL;
	param->amount_champs = count_champs(players);
	create_map(players, param);
	get_processes(param);
	print_map(param);
	execute_command(param->players->processors, param);
	printf("step 2\n");
//	execute_command(param->players->processors, param);
	print_map(param);

}
/*
   void logic(t_param *params)
   {
//	t_processor *temp_proc;

	if (!params)
		return;

	execute_command(params->processors, params);
//	while (params->cycle_to_die > 0)
//	{
//		temp_proc = params->processors;
//		params->cycle_to_die--;
	//	while (temp_proc)
	//	{
	//		set_command_for_proc(temp_proc, params);
	//		execute_process(params->processors, params);
	//		temp_proc = temp_proc->next;
	//	}
//	}
}
