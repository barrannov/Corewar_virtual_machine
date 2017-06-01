/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 18:43:34 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/01 18:08:12 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

void		handle_xor(t_param *params, t_processor *proc)
{
	t_val	*val;
	int		arg1;
	int		arg2;
	int		mv1;
	int		mv2;

	val = malloc(sizeof(t_val));
	get_args(val, params->map, proc);
	mv1 = get_move_or_xor_and(val->val1);
	mv2 = get_move_or_xor_and(val->val2);
	if (!check_args_or_xor_and(val))
		proc->pc = (proc->pc + 1) % MEM_SIZE;
	else
	{
		arg1 = get_arg_or_xor_and(params, proc, val->val1, 2);
		arg2 = get_arg_or_xor_and(params, proc, val->val2, 2 + mv1);
		proc->reg[params->map[(proc->pc + count_steps(val, 8) - 1)
			% MEM_SIZE] - 1] = arg1 ^ arg2;
		(arg1 ^ arg2) == 0 ? (proc->carry = 1) :
			(proc->carry = 0);
		proc->pc = (proc->pc + count_steps(val, 8)) % MEM_SIZE;
	}
}
