/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 12:13:10 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/03 00:24:06 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm_header.h"

static void	init_colors(t_player *players)
{
	t_player	*tmp;
	short		color;

	color = 1;
	tmp = players;
	init_pair(0, 7, 0);
	while (tmp)
	{
		init_pair(tmp->numb, color, COLOR_BLACK);
		init_pair(255 - tmp->numb, 7, color);
		color++;
		tmp = tmp->next;
	}
}

static void	print_pc(WINDOW *wnd, t_param *param, int i, int proc)
{
	wattron(wnd, COLOR_PAIR(255 - proc));
	wprintw(wnd, "%.2x", param->map[i]);
	wattroff(wnd, COLOR_PAIR(255 - proc));
	wprintw(wnd, " ");
}

static int	check_proc(t_param *param, int i)
{
	t_processor	*tmp;

	tmp = param->processors;
	while (tmp)
	{
		if ((int)tmp->pc == i)
			return (tmp->player);
		tmp = tmp->next;
	}
	return (0);
}

static void	print_map_vis(WINDOW *wnd, t_param *param)
{
	int i;

	start_color();
	init_colors(param->players);
	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			wprintw(wnd, "0x%.4x : ", i);
		if (check_proc(param, i))
			print_pc(wnd, param, i, check_proc(param, i));
		else
		{
			wattron(wnd, COLOR_PAIR(param->map_c[i]));
			wprintw(wnd, "%.2x ", param->map[i]);
			wattroff(wnd, COLOR_PAIR(param->map_c[i]));
		}
		i++;
	}
	wrefresh(wnd);
}

void		key_hook(int key)
{
	static int flag = 0;
	
	while (1)
	{
		if (key == 27)
		{
			endwin();
			exit(1);
		}
		if (key == 's')
			flag++;
		if (flag % 2 == 1)
			return ;
	}
}

void		visualize(t_param *param, int key)
{
	WINDOW *wnd;
	WINDOW *status;

	wnd = newwin(64, 201, 1, 1);
	status = newwin(100, 20, 65, 1);
	print_status(param, status);
	print_map_vis(wnd, param);
	refresh();
	wrefresh(status);
	key_hook(key);
}
