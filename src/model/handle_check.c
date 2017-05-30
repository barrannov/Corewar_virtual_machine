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

void delete_dead_processes(t_processor **head)
{
    if(!head || !(*head)) return ;
    t_processor * tmp = *head;
    t_processor * listToDel;

    if(tmp->is_alive == 0)
    {
        *head = (*head)->next;
        free(tmp);
    }
    while(tmp->next)
    {
        if(tmp->next->is_alive == 0)
        {
            listToDel = tmp->next;
            tmp->next = tmp->next->next;
            free(listToDel);
            if(!tmp->next)
                break;
        }
        tmp = tmp->next;
    }
}


int more_then_nbr_lives(t_player *player) {
    t_player *temp_play;
    int am;

    am = 0;
    temp_play = player;
    while (temp_play) {
        if (player->live_amount >= NBR_LIVE)
            am++;
         temp_play = temp_play->next;
    }
    return (0);
}

void handle_check(t_param *param) {
    delete_dead_processes(&param->processors);
    if (more_then_nbr_lives(param->players))
    {
        //TODO ? all processec must to say more then 21
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
