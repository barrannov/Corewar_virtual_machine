/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 21:42:54 by abaranov          #+#    #+#             */
/*   Updated: 2017/06/06 21:46:57 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm_header.h"

void				delete_dead_processes(t_processor **str)
{
	t_processor	*prev;
	t_processor	*cur;
	t_processor	*tmp;
	t_processor	*next;
	t_processor	*start;

	cur = (*str);
	while (cur && cur->is_alive == 0)
	{
		tmp = cur;
		cur = cur->next;
		tmp->next = NULL;
		free(tmp);
	}
	start = cur;
	if (amount_lst_el(cur) > 0)
		while (cur->next)
		{
			prev = cur;
			if (cur->next->is_alive == 0)
			{
				next = cur->next->next;
				tmp = cur->next;
				tmp->next = NULL;
				free(tmp);
				cur->next = next;
				prev->next = cur->next;
			}
			else
				cur = cur->next;
		}
	(*str) = start;
}

int					more_then_nbr_lives(t_processor *processor)
{
	t_processor *temp_proc;

	temp_proc = processor;
	while (temp_proc)
	{
		if (temp_proc->is_alive >= NBR_LIVE)
			return (1);
		temp_proc = temp_proc->next;
	}
	return (0);
}

void				handle_check(t_param *param)
{
	delete_dead_processes(&param->processors);
	if (more_then_nbr_lives(param->processors))
	{
		param->cycle_to_die -= CYCLE_DELTA;
		param->amount_checks = 0;
	}
	else
		param->amount_checks++;
	if (param->amount_checks == MAX_CHECKS)
	{
		param->amount_checks = 0;
		param->cycle_to_die -= CYCLE_DELTA;
	}
}
