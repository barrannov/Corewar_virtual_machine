/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 20:32:12 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/06/07 20:33:22 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

<<<<<<< HEAD
void	handle_zjmp(t_param *params, t_processor *proc)
{
	short	res;
=======
void				handle_zjmp(t_param *params, t_processor *proc)
{
	short res;
>>>>>>> fbeaa32599e452e5efc4a9e78cef86257b88da6b

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
