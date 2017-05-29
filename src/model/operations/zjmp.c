/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 20:32:12 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/05/29 20:33:20 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

static short	get_swap_short_value(unsigned char *number_ptr)
{
    short   		value;
    unsigned char	*value_ptr;
    unsigned char	tmp;

    ft_memmove((char*)&value, number_ptr, 2);
    value_ptr = (char*)&value;
    tmp = value_ptr[0];
    value_ptr[0] = value_ptr[1];
    value_ptr[1] = tmp;
    return (value);
}
void	handle_zjmp(t_param *par, t_processor *proc) {
    short value;

    value = get_swap_short_value(&par->map[proc->pc + 1]);
    if (proc->carry)
        proc->pc += (value % IDX_MOD);
    else
        proc->pc += 3;
}