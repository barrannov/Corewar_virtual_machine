#include "../../includes/model.h"

void deleteFirst(t_processor** list)
{
    t_processor* temp = *list;
    if (*list != NULL)
    {
        *list = (*list)->next;
        free(temp);
    }
}

void delete_dead_processes(t_processor *processes) {
    //TODO func deleats all nodes with 'is_alive = 0'
    t_processor *temp_proc;
    t_processor *next;
    t_processor *before;

    if(processes->is_alive == 0)
        deleteFirst(&processes);
    temp_proc = processes;
    while (temp_proc->next)
    {
        if (temp_proc->next->is_alive == 0) {
            before = temp_proc->next;
            next = before->next;
            free(before);
            temp_proc = next;
        }
        else
            temp_proc = temp_proc->next;
    }
}

int amount_lives_player(t_player *player) {
    t_player *temp_play;

    temp_play = player;
    while (temp_play) {
        if (player->live_amount >= NBR_LIVE)
            return (1);
        temp_play = temp_play->next;
    }
    return (0);
}

void handle_check(t_param *param) {
    delete_dead_processes(param->processors);
    if (amount_lives_player(param->players))
    {
        param->cycle_to_die -= CYCLE_DELTA;
        param->amount_checks = 0;
    }
    else
        param->amount_checks++;
    if(param->amount_checks == MAX_CHECKS + 1)
    {
        param->amount_checks = 0;
        param->cycle_to_die -= CYCLE_DELTA;
    }
}
