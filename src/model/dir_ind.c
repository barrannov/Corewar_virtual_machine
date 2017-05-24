# include "../../includes/vm_header.h"

unsigned int	bInd_to_litInd(unsigned char *big_ptr, int am_byte)
{
	unsigned int little;
	int i;
	int j;

	j = am_byte - 1;
	i = 0;
	unsigned char *little_ptr = malloc(sizeof(unsigned char) * am_byte);
	while (i < am_byte)
	{
		little_ptr[i] = big_ptr[i];
		j--;
		i++;
	}
	little = (unsigned int)little_ptr[0] * 16777216 + (unsigned int)little_ptr[1] * 65536 + (unsigned int)little_ptr[2] * 256 + (unsigned int)little_ptr[3];
	return (little);
}

/*TODO chech how to change return of little endian with more universal solution
 *
 */

unsigned int handle_direct(t_param *param, t_processor *proc, int am_byte)
{
	unsigned char dir[am_byte];
	unsigned int res;
	int i;

	i = 0;
	while (i < am_byte)
	{
		dir[i] = (unsigned char)param->map[proc->prog_counter + i];
		i++;
	}
	res = bInd_to_litInd(dir, am_byte);
	return (res);
}
