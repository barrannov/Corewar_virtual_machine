/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:04:13 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/17 20:10:54 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLER_H
# define CONTROLLER_H

# include "libft.h"
# include "op.h"

//validation functions
void	check_magic(int magic);
int		read_file_vm(char *file);
char	*ft_itoa_base_cor(int value, int base);
char	*get_string_from_byte(char *string);

//TO_DO переделать считывание файла - считаь всё одной строкой, а потом парсить в зависимости от типа данных
#endif
