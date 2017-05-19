/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 19:42:02 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/19 21:36:52 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLER_H
# define CONTROLLER_H

# include "libft.h"
# include "op.h"
# include "vm_header.h"
# include <stdio.h>

//validation functions
t_player		*read_file_vm(header_t *header, char *file);

//TO_DO переделать считывание файла - считаь всё одной строкой, а потом парсить в зависимости от типа данных
#endif
