/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_ind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 17:11:01 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/01 12:31:54 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/vm_header.h"
static unsigned int	get_res_from_hex(unsigned char *ptr, int am_byte)
{
	unsigned int	result;

	if (am_byte == 4)
		result = (unsigned int)ptr[0] * 0x1000000 + ptr[1] * 0x10000 + ptr[2] *
			0x100 + ptr[3];
	else
		result = (unsigned int)ptr[0] * 0x100 + ptr[1];
	return (result);
}

/* This function takes sting (4 chars), which contain 4 bytes in hex, and
 * transforms this string to unsigned int.  
 */
unsigned int		handle_dir(t_param *param, t_processor *proc,
		short int am_byte, short int pos)
{
	unsigned char	dir[am_byte];
	int				res;
	int				i;

	i = 0;
	while (i < am_byte)
	{
		dir[i] = param->map[(proc->pc + pos + i) % MEM_SIZE];
		i++;
	}
	res = get_res_from_hex(dir, am_byte);
	if (am_byte == 2)
		return ((short)res);
	else
		return ((int)res);
}
/* Function read "am_byte" bytes from memory at adress "pc + pos"
 * if we need to read 2 bytes, it returns short value, in case with 4
 * bytes - returns int
 */

unsigned int		handle_ind(t_param *param, t_processor *proc, int pos,
		char idx, char label)
{
	if (idx == 0)
		return (handle_dir(param, proc, (short)label,
					handle_dir(param, proc, 2, pos)));
	else
		return (handle_dir(param, proc, (short)label,
					handle_dir(param, proc, 2, pos) % IDX_MOD));
}
/* Hande ind:
 * pos is position, where starts first indirect element.
 * idx - flag to see where we need to use %IDX_MOD
 * label - flag shows what size of memory need to read)
 *
 * function read "label" bytes from memory part, that we get whom result
 * 			of handle dir function
 */
