/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 17:41:23 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/29 18:41:56 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

static void			write_value(t_param *params, t_processor *proc,
		unsigned int r, unsigned int adr)
{
	params->map[adr % MEM_SIZE] = proc->reg[r] >> 24;
	params->map[(adr + 1) % MEM_SIZE] = (proc->reg[r] << 8) >> 24;
	params->map[(adr + 2) % MEM_SIZE] = (proc->reg[r] << 16) >> 24;
	params->map[(adr + 3) % MEM_SIZE] = (proc->reg[r] << 24) >> 24;
}

static unsigned int	arg_1(t_param *params, t_processor *proc, t_val *val)
{
	if (val->val2 == 1)
		return ((unsigned int)proc->reg[(proc->pc + 2) % MEM_SIZE]);
	else if (val->val2 == 2)
		return (handle_dir(params, proc, 2, 2));
	else
		return (handle_ind(params, proc, 2, 1));
}

static unsigned int	arg_2(t_param *params, t_processor *proc, t_val *val)
{
	char	pos;

	val->val2 == 1 ? (pos = 1) :
		(pos = 2);
	if (val->val3 == 1)
		return ((unsigned int)proc->reg[(proc->pc + 2 + pos) % MEM_SIZE]);
	else
		return (handle_dir(params, proc, 2, 2 + pos));
}

void				handle_sti(t_param *params, t_processor *proc)
{
	t_val			*val;
	unsigned int	arg1;
	unsigned int	arg2;
	unsigned int	reg_n;
	static int		move[2] = {0, 0};
	
	val = malloc(sizeof(t_val));
	get_args(val, params->map, proc);
	val->val1 == 1 ? move[0]++ : (move[0] += 2);
	val->val2 == 1 ? move[1]++ : (move[1] += 2);
	reg_n = param->map[(proc->pc + 2) % MEM_SIZE];
	if (check_args(val))
	{
		arg1 = arg_1(params, proc, val);
		arg2 = arg_2(params, proc, val);
		write_value(params, proc, reg_n, arg1 + arg2);
		proc->reg[reg_n] == 0 ? (carry = 1) :
			(carry = 0);
		proc->pc = (proc->pc + 2 + move[0] + move[1]) % MEM_SIZE;
	}
	else
		proc->pc = (proc->pc + 1) % MEM_SIZE;
}
