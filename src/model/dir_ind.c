# include "../../includes/vm_header.h"

char *bInd_to_litInd(char *big_ptr)
{
	int little;

	char *little_ptr = (char *)&little;

	little_ptr[0] = big_ptr[3];
	little_ptr[1] = big_ptr[2];
	little_ptr[2] = big_ptr[1];
	little_ptr[3] = big_ptr[0];

	return (little_ptr);
}


int handle_direct(t_param *param, t_processor *proc, int am_byte)
{
	char dir[4];
	int res;

	dir[0] = param->map[proc->prog_counter];
	dir[1] = param->map[proc->prog_counter + 1];
	dir[2] = param->map[proc->prog_counter + 2];
	dir[3] = param->map[proc->prog_counter + 3];

	res = (int)bInd_to_litInd(dir);

	return (res);
}

char *handle_direct2(char *test)
{
	char dir[4];
	int res;

	dir[0] = test[0];
	dir[1] = test[1];
	dir[2] = test[2];
	dir[3] = test[3];

	res = (int)bInd_to_litInd(dir);
	return (bInd_to_litInd(dir));
}


int main()
{
	char test[4] = {'a','b', 'c', 'd'};

	printf("%s\n", test);
	printf("\n%s\n", handle_direct2(test));

}
