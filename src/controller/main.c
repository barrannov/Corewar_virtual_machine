/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 11:47:44 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/19 21:58:00 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm_header.h"

int		main(int argc, char **argv)
{
	t_player	*player;
	header_t	*header;

	if (!argc || !argv)
		return (0);
	header = malloc(sizeof(header_t));
	player = read_file_vm(header, argv[1]);
	logic(player);
	return (0);
}
