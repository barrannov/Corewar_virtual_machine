/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 17:16:27 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/29 17:54:28 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/model.h"

void	handle_aff(t_param *params, t_processor *proc)
{
	char	res;
	char	reg;

	reg = params->map[(proc->pc + 1) % MEM_SIZE] - 1;
	if (reg > 0 && reg < 16)
	{
		res = proc->reg[reg] % 256;
		ft_putchar(res);
		proc->pc = (proc->pc + 2) % MEM_SIZE;
	}
	else
		proc->pc = (proc->pc + 1) % MEM_SIZE;
}