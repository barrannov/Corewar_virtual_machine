/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:17:51 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/20 15:03:33 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm_header.h"

void execute_command(t_processor *process, t_param *param)
{
	if (param->map[process->prog_counter] == 0 && param->map[process->prog_counter] == 2)
		handle_ld(param, process);
}

void set_command_for_proc(t_processor *process, t_param *param)
{
	if (process->prog_counter != 0)
		return;
	if (param->map[process->prog_counter] == 0 && param->map[process->prog_counter] == 2)
		set_cycles_ld(process);
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

void logic(t_param *params)
{
	t_processor *temp_proc;

	if (!params)
		return;
	while (params->cycle_to_die > 0)
	{
		temp_proc = params->processors;
		while (temp_proc)
		{
			set_command_for_proc(temp_proc, params);
			execute_process(params->processors, params);
			temp_proc = temp_proc->next;
		}
	}
}

int main()
{
	return (0);
}
