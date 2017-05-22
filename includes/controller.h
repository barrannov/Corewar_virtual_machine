/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 19:42:02 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/22 20:00:25 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLER_H
# define CONTROLLER_H

# include "libft.h"
# include "op.h"
# include "vm_header.h"
# include <stdio.h> //delete it

//validation functions
//t_player		*read_file_vm(header_t *header, char *file);
int		vm_get_numb(char **argv,  int n,  int *numb);
int		digit(char *str);

#endif
