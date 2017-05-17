/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_vm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 18:06:43 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/17 18:08:52 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/controller.h"

void		magic_error(void)
{
	ft_putstr("Error\n");
	exit(1);
}

static char	*get_magic(char *read_m)
{
	char			*tmp;
	char			*tmp_result;
	char			*result;
	unsigned char	byte;
	unsigned long	n;

	n = -1;
	result = NULL;
	tmp = NULL;
	while (++n < sizeof(COREWAR_EXEC_MAGIC))
	{
		byte = read_m[n];
		tmp = ft_itoa_base_cor(byte, 16);
		result != NULL ? (tmp_result = ft_strdup(result)) :
			(tmp_result = NULL);
		free(result);
		tmp_result == NULL ? (result = ft_strdup(tmp)) :
			(result = ft_strjoin(tmp_result, tmp));
		free(tmp);
		free(tmp_result);
	}
	return (result);
}

void		check_magic(int fd)
{
	char	read_m[sizeof(COREWAR_EXEC_MAGIC) + 1];
	int		res;
	char	*magic;

	res = read(fd, &read_m, sizeof(COREWAR_EXEC_MAGIC));
	if (res < 1)
		magic_error();
	magic = get_magic(read_m);
	if (ft_atoi_base(magic, 16) != COREWAR_EXEC_MAGIC)
		magic_error();
}
