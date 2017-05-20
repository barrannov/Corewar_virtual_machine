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


void execute_process(t_processor *process)
{
/*
 * At the beginning we are checking waite_cycles, if waite_cycles > 0, it means that process needs to wait this cycles
 * if waite_cycles == 0, it means that the machine is ready to execute command
 * */
	if (process->waite_cycles > 0)
	{
		process->waite_cycles--;
		return ;
	}
	/*execute command here
	 * */
}

void execute_champ(t_player *player)
{
	t_processor *temp_process;

	temp_process = player->processors;
	while (temp_process)
	{
		execute_process(temp_process);
		temp_process = temp_process->next;
	}
}

void logic(t_param *params)
{
	t_player *temp_chemp;

	if (!params)
		return;
	while (params->cycle_to_die > 0)
	{
		temp_chemp = params->player;
		while (temp_chemp)
		{
			execute_champ(temp_chemp);
			temp_chemp = temp_chemp->next;
		}

	}
}

int main()
{
	return (0);
}
