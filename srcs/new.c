/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 18:19:04 by cseabass          #+#    #+#             */
/*   Updated: 2020/07/31 18:19:06 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flags(char *format, t_struct *st, va_list ap)
{
	while (format[st->i] >= 32 && format[st->i] <= 48 && format[st->i] != 37)
	{
		if (format[st->i] == '+')
			st->f_plus = 1;
		if (format[st->i] == '.')
			st->f_pres = 1;
		else if (format[st->i] == '-')
			st->f_minus = 1;
		else if (format[st->i] == ' ')
			st->f_space = 1;
		else if (format[st->i] == '#')
			st->f_resh = 1;
		else if (format[st->i] == '0')
			st->f_nul = 1;
		else if (format[st->i] == '*')
			st->zvezd++;
		st->i++;
	}
	if (format[st->i - 1] == '0' && format[st->i - 2] == '.')
		st->i--;
	if (st->f_minus == 1)
		st->f_nul = 0;
	if (st->f_plus == 1)
		st->f_space = 0;
}

void	pres_check(char *format, t_struct *st, va_list ap)
{
	if (format[st->i] == '.')
	{
		pres_width(format, st, ap);
		st->f_pres = 1;
	}
}

void	pres_width1(t_struct *st, char *wdht, char *format)
{
	st->wdth_pres = ft_atoi(wdht);
	if (format[st->i - 1] >= 65 && format[st->i - 1] <= 122)
		st->i--;
}

void	pres_width(char *format, t_struct *st, va_list ap)
{
	int		j;
	char	*wdht;

	j = 0;

	if ((format[st->i]> 59 && format[st->i] < 127) && st->zvezd == 0)
		return ;
	if (st->zvezd > 0 || (format[st->i - 2] == '*' &&
		format[st->i - 1] != '%' && format[st->i - 1] != '.'))
		st->wdth_pres = va_arg(ap, int);
	else
	{
		wdht = ft_memalloc(20);
		while (format[st->i] != '\0' && format[st->i] != '%')
		{
			if (format[st->i] >= 48 && format[st->i] <= 57)
			{
				wdht[j] = format[st->i];
				j++;
			}
			st->i++;
			if (format[st->i] == '.' || (format[st->i] > 96 &&
				format[st->i] < 123) || format[st->i] == st->specif)
				break ;
		}
		pres_width1(st, wdht, format);
		free(wdht);
	}

}

void	width1(char *format, t_struct *st, va_list ap)
{
	if (format[st->i - 1] == '.' || (format[st->i - 2] == '.' &&
		format[st->i - 1] != '%'))
	{
		pres_width(format, st, ap);
		st->f_pres = 1;
	}
	else
	{
		detect_wdth(format, st, ap);
		pres_check(format, st, ap);
	}
}

void	width(char *format, t_struct *st, va_list ap)
{
	if (st->zvezd > 0)
	{
		if (st->zvezd == 1 && st->f_pres == 1 && format[st->i - 1] != '.')
			pres_width(format, st, ap);
		else if (st->zvezd == 2)
		{
			detect_wdth(format, st, ap);
			pres_width(format, st, ap);
		}
		else
			detect_wdth(format, st, ap);
	}
	else
		width1(format, st, ap);
	if (st->zvezd == 1 && st->f_pres == 1 && format[st->i - 1] == '.')
	{
		st->zvezd--;
		pres_width(format, st, ap);
	}
}

void	detect_wdth1(t_struct *st, char *format)
{
	char	*wdht;
	int		i;
	int		j;

	i = st->i;
	j = 0;
	wdht = ft_memalloc(20);
	while (format[i] != '\0' && format[i] != '%')
	{
		if (format[i] >= 48 && format[i] <= 57)
		{
			wdht[j] = format[i];
			j++;
		}
		if (format[i] == '.' || (format[i] > 96 && format[i] < 123)
			|| format[i] == st->specif)
			break ;
		i++;
	}
	st->wdht = ft_atoi(wdht);
	st->i = st->i + j;
	free(wdht);
}

void	detect_wdth(char *format, t_struct *st, va_list ap)
{
	int		i;
	int		j;
	char	*wdht;

	i = st->i;
	j = 0;
	if (st->zvezd > 0)
	{
		st->wdht = va_arg(ap, int);
		if (st->wdht < 0)
		{
			st->wdht = st->wdht * -1;
			st->f_minus = 1;
			st->f_nul = 0;
		}
	}
	else
		detect_wdth1(st, format);
}

void	ft_free(t_struct *st)
{
	ft_memdel((void **)(&st->tmp));
}
