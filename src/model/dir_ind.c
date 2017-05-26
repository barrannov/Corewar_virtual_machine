/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_ind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 17:11:01 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/26 16:43:10 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/vm_header.h"

unsigned int	change_endian(unsigned char *big_ptr, int am_byte)
{
	unsigned int	little;
	unsigned char	*ptr;
	int				i;
	int				j;

	j = am_byte - 1;
	i = 0;
	ptr = malloc(sizeof(unsigned char) * am_byte);
	while (i < am_byte)
	{
		ptr[i] = big_ptr[i];
		j--;
		i++;
	}
	if (am_byte == 4)
		little = (unsigned int)ptr[0] * 16777216 + ptr[1] * 65536 + ptr[2] * 256 + ptr[3];
	else
		little = (unsigned int)ptr[0] * 256 + ptr[1];
	return (little);
}

/*TODO chech how to change return of little endian with more universal solution
 *
 */

unsigned int	handle_dir(t_param *param, t_processor *proc, int am_byte, int pos)
{
	unsigned char	dir[am_byte];
	unsigned int	res;
	int				i;

	i = 0;
	while (i < am_byte)
	{
		dir[i] = param->map[proc->pc + pos + i];
		i++;
	}
	res = change_endian(dir, am_byte);
	return (res);
}

unsigned int handle_ind(t_param *param, t_processor *proc, int pos)
{
	return (handle_dir(param, proc, 2, handle_dir(param, proc, 2, pos)));
}
