/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_vm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:22:42 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/19 19:43:35 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/controller.h"

void	read_error(void)
{
	ft_putstr("Error\n");
	exit(1);
}

unsigned int move_bits(unsigned int num)
{
	unsigned int fs;
	unsigned int s;
	unsigned int t;
	unsigned int fo;

	fs = num >> 24;
	s = (num << 8) >> 24;
	t = (num << 16) >> 24;
	fo = (num << 24) >> 24;
	num = (fo << 24) + (t << 16) + (s << 8) + fs;
	return (num);
}

int		read_file_vm(char *file)
{
	int				fd;
	header_t		*player;
	char 			res[sizeof(header_t)];
	unsigned char	*command;

	fd = open(file, O_RDONLY);
	player = malloc(sizeof(header_t)); 
	read(fd, res, sizeof(header_t));
	player = (header_t *)res;
	player->magic = move_bits(player->magic);
	player->prog_size = move_bits(player->prog_size);
	if (player->magic != COREWAR_EXEC_MAGIC)
		read_error();
	command = malloc(player->prog_size);
	read(fd, command, player->prog_size);
	return (0);
}
