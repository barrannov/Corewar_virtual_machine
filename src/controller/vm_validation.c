/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:32:31 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/01 17:55:19 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm_header.h"

unsigned int	move_bits(unsigned int num)
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

static t_player	*get_player(header_t *header, int fd, int numb)
{
	t_player		*player;
	unsigned char	*com;

	player = malloc(sizeof(t_player) + 1);
	player->header = header;
	com = malloc(header->prog_size);
	read(fd, com, header->prog_size);
	player->commands = com;
	player->numb = numb;
	player->next = NULL;
	return (player);
}

t_player		*read_file_vm(char *file, int numb)
{
	int			fd;
	char		*res;
	header_t	*header;

	res = malloc(sizeof(char *) * sizeof(header_t));
	fd = open(file, O_RDONLY);
	read(fd, res, sizeof(header_t));
	header = (header_t *)res;
	header->magic = move_bits(header->magic);
	header->prog_size = move_bits(header->prog_size);
	if (header->magic != COREWAR_EXEC_MAGIC)
		print_cant_read_source_file(file);
	return (get_player(header, fd, numb));
}
