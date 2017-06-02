#include "../../includes/model.h"

void deleteFirst(t_processor **list) {
    t_processor *temp = *list;
    if (*list != NULL) {
        *list = (*list)->next;
        free(temp);
    }
}


void delete_dead_processes2(t_param **param) {

    // if(!head || !(*head)) return ;
    t_processor *tmp = (*param)->processors;
    t_processor *del;
    //    t_processor *current = (*param)->processors->next;

    if (tmp->is_alive == 0) {
        (*param)->processors = (*param)->processors->next;
        //free(tmp);
    }
    while (tmp->next) {
        if (!tmp->next->is_alive)
        {
            del = tmp->next;
            tmp->next = tmp->next->next;
            free(del);
        }
        tmp = tmp->next;
//        if (current->is_alive == 0) {
//            tmp = current;
//            previous->next = current->next;
//            free(tmp);
//            current = previous->next;
//        }
//        else
//        {
//            previous = current;
//            current = current->next;
//        }
    }

}

void	delete_dead_processes(t_processor **str)
{
    t_processor	*prev;
    t_processor	*cur = (*str);
    t_processor	*tmp;
    t_processor	*next;
    t_processor	*start;

    while (cur && cur->is_alive == 0)
    {
        tmp = cur;
        cur = cur->next;
        tmp->next = NULL;
        free(tmp);
    }
    start = cur;
    if(amount_lst_el(cur) > 0)
    while (cur->next)
    {
        prev = cur;
        if (cur->next->is_alive == 0)
        {
            next = cur->next->next;
            tmp = cur->next;
            tmp->next = NULL;
            free(tmp);
            cur->next = next;
            prev->next = cur->next;
        }
        else
            cur = cur->next;
    }
    (*str) = start;
}

int more_then_nbr_lives(t_processor *processor) {
    t_processor *temp_proc;

    temp_proc = processor;
    while (temp_proc) {
        if (processor->is_alive >= NBR_LIVE)
            return (1);
        temp_proc = temp_proc->next;
    }
    return (0);
}

void handle_check(t_param *param) {
    delete_dead_processes(&param->processors);
    if (more_then_nbr_lives(param->processors)) {
        //TODO ? all processec must to say more then 21
        param->cycle_to_die -= CYCLE_DELTA;
        param->amount_checks = 0;
    } else
        param->amount_checks++;
    if (param->amount_checks == MAX_CHECKS) {
        param->amount_checks = 0;
        param->cycle_to_die -= CYCLE_DELTA;
    }
}
