/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 18:17:30 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/06 21:11:36 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

void	live_to_chemp(t_player *players, int arg, int play)
{
	t_player	*temp_player;

	temp_player = players;
	while (temp_player)
	{
		if (temp_player->numb == arg)
		{
			temp_player->live = 1;
			temp_player->live_amount++;
			if (play == 1)
				say_live(temp_player->header->prog_name);
		}
		else
			temp_player->live = 0;
		temp_player = temp_player->next;
	}
}

void	handle_live(t_param *params, t_processor *proc, int play)
{
	int	arg;

	arg = handle_dir(params, proc, 4, 1);
	live_to_chemp(params->players, arg, play);
	proc->is_alive++;
	proc->pc = (proc->pc + 5) % MEM_SIZE;
}
