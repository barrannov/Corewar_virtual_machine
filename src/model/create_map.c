/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 17:29:15 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/26 15:42:10 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm_header.h"

void add_to_map(t_player *players, t_param *params, int pc)
{
	int i;

	i = 0;
	while (i < (int)players->header->prog_size)
	{
		params->map[pc] = players->commands[i];
		pc++;
		i++;
	}
}

void add_null(char *map)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		map[i] = '0';
		i++;
	}
}
//void add_to_map(int pc, )

void create_map(t_player *players, t_param *param)
{
	t_player *temp_players;
	int pc;


	pc = 0;
	temp_players = players;
	param->players = players;
	param->map = (unsigned char *)ft_strnew(MEM_SIZE);
	//add_null(param->map);
	while (temp_players)
	{
		//TODO  add pc to players process
		add_to_map(players, param, pc);
		temp_players = temp_players->next;
		pc += MEM_SIZE / param->amount_champs;
	}
	int i = -1;
//	while (++i < MEM_SIZE)
//	{
//		if (i % 64 == 0)
//		{
//			printf("\n");
//			printf("row # ");
//		}
//		if (param->map[i] == 0)
//			printf("%.2x ",param->map[i]);
//		else
//			printf("\033[32;1m%.2x\033[0m ", param->map[i]);
//	}
}
