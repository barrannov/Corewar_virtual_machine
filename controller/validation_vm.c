/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_vm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:22:42 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/17 18:09:47 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/controller.h"

int		read_file_vm(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	check_magic(fd);
	return (0);
}
