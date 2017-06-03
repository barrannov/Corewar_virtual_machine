/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 20:32:12 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/06/02 23:20:08 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

void	handle_zjmp(t_param *params, t_processor *proc)
{
	if (proc->carry)
		proc->pc += (handle_dir(params, proc, 2, 1) % IDX_MOD) % MEM_SIZE;
	else
		proc->pc = (proc->pc + 3) % MEM_SIZE;
}
