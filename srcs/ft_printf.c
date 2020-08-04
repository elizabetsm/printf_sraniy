/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 18:05:45 by cseabass          #+#    #+#             */
/*   Updated: 2020/07/31 18:05:49 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_fl(char *format, t_struct *st, va_list ap)
{
	st->i--;
	if (format[st->i] == 'L')
		st->f_long = 2;
	else
		st->f_long = 0;
	st->i++;
	if (format[st->i] == 'f' && st->f_long == 0)
		st->fl = va_arg(ap, double);
	else if (format[st->i] == 'f' && st->f_long == 2)
		st->fl = va_arg(ap, long double);
	st->i++;
	st->f = 1;
	bit_parcer(st->fl, st);
}

void	ft_printf_sec(char *format, t_struct *st, va_list ap)
{
	if (format[st->i] == 'd' || format[st->i] == 'i')
	{
		st->a = va_arg(ap, int);
		st->specif = 'd';
		specif_di(st, st->a, format);
	}
	else if (format[st->i] == 'o' || format[st->i] == 'u' ||
			format[st->i] == 'x' || format[st->i] == 'X')
	{
		st->u = va_arg(ap, unsigned int);
		specif_uoxx(st, format, st->u);
		st->f_plus = 0;
	}
	else if (format[st->i] == 'p')
	{
		st->d = va_arg(ap, long long int);
		hexadecimal(st->d, 0, st);
		st->specif = 'p';
		st->i++;
	}
}

void	ft_print_cs(int trig, t_struct *st, va_list ap)
{
	if (trig == 1)
	{
		st->s = va_arg(ap, char *);
		st->specif = 's';
		if (st->s == NULL)
			ft_strcpy(st->tmp, "(null)");
		else
			ft_strcpy(st->tmp, st->s);
		st->i++;
	}
	else if (trig == 2)
	{
		st->c = va_arg(ap, int);
		if (!st->c)
		{
			st->c_trig = 1;
			ft_strcpy(st->tmp, "s");
		}
		else
		{
			st->tmp[0] = st->c;
			st->tmp[1] = '\0';
		}
		st->i++;
	}
}

void	specifier(char *format, t_struct *st, va_list ap)
{
	if (format[st->i] != 's' && format[st->i] != 'c' && format[st->i] != 'p' &&
		format[st->i] != 'd' && format[st->i] != 'i' &&
		format[st->i] != 'o' && format[st->i] != 'u' &&
		format[st->i] != 'x' && format[st->i] != 'X' && format[st->i] !=
		'f')
	{
		st->tmp[0] = format[st->i];
		st->tmp[1] = '\0';
		st->f_space = 0;
		if (format[st->i] != '\0')
			ft_print(format, st);
		else
			st->i--;
		st->i++;
		return ;
	}
	if (format[st->i] == 's')
		ft_print_cs(1, st, ap);
	else if (format[st->i] == 'c')
		ft_print_cs(2, st, ap);
	else if (format[st->i] == 'f')
		ft_printf_fl(format, st, ap);
	else
		ft_printf_sec(format, st, ap);
	ft_print(format, st);
}

void	handle(char *format, va_list ap, t_struct *st)
{
	int i;

	init(st);
	st->i++;
	flags(format, st, ap);
	width(format, st, ap);
	i = length(format, st, ap);
	if (format[st->i] == 'L')
		st->i++;
	if (i == 0)
		specifier(format, st, ap);
	else
		ft_print(format, st);
}

void 	memdel(t_struct *st)
{
	ft_memdel((void **)(&st->color));
	ft_memdel((void **)(&st));

}

int		ft_printf(char *format, ...)
{
	va_list		ap;
	t_struct	*st;
	int			i;

	st = (t_struct *)malloc(sizeof(t_struct));
	va_start(ap, format);
	st->color = ft_memalloc(20);
	st->i = 0;
	while (format[st->i] != '\0')
	{
		if (format[st->i] == '%')
			handle(format, ap, st);
		else if (format[st->i] == '{' && ft_strcmp(st->color, "no") != 0)
			proverka(format, st);
		else
		{
			st->schet = st->schet + re_putchar(format[st->i]);
			st->i++;
		}
	}
	va_end(ap);
	i = st->schet;
	memdel(st);
	return (i);
}

int main()
{
	static unsigned int		mx_u = 235;
	static long double			mx_Lf = 0.375l;
	static double				mx_f = 0.625;
	static long				mx_li =  4223372036854775800;
	static long long			mx_lli = 3223372036654775200;
	static char				mx_c = 'G';
	static short				mx_hi = -3244;
	static char				mx_hhi = 'F';
	static char			   *mx_s = "Hello, World!";
	static int					mx_i = 42;
	double z;
	z = NAN;
//	z = -1 * z;
	int i = ft_printf("{Blue}%d{eoc}", 123);
	printf("\ni = %d\n", i);
	int a = printf("{Blue}%d{eoc}", 123);
    printf("\na = %d", a);

    return 0;
}
