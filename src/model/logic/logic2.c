/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 22:55:06 by abaranov          #+#    #+#             */
/*   Updated: 2017/06/06 22:59:44 by abaranov         ###   ########.fr       */
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

//void				print_map(t_param *param)
//{
//	int i;
//
//	i = -1;
//	while (++i < MEM_SIZE)
//	{
//		if (i % 64 == 0)
//		{
//			printf("\n");
//			printf("row # ");
//		}
//		if (param->map[i] == 0)
//			printf("%.2x ", param->map[i]);
//		else
//			printf("\033[32;1m%.2x\033[0m ", param->map[i]);
//	}
//	printf("\n");
//}
