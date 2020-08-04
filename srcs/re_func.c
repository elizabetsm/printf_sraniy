/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 18:42:31 by cseabass          #+#    #+#             */
/*   Updated: 2020/07/31 18:42:33 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	re_putstr(char const *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	re_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
