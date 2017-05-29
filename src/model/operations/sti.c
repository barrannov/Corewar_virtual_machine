/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 17:41:23 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/28 18:26:19 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

static void			write_value(t_param *params, t_processor *proc,
		unsigned int r, unsigned int adr)
{
	params->map[adr] = proc->reg[r] >> 24;
	params->map[adr + 1] = (proc->reg[r] << 8) >> 24;
	params->map[adr + 1] = (proc->reg[r] << 16) >> 24;
	params->map[adr + 1] = (proc->reg[r] << 24) >> 24;
}

static unsigned int	arg_1(t_param *params, t_processor *proc, t_val *val)
{
	if (val->val2 == 1)
		return ((unsigned int)proc->reg[proc->pc + 2]);
	else if (val->val2 == 2)
		return (handle_dir(params, proc, 2, 2));
	else
		return (handle_ind(params, proc, 2, 1));
}

static unsigned int	arg_2(t_param *params, t_processor *proc, t_val *val)
{
	char	pos;

	val->val1 == 1 ? (pos = 1) :
		(pos = 2);
	if (val->val3 == 1)
		return ((unsigned int)proc->reg[proc->pc + 2 + pos]);
	else
		return (handle_dir(params, proc, 2, 2 + pos));
}

void		handle_sti(t_param *params, t_processor *proc)
{
	t_val			*val;
	unsigned int	arg1;
	unsigned int	arg2;
	static int		move[2] = {0, 0};
	
	val = malloc(sizeof(t_val));
	get_args(val, params->map, proc);
	val->val1 == 1 ? move[0]++ : (move[0] += 2);
	val->val2 == 1 ? move[1]++ : (move[1] += 2);
//	if (check_args(val))
//	{
		arg1 = arg_1(params, proc, val);
		arg2 = arg_2(params, proc, val);
		write_value(params, proc, proc->reg[params->map[proc->pc + 2]] - 1, arg1 + arg2);
		proc->reg[params->map[proc->pc + 1 + move[0] + move[1]]] == 0 ?
			(proc->carry = 1) :
			(proc->carry = 0);
		proc->pc += 2 + move[0] + move[1];
//	}
//	else
//		proc->pc++;
	printf("here\n");
}

/* TODO Find how to handle first argument in case it will be IND
 *
 */
