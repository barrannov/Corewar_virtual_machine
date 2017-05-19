/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_vm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:22:42 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/19 18:31:12 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/controller.h"

void	read_error(void)
{
	ft_putstr("Error\n");
	exit(1);
}

void	get_player_name(header_t *player, int fd)
{
	int		res;
	char	name[PROG_NAME_LENGTH];
	int		n;

	n = -1;
	res = read(fd, &name, PROG_NAME_LENGTH);
	lseek(fd, PROG_NAME_LENGTH - sizeof(name) + 4, SEEK_CUR);
	while (++n < PROG_NAME_LENGTH)
		player->prog_name[n] = name[n];

}

void	get_memory(header_t *player, int fd)
{
	char	res[sizeof(player->prog_size)];
	int		n;
	unsigned char ch;
	n = read(fd, &res, sizeof(player->prog_size));
	if (n < 1)
		read_error();
	ch = res[0];
	write(1, &ch, 1);
	ch = res[1];
	write(1, &ch, 1);
	ch = res[2];
	write(1, &ch, 1);
	ch = res[3];
	write(1, &ch, 1);
//	player->prog_size = ft_atoi(get_string_from_byte(res));
//	ft_putnbr(player->prog_size);
}

#include <stdio.h>
int		read_file_vm(char *file)
{
	int			fd;
	header_t	*player;
	char 		res[sizeof(header_t)];
//	char		*command;

	fd = open(file, O_RDONLY);
//	check_magic(fd);
	player = malloc(sizeof(header_t)); 
	read(fd, res, sizeof(header_t));
	player = (header_t *)res;
	printf("%zu\n", sizeof(header_t));
	unsigned char *command;
	command = malloc(1024);
	read(fd, command, 1023);
	unsigned int i = 0;

	while (i < 1023)
	{
		printf("%x ", command[i]);
		i++;
	}
	return (0);
}
