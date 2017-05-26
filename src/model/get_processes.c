/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_processes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 17:34:21 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/26 15:43:46 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm_header.h"

void	init_reg(t_processor *proc)
{
	int i;

	i = -1;
	while (++i < REG_NUMBER)
		proc->reg[i] = 0;
}

void	add_process(t_player *player, int pc)
{
	t_processor	*new;
	t_processor *tmp;

	new = malloc(sizeof(t_processor) + 1);
	new->pc = pc;
	init_reg(new);
	new->reg[0] = player->numb;
	new->carry = 0;
	new->waite_cycles = 0;
	new->next = NULL;
	tmp = player->processors;
	if (!player->processors)
		player->processors = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	get_processes(t_param *param)
{
	t_player	*tmp;

	tmp = param->players;
	while (tmp)
	{
		add_process(tmp, 0);
		tmp = tmp->next;
	}
}
