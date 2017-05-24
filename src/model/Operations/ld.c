#include "../../../includes/vm_header.h"
#include "../../../includes/model.h"

void set_cycles_ld(t_processor *proc)
{
	proc->waite_cycles = 5;
}

void handle_ld(t_param *params, t_processor *proc)
{
	t_val *val;
	unsigned int arg1;
//	int arg2;

	val = malloc(sizeof(t_val));
	proc->prog_counter++;
	get_args(val, params->map, proc);
	proc->prog_counter++;
	if(val->val1 == 2)
	{
		arg1 = handle_direct(params, proc, 4);
		printf("%u\n", arg1);
		//	proc->prog_counter+= 4;
	}
}
