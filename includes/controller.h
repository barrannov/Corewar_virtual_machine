/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 19:42:02 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/06 20:07:51 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLER_H
# define CONTROLLER_H

# include "libft.h"
# include "../op.h"
# include "vm_header.h"

int					vm_get_numb(char **argv, int n, int *numb);
int					digit(char *str);

#endif
