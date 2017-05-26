#include "../../../includes/vm_header.h"

void set_cycles_live(t_processor *proc)
{
	proc->waite_cycles = 10;
}

void live_to_chemp(t_player *players, int arg)
{
    t_player *temp_player;

    temp_player = players;
    while (temp_player)
    {
        if (temp_player->numb == arg)
            temp_player->live = 1;
        else
            temp_player->live = 0;
        temp_player = temp_player->next;
    }
}

void handle_live(t_param *params, t_processor *proc)
{
    int arg;

    arg = handle_dir(params, proc, 4, 1);
    live_to_chemp(params->players, arg);
    proc->is_alive = 1;
    proc->pc += 4;
}