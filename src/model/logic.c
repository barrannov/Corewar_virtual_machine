/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:17:51 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/22 22:10:26 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm_header.h"

void logic(t_player *player)
{
	if (!player)
		vm_print_usage();
	else
	{
		printf("%s\n", player->header->prog_name);
		printf("%s\n", player->next->header->prog_name);
		printf("%d\n", player->numb);
		printf("%d\n", player->next->numb);
		printf("%d\n", player->next->next->numb);
	}
	if (!player)
		return ;
}
