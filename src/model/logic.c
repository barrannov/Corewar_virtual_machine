/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:17:51 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/26 15:47:01 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm_header.h"

void execute_command(t_processor *process, t_param *param) {
    //	if ( process->waite_cycles!= 0)
    //		return;
//	if (process->prog_counter == 0) //delete it
//		process->prog_counter = 3;
    if (param->map[process->pc] == 1)
        handle_live(param, process);
    else if (param->map[process->pc] == 2)
        handle_ld(param, process);
    else if (param->map[process->pc] == 3)
        handle_st(param, process);
    else if (param->map[process->pc] == 4)
        handle_add(param, process);
    else if (param->map[process->pc] == 5)
        handle_sub(param, process);

}

void set_command_for_proc(t_processor *process, t_param *param) {
    if (process->waite_cycles != 0)
        return;
    if (param->map[process->pc] == 1)
        set_cycles_live(process);
    if (param->map[process->pc] == 2)
        set_cycles_ld(process);
    if (param->map[process->pc] == 3)
        set_cycles_fork(process);
}

void execute_process(t_processor *process, t_param *param) {
/*
 * At the beginning we are checking waite_cycles, if waite_cycles > 0, it means that process needs to wait this cycles
 * if waite_cycles == 0, it means that the machine is ready to execute command
 * */
    if (process->waite_cycles > 0) {
        process->waite_cycles--;
        if (process->waite_cycles > 0)
            return;
    }
    execute_command(process, param);
    /*execute command here
     * */
}

int count_champs(t_player *players) {
    int res;
    t_player *tmp;

    res = 0;
    tmp = players;
    while (tmp) {
        res++;
        tmp = tmp->next;
    }
    return (res);
}

void print_map(t_param *param)//this func must be in view
{
    int i;

    i = -1;
    while (++i < MEM_SIZE) {
        if (i % 64 == 0) {
            printf("\n");
            printf("row # ");
        }
        if (param->map[i] == 0)
            printf("%.2x ", (unsigned char) param->map[i]);
        else
            printf("\033[32;1m%.2x\033[0m ", (unsigned char) param->map[i]);
    }
    printf("\n");

}

void unset_live_players(t_player *players) {
    t_player *live_players;

    live_players = players;
    while (live_players) {
        live_players->live = 0;
        live_players = live_players->next;
    }
}

void unset_is_alive_process(t_processor *proc) {
    t_processor *live_proc;

    live_proc = proc;
    while (live_proc) {
        live_proc->is_alive = 0;
        live_proc = live_proc->next;
    }

}

void algorithm(t_param *params) {
    int cycles;

    cycles = 0;
    t_processor *temp_proc;
    while (params->cycle_to_die > 0) {
        temp_proc = params->processors;
        while (temp_proc) {
            set_command_for_proc(temp_proc, params);
            execute_process(params->processors, params);
            temp_proc = temp_proc->next;
        }
        if (cycles % params->cycle_to_die == 0) {
            handle_check(params);
            unset_is_alive_process(params->processors);
        }
    }
}

void logic(t_player *players) {
    t_param *param;

    param = malloc(sizeof(t_param));
    param->processors = NULL;
    param->amount_champs = count_champs(players);
    create_map(players, param);
    get_processes(param);
    param->cycle_to_die = CYCLE_TO_DIE;
    print_map(param);
    execute_command(param->processors, param);

    algorithm(param); //start of algorithm

    printf("step 2\n");
//	execute_command(param->players->processors, param);
    print_map(param);

}