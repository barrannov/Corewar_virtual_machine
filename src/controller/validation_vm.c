/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_vm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:22:42 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/19 21:58:46 by oklymeno         ###   ########.fr       */
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

char			*get_commands(unsigned char *com, unsigned int size)
{
	char			*res;
	char			*all_bases;
	int				t;
	int				n;
	unsigned int	i;

	all_bases = "0123456789abcdef";
	res = malloc(sizeof(char) * size * 2 + 1);
	i = 0;
	n = 0;
	while (i < size)
	{
		t = (int)com[i];
		res[n + 1] = all_bases[t % 16];
		res[n] = all_bases[t / 16 % 16];
		n += 2;
		i++;
	}
	res[n] = '\0';
	return (res);
}

t_player		*get_player(header_t *header, int fd)
{
	t_player		*player;
	unsigned char	*com;

	player = malloc(sizeof(t_player) + 1);
	player->header = header;
	com = malloc(sizeof(header->prog_size));
	read(fd, com, header->prog_size);
	player->commands = get_commands(com, header->prog_size);
	free(com);
	return (player);
}

t_player		*read_file_vm(header_t *header, char *file)
{
	int		fd;
	char	res[sizeof(header_t)];

	fd = open(file, O_RDONLY);
	read(fd, res, sizeof(header_t));
	header = (header_t *)res;
	header->magic = move_bits(header->magic);
	header->prog_size = move_bits(header->prog_size);
	if (header->magic != COREWAR_EXEC_MAGIC)
		print_cant_read_source_file();
	return (get_player(header, fd));
}
