/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 00:14:37 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/03 00:17:39 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm_header.h"

void        print_status(t_param *param, WINDOW *status)
{
	wprintw(status, "cycle = %d\n", param->cycle);
	wprintw(status, "cycle_to_die = %d", param->cycle_to_die);
	wrefresh(status);
}
