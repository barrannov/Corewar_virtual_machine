/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 15:48:51 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/25 21:46:13 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"
#include "../../../includes/model.h"

void	set_cycles_ld(t_processor *proc)
{
	proc->waite_cycles = 5;
}

void	print_reg(t_processor *proc)// for testing, delete it
{
	int i;

	i = -1;
	while (++i < REG_NUMBER)
		printf("reg %d = %d\n", i + 1, proc->reg[i]);
}

void	load_value(t_param *param, t_processor *proc, unsigned int value)
{
	if (param->map[proc->prog_counter] > 0 && param->map[proc->prog_counter] < REG_NUMBER)
	{
		if (value == 0)
			proc->carry = 1;
		proc->reg[param->map[proc->prog_counter] - 1] = value;
	}
	proc->prog_counter++;
}

void	handle_ld(t_param *params, t_processor *proc)
{
	t_val			*val;
	unsigned int	arg;

	val = malloc(sizeof(t_val));
	proc->prog_counter++;
	get_args(val, params->map, proc);
	if (val->val1 == 2)
		arg = handle_direct(params, proc, 4);
	else if (val->val1 == 3)
		arg = handle_indirect(params, proc, 2);
	else
	{
		proc->prog_counter++;
		return ;
	}
	load_value(params, proc, arg);
	print_reg(proc);
}
