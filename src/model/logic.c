/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:17:51 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/24 17:03:33 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm_header.h"

void logic(t_player *player)
{
	t_processor *temp_proc;

	if (!player)
		return ;
	temp_proc = malloc(sizeof(t_processor));
	int i = -1;
	while (++i < (int)player->header->prog_size)
		printf("%x", player->commands[i]);
	i = -1;
	printf("\n");
	while (++i < (int)player->next->header->prog_size)
		printf("%x", player->next->commands[i]);
//	printf("%s\n", player->next->commands);
//	if (!player)
//		return ;
}
