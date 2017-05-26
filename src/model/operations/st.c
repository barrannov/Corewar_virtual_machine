/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 19:35:08 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/25 22:28:58 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

void	write_value(t_param *params, t_processor *proc, unsigned int r)
{
	unsigned int	adr;

	adr = proc->pc + (handle_indirect(params, proc, 3) % IDX_MOD);
	params->map[adr] = proc->reg[r] >> 24;
	params->map[adr + 1] = (proc->reg[r] << 8) >> 24;
	params->map[adr + 2] = (proc->reg[r] << 16) >> 24;
	params->map[adr + 3] = (proc->reg[r] << 24) >> 24;
}

void	handle_st(t_param *params, t_processor *proc)
{
	t_val			*val;
	unsigned int	r1;
	unsigned int	r2;

	val = malloc(sizeof(t_val));
	get_args(val, params->map, proc);
	r1 = params->map[proc->pc + 2] - 1;
	r2 = params->map[proc->pc + 3] - 1;
	if (val->val2 == 1 && r1 > 0 && r1 < REG_NUMBER && r2 > 0 && r2 < REG_NUMBER)
	{
		proc->reg[params->map[r2]] = proc->reg[r1];
		proc->pc += 4;
	}
	else if (val->val2 == 3)
	{
		write_value(params, proc, r1);
		proc->pc += 5;
	}
	else
	{
		proc->pc++;
		return ;
	}
}