/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:29:08 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/29 14:30:11 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

void copy_process_on_the_top(t_param *param, t_processor *proc, unsigned int pc)
{
    t_processor *new;
    int i;

    i = 0;
    new = (t_processor *)malloc(sizeof(t_processor));
    new->carry = proc->carry;
    new->is_alive = 0;
    new->waite_cycles = 0;
    new->pc = pc;
    while (i < 16)
    {
        new->reg[i] = proc->reg[i];
        i++;
    }
    new->next = param->processors;
    param->processors = new;
}

void set_cycles_fork(t_processor *processor)
{
	processor->waite_cycles = 800;
}

void handle_fork(t_param *param, t_processor *processor)
{
    unsigned int	adr;

    adr = processor->pc + handle_dir(param, processor, 2, 1);
    copy_process_on_the_top(param, processor, adr);
}
