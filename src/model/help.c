/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 22:09:13 by abaranov          #+#    #+#             */
/*   Updated: 2017/06/06 22:17:07 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm_header.h"

void				sort_players(t_param *param)
{
	t_processor	*tmpptr;
	t_processor	*tmpnxt;
	int			tmp;

	tmpptr = param->processors;
	tmpnxt = param->processors->next;
	while (tmpnxt != NULL)
	{
		while (tmpnxt != tmpptr)
		{
			if (tmpnxt->player > tmpptr->player)
			{
				tmp = tmpptr->player;
				tmpptr->player = tmpnxt->player;
				tmpnxt->player = tmp;
			}
			tmpptr = tmpptr->next;
		}
		tmpptr = param->processors;
		tmpnxt = tmpnxt->next;
	}
}

void				get_args(t_val *val, unsigned char *map, t_processor *proc)
{
	val->val1 = (map[proc->pc + 1] & 0xc0) >> 6;
	val->val2 = (map[proc->pc + 1] & 0x30) >> 4;
	val->val3 = (map[proc->pc + 1] & 0x0c) >> 2;
}
