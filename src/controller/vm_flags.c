/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:00:23 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/22 20:04:59 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/controller.h"

int		digit(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

void	get_dump(t_fl *flags, char **argv)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (argv[++i])
		if (!ft_strcmp(argv[i], "-d"))
			res++;
	if (res > 1)
		print_cant_read_source_file(argv[i]); /* to much -d flags */
	i = 0;
	while (argv[++i])
	{
		if (!ft_strcmp(argv[i], "-d"))
		{
			flags->dump = ft_atoi(argv[i + 1]);
			if (flags->dump == 0)
				print_cant_read_source_file(argv[i]);/* incorrect argument passing to -d flag*/
		}
	}
	if (flags->dump < 0)
		print_cant_read_source_file(argv[i]);//use only integers
}

void	get_vis(t_fl *flags, char **argv)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (argv[++i])
		if (!ft_strcmp(argv[i], "-v"))
			res++;
	if (res > 1)
		print_cant_read_source_file(argv[i]);//to much -v flags
	i = 0;
	while (argv[++i])
		if (!ft_strcmp(argv[i], "-v"))
			flags->vis = 1;
}

void	vm_get_flags(t_fl *flags, char **argv)
{
	int n;

	n = 0;
	flags->dump = 0;
	flags->vis = 0;
	get_dump(flags, argv);
	get_vis(flags, argv);
}

int		vm_get_numb(char **argv, int n, int *numb)
{
	if (n > 2)
		if (!ft_strcmp(argv[n - 2], "-n") && digit(argv[n - 1]))
			return (ft_atoi(argv[n - 1]));
	*numb += 1;
	return (*numb);
}
