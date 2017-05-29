#include "../../../includes/vm_header.h"

void		handle_xor(t_param *params, t_processor *proc)
{
    t_val	*val;
    int		arg1;
    int		arg2;
    int		mv1;
    int		mv2;

    val = malloc(sizeof(t_val));
    get_args(val, params->map, proc);
    mv1 = get_move(val->val1);
    mv2 = get_move(val->val2);
    if (!check_args(val))
        proc->pc++;
    else
    {
        arg1 = get_arg(params, proc, val->val1, 2);
        arg2 = get_arg(params, proc, val->val2, 2 + mv1);
        proc->reg[params->map[proc->pc + 1 + mv1 + mv2]] = arg1 ^ arg2;
        (arg1 ^ arg2) == 0 ? (proc->carry = 1) :
        (proc->carry = 0);
        proc->pc += 4 + mv1 + mv2;
    }
}
