#include "../../includes/vm_header.h"

void add_to_map(t_player *players, t_param *params, int pc)
{
	int i;

	i = 0;
	while (players->commands[i])
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
/// /void add_to_map(int pc, )

void create_map(t_player *players, t_param *params)
{
	t_player *temp_players;
	int pc;

	pc = 0;
	temp_players = players;
	params->map = ft_strnew(MEM_SIZE);
	add_null(params->map);
	while(temp_players)
	{
		//TODO  add pc to players process
		add_to_map(players, params, pc);
		temp_players = temp_players->next;
		pc += CHAMP_MAX_SIZE;
	}
}
