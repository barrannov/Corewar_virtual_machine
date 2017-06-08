/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:17:51 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/08 21:36:17 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

static void			free_all(t_param *param)
{
	free(param->processors);
	free(param->map);
	free(param->map_c);
	free(param->players->next->next->header);
	free(param->players->next->next->commands);
	free(param->players->next->next);
	free(param->players->next->header);
	free(param->players->next->commands);
	free(param->players->next);
	free(param->players->header);
	free(param->players->commands);
	free(param->players);
	free(param);
}

void				special_for_denchik(t_param *params, t_fl *flags)
{
	t_processor *temp_proc;

	temp_proc = params->processors;
	while (temp_proc)
	{
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
	while (params->cycle_to_die > 0 && params->amount_proc > 0)
	{
		if (flags->vis == 1)
			visualize(params);
		special_for_denchik(params, flags);
		params->cycle++;
	}
	if (flags->vis == 1)
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
<<<<<<< HEAD
    sort_players(param);
    param->amount_champs = 0;
=======
	param->amount_champs = 0;
	flags->vis == 1 ? (param->print_live = 0) : 
		(param->print_live = 1);
>>>>>>> 2f57ced58183925dfb7559681d61e56fb7b6e2af
	param->cycle_to_die = CYCLE_TO_DIE;
	algorithm(param, flags);
	free_all(param);
}
