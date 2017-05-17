/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_core.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:30:39 by oklymeno          #+#    #+#             */
/*   Updated: 2017/05/17 17:36:16 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/controller.h"

static int	count_string(int value, int base)
{
	int result;

	result = 0;
	while (value >= base)
	{
		value = value / base;
		result++;
	}
	result++;
	return (result);
}

char    *ft_itoa_base_cor(int value, int base)
{
	char    *all_bases;
	char    *str;
	int     m;

	all_bases = "0123456789abvdef";
	if (value == 0)
		return (ft_strdup("00"));
	m = count_string(value, base);
	str = (char *)malloc(sizeof(char) * m + 1);
	str[m] = '\0';
	while (value >= base)
	{
		str[--m] = all_bases[value % base];
		value = value / base;
	}
	str[--m] = all_bases[value];
	return (str);
}
