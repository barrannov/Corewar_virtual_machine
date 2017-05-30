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

int amount_lst_el_players(t_player *player)
{
    int i;

    i = 0;
    while (player)
    {
        i++;
        player = player->next;
    }
    return (i);
}

int amount_lst_el(t_processor *procs)
{
    int i;

    i = 0;
    while (procs)
    {
        i++;
        procs = procs->next;
    }
    return (i);
}

void execute_command(t_processor *process, t_param *param) {
    if (process->waite_cycles != 0)
        return;
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
    else if (param->map[process->pc] == 6)
        handle_and(param, process);
    else if (param->map[process->pc] == 7)
        handle_or(param, process);
    else if (param->map[process->pc] == 8)
        handle_xor(param, process);
    else if (param->map[process->pc] == 9)
        handle_zjmp(param, process);
    else if (param->map[process->pc] == 10)
        handle_ldi(param, process);
    else if (param->map[process->pc] == 11)
        handle_sti(param, process);
    else if (param->map[process->pc] == 12)
        handle_fork(param, process);
    else if (param->map[process->pc] == 13)
        handle_lld(param, process);
    else if (param->map[process->pc] == 14)
        handle_lldi(param, process);
    else if (param->map[process->pc] == 15)
        handle_lfork(param, process);
    else if (param->map[process->pc] == 16)
        handle_aff(param, process);
}

void set_command_for_proc(t_processor *process, t_param *param) {
    if (process->waite_cycles != 0)
        return;
    if (param->map[process->pc] == 1)
        process->waite_cycles = 10;
    else if (param->map[process->pc] == 2)
        process->waite_cycles = 5;
    else if (param->map[process->pc] == 3)
        process->waite_cycles = 5;
    else if (param->map[process->pc] == 4)
        process->waite_cycles = 10;
    else if (param->map[process->pc] == 5)
        process->waite_cycles = 10;
    else if (param->map[process->pc] == 6)
        process->waite_cycles = 6;
    else if (param->map[process->pc] == 7)
        process->waite_cycles = 6;
    else if (param->map[process->pc] == 8)
        process->waite_cycles = 6;
    else if (param->map[process->pc] == 9)
        process->waite_cycles = 20;
    else if (param->map[process->pc] == 10)
        process->waite_cycles = 25;
    else if (param->map[process->pc] == 11)
        process->waite_cycles = 25;
    else if (param->map[process->pc] == 12)
        process->waite_cycles = 800;
    else if (param->map[process->pc] == 13)
        process->waite_cycles = 10;
    else if (param->map[process->pc] == 14)
        process->waite_cycles = 50;
    else if (param->map[process->pc] == 15)
        process->waite_cycles = 1000;
    else if (param->map[process->pc] == 16)
        process->waite_cycles = 2;
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
     //   print_map(param);
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
            printf("%.2x ",  param->map[i]);
        else
            printf("\033[32;1m%.2x\033[0m ", param->map[i]);
    }
    printf("\n");

}

void unset_is_alive_process(t_processor *proc) {
    t_processor *live_proc;

    live_proc = proc;
    while (live_proc) {
        live_proc->is_alive = 0;
        live_proc = live_proc->next;
    }

}

void output_the_winner(t_player *players)
{
    t_player *temp_player;

    temp_player = players;
    ft_putstr("\nThe winner is ");
    if (amount_lst_el_players(players) == 1)
        ft_putstr(temp_player->header->prog_name);
    else
        while (temp_player)
        {
            if (temp_player->live == 1)
            {
                ft_putstr(temp_player->header->prog_name);
                    return;
            }
            temp_player = temp_player->next;
        }
}

void special_for_denchik(t_param *params)
{
    t_processor *temp_proc;

    temp_proc = params->processors;
    while (temp_proc) {
        //  set_command_for_proc(temp_proc, params);
        execute_process(temp_proc, params);
        //  print_map(params);
//            if (params->map[temp_proc->pc] == 0)
//                 temp_proc->pc = (temp_proc->pc + 1) % MEM_SIZE;
        temp_proc = temp_proc->next;
    }
    if (params->cycle % params->cycle_to_die == 0 && params->cycle > 0) {
        handle_check(params);
        unset_is_alive_process(params->processors);
    }
}

void algorithm(t_param *params) {

    params->cycle = 0;
    while (params->cycle_to_die > 0  && amount_lst_el(params->processors) > 0)
    {
        special_for_denchik(params);
        params->cycle++;
    }
    output_the_winner(params->players);
}

void logic(t_player *players)
{
    t_param *param;

    param = malloc(sizeof(t_param));
    param->processors = NULL;
    param->amount_champs = count_champs(players);
    create_map(players, param);
    get_processes(param);
    param->cycle_to_die = CYCLE_TO_DIE;
    print_map(param);
//    execute_command(param->processors, param);
    algorithm(param); //start of algorithm
//    printf("step 2\n");
//	execute_command(param->players->processors, param);
    print_map(param);

}
