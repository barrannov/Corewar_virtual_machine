/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:20:57 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/29 14:25:43 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

void	load_value(t_param *param, t_processor *proc, unsigned int value)
{
    if (param->map[proc->pc + 6] > 0 && param->map[proc->pc + 6] < REG_NUMBER)
    {
        value == 0 ? (proc->carry = 1) :
			(proc->carry = 0);
        proc->reg[param->map[proc->pc + 6] - 1] = value;
        proc->pc += 7;
    }
    else
        proc->pc++;
}

void	handle_ld(t_param *params, t_processor *proc)
{
    t_val			*val;
    unsigned int	arg;

    val = malloc(sizeof(t_val));
    get_args(val, params->map, proc);
    if (val->val1 == 2)
        arg = handle_dir(params, proc, 4, 2);
    else if (val->val1 == 3)
        arg = handle_ind(params, proc, 2, 0);
    else
    {
        proc->pc++;
        return ;
    }
    load_value(params, proc, arg);
    print_reg(proc);
}
