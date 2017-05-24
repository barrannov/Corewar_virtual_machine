#include "../../../includes/vm_header.h"

void set_cycles_ld(t_processor *proc)
{
	proc->waite_cycles = 5;
}

void handle_ld(t_param *params, t_processor *proc)
{
	t_val *val;

	proc->prog_counter++;
	get_args(val, params->map, proc);
	proc->prog_counter++;
	if(val->val1 == 10)
	{

	}
}