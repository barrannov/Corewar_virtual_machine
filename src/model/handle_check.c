/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 21:42:54 by abaranov          #+#    #+#             */
/*   Updated: 2017/06/08 19:41:33 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm_header.h"

void deletefirst (t_processor **head) {
	t_processor *tmp = *head;            // save old head for freeing.
	if (tmp == NULL) return;             // list empty? then do nothing.
	*head = tmp->next;                   // advance head to second node.
	free (tmp);                          // free old head.
}

static void			delete_first(t_processor **str)
{
//	printf("before %d\n", amount_lst_el(*str));
	while (*str && (*str)->is_alive == 0)
	{
		deletefirst(str);
	}
	//printf("after %d\n", amount_lst_el(*str));
}

static void			free_tmp(t_processor *tmp)
{
	tmp->next = NULL;
	free(tmp);
}

void				delete_dead_processes(t_processor **str)
{
	t_processor	*prev;
	t_processor	*cur;
	t_processor	*tmp;
	t_processor	*next;
	t_processor	*start;

	cur = (*str);
	delete_first(&cur);
	start = cur;
	if (cur && cur->next)
		while (cur->next)
		{
			prev = cur;
			if (cur->next->is_alive == 0)
			{
				next = cur->next->next;
				tmp = cur->next;
				free_tmp(tmp);
				cur->next = next;
				prev->next = cur->next;
			}
			else
				cur = cur->next;
		}
	(*str) = start;
}

int					more_then_nbr_lives_players(t_player *player)
{
    t_player *temp_play;

    temp_play = player;
    while (temp_play)
    {
        if (temp_play->live_amount >= NBR_LIVE)
            return (1);
        temp_play = temp_play->next;
    }
    return (0);
}
//int					more_then_nbr_lives(t_processor *processor)
//{
//	t_processor *temp_proc;
//
//	temp_proc = processor;
//	while (temp_proc)
//	{
//		if (temp_proc->is_alive >= NBR_LIVE)
//			return (1);
//		temp_proc = temp_proc->next;
//	}
//	return (0);
//}

void				handle_check(t_param *param)
{
	delete_dead_processes(&param->processors);
//    ft_putstr("cycle: ");
//	ft_putnbr(param->cycle);
//	ft_putchar('\n');
//    ft_putstr("amount: ");
//	ft_putnbr(param->amount_proc);
//	ft_putchar('\n');
	param->amount_proc = amount_lst_el(param->processors);
	if (more_then_nbr_lives_players(param->players))
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
