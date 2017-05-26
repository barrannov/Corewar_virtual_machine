/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:50:05 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/26 17:03:52 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

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
    if (param->map[proc->pc + 6] > 0 && param->map[proc->pc + 6] < REG_NUMBER)
    {
        value == 0 ? (proc->carry = 1) : (proc->carry = 0);
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
        arg = handle_ind(params, proc, 2);
    else
    {
        proc->pc++;
        return ;
    }
    load_value(params, proc, arg);
    print_reg(proc);
}
