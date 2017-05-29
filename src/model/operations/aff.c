/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 17:16:27 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/29 17:19:56 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm_header.h"

void	handle_aff(t_param *params, t_processor *proc)
{
	char res;

	res = proc->reg[params->map[proc->pc + 1] - 1] % 256;
	ft_putchar(res);
}
