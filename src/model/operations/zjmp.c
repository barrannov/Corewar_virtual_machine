/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 20:32:12 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/06/07 19:48:40 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

void				handle_zjmp(t_param *params, t_processor *proc)
{
	short res;

	if (proc->carry)
	{
		res = (handle_dir(params, proc, 2, 1) % IDX_MOD) % MEM_SIZE;
		proc->pc = (proc->pc + res) % MEM_SIZE;
		if (proc->pc < 0)
			proc->pc = MEM_SIZE + proc->pc;
	}
	else
		proc->pc = (proc->pc + 3) % MEM_SIZE;
}
