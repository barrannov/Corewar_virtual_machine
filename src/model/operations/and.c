/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:47:37 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/29 17:55:32 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

int	check_args(t_val *val)
{
	if (val->val1 != 1 && val->val1 != 2 && val->val1 != 3)
		return (0);
	if (val->val2 != 1 && val->val2 != 2 && val->val2 != 3)
		return (0);
	if (val->val3 != 1)
		return (0);
	return (1);
}

int	get_arg(t_param *params, t_processor *proc, char val, int pos)
{
	if (val == 1)
		return (proc->reg[params->map[(proc->pc + pos) % MEM_SIZE] - 1]);
	else if (val == 2)
		return ((int)handle_dir(params, proc, 4, pos));
	else if (val == 3)
		return ((int)handle_ind(params, proc, pos, 1));
	else
		return (0);
}

int			get_move(char val)
{
	if (val == 1)
		return (1);
	else if (val == 2)
		return (2);
	else if (val == 3)
		return (4);
	else
		return (0);
}

void		handle_and(t_param *params, t_processor *proc)
{
	t_val	*val;
	int		arg1;
	int		arg2;
	int		mv1;
	int		mv2;

	val = malloc(sizeof(t_val));
	get_args(val, params->map, proc);
	mv1 = get_move(val->val1);
	mv2 = get_move(val->val2);
	if (!check_args(val))
		proc->pc = (proc->pc + 1) % MEM_SIZE;
	else
	{
		arg1 = get_arg(params, proc, val->val1, 2);
		arg2 = get_arg(params, proc, val->val2, 2 + mv1);
		proc->reg[params->map[(proc->pc + 1 + mv1 + mv2) % MEM_SIZE]] = arg1 & arg2;
		(arg1 & arg2) == 0 ? (proc->carry = 1) :
			(proc->carry = 0);
		proc->pc = (proc->pc + 4 + mv1 + mv2) % MEM_SIZE;
	}
}
