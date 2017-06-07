/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:21:49 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/02 17:53:59 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIRTUAL_MACHINE_VIEW_H
# define VIRTUAL_MACHINE_VIEW_H

# define MAX_UINT = 4294967295

#include "vm_header.h"

void	print_cant_read_source_file(char *name);
void	vm_print_usage(void);
void	dump_error(void);
void	say_live(char *name);
void	print_map(unsigned char *map);
char	*ft_itoa_base(int value, int base);

#endif //VIRTUAL_MACHINE_VIEW_H
