# include "../../includes/vm_header.h"

char *bInd_to_litInd(char *big_ptr, int am_byte)
{
	int little;
	int i;
	int j;

	j = am_byte - 1;
	i = 0;
	char *little_ptr = (char *) &little;
	while (i < am_byte)
	{
		little_ptr[i] = big_ptr[j];
		j--;
		i++;
	}
	return (little_ptr);
}

int handle_direct(t_param *param, t_processor *proc, int am_byte)
{
	char dir[4];
	int res;
	int i;

	i = 0;
	while (i < am_byte)
	{
		dir[i] = param->map[proc->prog_counter + i];
		i++;
	}

	res = (int) bInd_to_litInd(dir, am_byte);
	return (res);
}
