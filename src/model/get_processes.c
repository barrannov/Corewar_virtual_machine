/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_processes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 17:34:21 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/06 21:47:59 by oklymeno         ###   ########.fr       */
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

void add_process(t_param *params, short pc, int numb)
{
	t_processor	*new;
	t_processor *tmp;
//TODO put new proccesses at the top
	new = malloc(sizeof(t_processor) + 1);
	new->pc = pc;
	init_reg(new);
	new->reg[0] = numb;
	new->carry = 0;
	new->waite_cycles = 0;
	new->is_alive = 0;
	new->player = numb;
	new->next = NULL;
	tmp = params->processors;
	if (!params->processors)
		params->processors = new;
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
	int			numb;

	numb = 0;
	tmp = param->players;
	while (tmp)
	{
		add_process(param, tmp->pos, ++numb);
		tmp = tmp->next;
	}
}
