/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 19:44:38 by cseabass          #+#    #+#             */
/*   Updated: 2020/07/31 19:44:41 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print(char *format, t_struct *st)
{
	st->i--;
	if ((st->wdht > st->wdth_pres) && st->f_pres == 1 && st->f != 1)
		st->f_trig = 1;
	if (st->specif == 's' || st->specif == 'c' )
	{
		st->f_scp = 1;
		st->f_trig = 0;
		st->f_space = 0;
	}
	if ((st->specif == 'x' || st->specif == 'X' ||
		st->specif == 'o') && st->tmp[0] == '0')
		st->without_0x = 1;
	if (st->specif == 's' && st->wdth_pres < 0)
		st->wdth_pres = ft_strlen(st->tmp);
	if (st->f_minus == 1)
		minus_print(format, st);
	else
		print_else(format, st);
	ft_memdel((void **)(&st->tmp));
	st->i++;
}

void	plus_print(t_struct *st)
{
	if (st->specif == 's' || st->specif == 'c' || st->specif == 'p')
		st->f_plus = 0;
	if (st->f == 1)
	{
		if (st->sign_bit == 1)
			st->schet = st->schet + re_putchar('-');
		else if (st->f_plus == 1 && ft_strcmp(st->tmp, "nan") != 0)
			st->schet = st->schet + re_putchar('+');
	}
	else
	{
		if (st->num_flags == 1)
			st->schet = st->schet + re_putchar('-');
		else if (st->f_plus == 1)
			st->schet = st->schet + re_putchar('+');
	}
}

void	minus_print1(char *format, t_struct *st)
{
	if (st->specif == 'p')
		st->schet = st->schet + re_putstr("0x");
	if (st->f_resh == 1)
	{
		if (st->f_pres == 0 ||
			(st->f_pres == 1 && st->wdth_pres <= ft_strlen(st->tmp)))
		{
			if (st->specif == 'o' && (st->without_0x != 1 ||
				(st->wdth_pres == 0 && st->f_pres == 1)))
				st->schet = st->schet + re_putstr("0");
		}
	}
	if (st->c_trig == 1)
		st->schet = st->schet + re_putchar(st->c);
	else if ((st->specif != 'g' && st->f_pres != 1) || st->f == 1)
		st->schet = st->schet + re_putstr(st->tmp);
	else if ((st->specif != 's' && st->wdth_pres > 0) || st->f == 1)
		st->schet = st->schet + re_putstr(st->tmp);
	if (st->f_space == 1 && st->num_flags != 1 && st->sign_bit != 1 &&
		st->c_trig != 1 && ft_strcmp(st->tmp, "%") != 0)
		st->schet = st->schet + re_putchar(' ');
	if ((st->wdht > 0 && st->f_nul != 1) || st->f_space == 1 || st->f_pres == 1)
		space_print(st);
}

void	minus_print(char *format, t_struct *st)
{
	plus_print(st);
	if (st->f_resh == 1)
	{
		if (st->without_0x != 1 && st->f_resh == 1)
		{
			if (st->specif == 'x')
				st->schet = st->schet + re_putstr("0x");
			else if (st->specif == 'X')
				st->schet = st->schet + re_putstr("0X");
		}
	}
	if (st->wdth_pres > 0 && st->f_pres == 1)
		pres_print(st);
	if (st->f_nul == 1 && st->f_pres != 1)
		null_print(st);
	minus_print1(format, st);
}

void	print_else1(char *format, t_struct *st)
{

	if (st->f_resh == 1)
	{
		if (st->f_pres == 0 ||
			(st->f_pres == 1 && st->wdth_pres <= ft_strlen(st->tmp)))
		{
			if (st->specif == 'o' && (st->without_0x != 1 ||
				(st->wdth_pres == 0 && st->f_pres == 1)))
				st->schet = st->schet + re_putstr("0");
		}
	}
	if (st->c_trig == 1)
		st->schet = st->schet + re_putchar(st->c);
	else if (st->f_pres == 1 && st->wdth_pres == 0 &&
			ft_strcmp(st->tmp, "0") == 0 && st->f != 1)
		st->wdth_pres = 0;
	else if (st->specif != 'g' && st->f_pres != 1)
		st->schet = st->schet + re_putstr(st->tmp);
	else if ((st->specif != 's' || st->f == 1))
		st->schet = st->schet + re_putstr(st->tmp);
}

void	print_else(char *format, t_struct *st)
{
	if (st->f_space == 1 && st->num_flags != 1 && st->sign_bit != 1 &&
		st->c_trig != 1 && ft_strcmp(st->tmp, "%") != 0 &&
		ft_strcmp(st->tmp, "nan") != 0)
		st->schet = st->schet + re_putchar(' ');
	if (((st->wdht > 0 || st->f_space == 1) && (st->f_nul != 1 ||
		(st->f_trig == 1))) || (st->f == 1 && st->f_nul != 1))
		space_print(st);
	plus_print(st);
	if (st->without_0x != 1 && st->f_resh == 1)
	{
		if (st->specif == 'x')
			st->schet = st->schet + re_putstr("0x");
		else if (st->specif == 'X')
			st->schet = st->schet + re_putstr("0X");
	}
	if (st->specif == 'p')
		st->schet = st->schet + re_putstr("0x");
	if ((st->f_nul == 1 && st->f_pres != 1) || (st->f_nul == 1 && st->f == 1) || (st->f_nul == 1 && st->f_scp == 1))
		null_print(st);
	if (st->wdth_pres > 0 && st->f_pres == 1)
		pres_print(st);
	print_else1(format, st);
}

void	space_print1(t_struct *st, int c, int i)
{
	if (st->specif == 's' || st->specif == 'c' || st->specif == 'p')
		st->f_plus = 0;
	if ((st->num_flags == 1 && st->f_plus != 1) ||
		(st->num_flags != 1 && st->f_plus == 1) || st->sign_bit == 1)
		c--;
	else if (st->num_flags == 1 && st->f_plus == 1)
		c--;
	else if (st->f_space == 1 && st->num_flags != 1)
		c--;
	if (st->specif == 'p')
		c = c - 2;
	if (st->f_resh == 1 && (st->specif == 'x' || st->specif == 'X') &&
		st->without_0x == 0)
		c = c - 2;
	else if ((st->f_resh == 1 && st->specif == 'o') &&
			((st->f_pres == 1 && st->wdth_pres <= i) ||
			(st->wdht > 0 && st->f_pres == 0 && st->without_0x != 1)))
		c--;
	while (c > 0)
	{
		st->schet = st->schet + re_putchar(' ');
		c--;
	}
}

void	space_print(t_struct *st)
{
	int c;
	int i;

	if (st->f_space == 1 && st->num_flags != 1 && st->wdht == 0)
		return ;
	if (st->wdth_pres == 0 && st->f_pres == 1 && st->f != 1 && (st->specif == 's' || ft_strcmp(st->tmp, "0") == 0))
		i = 0;
	else
		i = ft_strlen(st->tmp);
	if (st->wdth_pres > 0 && i < st->wdth_pres && st->specif == 's')
		c = st->wdht - i;
	else if (st->wdth_pres > 0 && i > st->wdth_pres && st->specif == 's')
		c = st->wdht - st->wdth_pres;
	else if (st->wdth_pres > 0 && (i < st->wdth_pres) && st->f_scp == 0)
		c = st->wdht - st->wdth_pres;
	else if (st->wdth_pres > 0 && (i > st->wdth_pres) && st->specif != 's')
		c = st->wdht - i;
	else
		c = st->wdht - i;
	space_print1(st, c, i);
}

void	null_print2(t_struct *st, int c)
{
	if (st->specif == 'p')
		c = c - 2;
	if ((st->f_resh == 1 && (st->specif == 'x' || st->specif == 'X')) &&
		st->without_0x == 0)
		c = c - 2;
	else if (st->f_resh == 1 && st->specif == 'o' &&
			st->without_0x == 0)
		c--;
	while (c > 0)
	{
		st->schet = st->schet + re_putchar('0');
		c--;
	}
}

void	null_print1(t_struct *st, int i)
{
	int c;

	if (st->wdth_pres > 0 && i > st->wdth_pres)
		c = st->wdht - i;
	else if (st->wdth_pres > 0 && i < st->wdth_pres)
		c = st->wdht - st->wdth_pres;
	else
		c = st->wdht - i;
	if (st->wdth_pres > 0 && i > st->wdth_pres && st->f_scp == 1)
		c = st->wdht - st->wdth_pres;
	if ((st->num_flags == 1 && st->f_plus != 1) ||
		(st->num_flags != 1 && st->f_plus == 1) || st->sign_bit == 1)
		c--;
	else if (st->num_flags == 1 && st->f_plus == 1)
		c--;
	else if (st->f_space == 1 && st->num_flags != 1)
		c--;
	null_print2(st, c);
}

void	null_print(t_struct *st)
{
	int c;
	int i;

	i = ft_strlen(st->tmp);
	if (st->f_scp == 1 && st->wdth_pres == 0 && st->f_pres == 1)
		i = 0;
	if (st->f_space == 1 && st->num_flags != 1 && st->wdht == 0)
		st->schet = st->schet + re_putchar(' ');
	else
		null_print1(st, i);
}
