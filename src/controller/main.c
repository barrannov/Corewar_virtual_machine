/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 11:47:44 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/19 22:14:13 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/controller.h"

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
