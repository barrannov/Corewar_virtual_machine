/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 22:55:06 by abaranov          #+#    #+#             */
/*   Updated: 2017/06/07 20:10:48 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

void				execute_process(t_processor *process, t_param *param)
{
	if (process->waite_cycles > 0)
	{
		process->waite_cycles--;
		if (process->waite_cycles > 0)
			return ;
	}
	execute_command(process, param);
}

int					count_champs(t_player *players)
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
