/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:27:25 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/29 15:08:18 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

static unsigned int	arg_1(t_param *params, t_processor *proc, t_val *val)
{
	if (val->val1 == 1)
		return ((unsigned int)proc->reg[proc->pc + 2]);
	else if (val->val1 == 2)
		return (handle_dir(params, proc, 2, 2));
	else
		return (handle_ind(params, proc, 2, 0));
}

static unsigned int	arg_2(t_param *params, t_processor *proc, t_val *val)
{
	char	pos;

	val->val1 == 1 ? (pos = 1) :
		(pos = 2);
	if (val->val2 == 1)
		return ((unsigned int)proc->reg[proc->pc + 2 + pos]);
	else
		return (handle_dir(params, proc, 2, 2 + pos));
}

void		handle_ldi(t_param *params, t_processor *proc)
{
	t_val			*val;
	unsigned int	arg1;
	unsigned int	arg2;
	static int		move[2] = {0, 0};
	
	val = malloc(sizeof(t_val));
	get_args(val, params->map, proc);
	val->val1 == 1 ? move[0]++ : (move[0] += 2);
	val->val2 == 1 ? move[1]++ : (move[1] += 2);
	if (check_args(val))
	{
		arg1 = arg_1(params, proc, val);
		arg2 = arg_2(params, proc, val);
		proc->reg[params->map[proc->pc + 1 + move[0] + move[1]] - 1] = 
			handle_dir(params, proc, REG_SIZE, (proc->pc + ((arg1 + arg2) %
			IDX_MOD)));
		proc->reg[params->map[proc->pc + 1 + move[0] + move[1]] - 1] == 0 ?
		   (proc->carry = 1) :
		   (proc->carry = 0);
		proc->pc += 2 + move[0] + move[1];
	}
	else
		proc->pc++;
}
