/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 13:30:04 by cseabass          #+#    #+#             */
/*   Updated: 2020/07/31 13:30:06 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#define SIZE_E 16383
#define SIZE_M 64

void	*ft_cpy(char *newptr, char *ptr, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (ptr[i] != '\0')
	{
		newptr[i] = ptr[i];
		i++;
	}
	while (i < size)
	{
		newptr[i] = '0';
		i++;
	}
	newptr[i] = '\0';
	return (newptr);
}

void	*ft_realloc(void *ptr, size_t size)
{
	char	*newptr;

	if (!size && ptr)
	{
		if (!(newptr = (char *)malloc(1)))
			return (NULL);
		ft_memdel(&ptr);
		return (newptr);
	}
	if (!(newptr = (char *)malloc(size + 1)))
		return (NULL);
	if (ptr)
	{
		ft_cpy(newptr, ptr, size);
		ft_memdel(&ptr);
	}
	return (newptr);
}

void	*get_char(char *arr)
{
	char	*mas;
	int		i;
	int		j;

	j = ft_strlen(arr);
	i = 0;
	mas = ft_memalloc(ft_strlen(arr) + 1);
	while (arr[i] != '\0')
	{
		mas[i] = arr[j - 1];
		i++;
		j--;
	}
	mas[i] = '\0';
	ft_memdel((void **)(&arr));
	arr = mas;
	return (arr);
}

void	*sum_char2(char *ans, int i, int j)
{
	char *newptr;

	while (ans[i] != '\0')
	{
		if (ans[i] > '9')
		{
			if (ans[i + 1] == '\0')
			{
				newptr = ft_strnew(j + 1);
				ft_strcpy(newptr, ans);
				newptr[i] -= 10;
				newptr[i + 1] = 49;
				newptr[i + 2] = '\0';
				ft_memdel((void **)(&ans));
				return (newptr);
			}
			else
			{
				ans[i + 1]++;
				ans[i] -= 10;
			}
		}
		i++;
	}
	return (ans);
}

void	*sum_char(char *ans, char *tmp, t_struct *st)
{
	int i;
	int j;

	i = ft_strlen(ans);
	j = ft_strlen(tmp);
	while ((i - 1) == j || j > i)
	{
		ans = ft_realloc(ans, (i * 2));
		i = ft_strlen(ans);
		j = ft_strlen(tmp);
	}
	i = 0;
	while (tmp[i] != '\0' && ans[i] != '\0')
	{
		ans[i] += tmp[i] - '0';
		i++;
	}
	i = 0;
	ans = sum_char2(ans, i, j);
	return (ans);
}

void	two_degree2(t_struct *st)
{
	char	*newptr;
	int		i;

	i = 0;
	while (st->arr[i] != '\0')
	{
		if (st->arr[i + 1] == '\0' && st->arr[i] > '9')
		{
			newptr = ft_memalloc(i + 4);
			ft_strcpy(newptr, st->arr);
			newptr[i] -= 10;
			newptr[i + 1] = 49;
			newptr[i + 2] = '\0';
			ft_memdel((void **)(&st->arr));
			st->arr = newptr;
			return ;
		}
		if (st->arr[i] > '9')
		{
			st->arr[i] -= 10;
			st->arr[i + 1]++;
		}
		i++;
	}
}

void	two_degree(t_struct *st)
{
	char	*tm;
	int		i;

	i = ft_strlen(st->arr);
	tm = ft_memalloc(i + 1);
	ft_strcpy(tm, st->arr);
	i = 0;
	while (st->arr[i] != '\0')
	{
		st->arr[i] += tm[i] - '0';
		i++;
	}
	ft_memdel((void **)(&tm));
	two_degree2(st);
}

void	rounding_fp(t_struct *st)
{
	char *arr;

	arr = ft_memalloc(2);
	arr[0] = '1';
	arr[1] = '\0';
	st->fp = get_char(st->fp);
	sum_char(st->fp, arr, st);
	st->fp = get_char(st->fp);
	st->f_zero = 0;
	st->sp[0] -= 10;
	ft_memdel((void **)(&arr));
}

int		sum_reverse2(const char *arr, t_struct *st)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (arr[j] != '\0')
	{
		st->sp[i] += arr[j] - '0';
		k = i;
		while (k > 0)
		{
			if (st->sp[k] > '9')
			{
				st->sp[k - 1]++;
				st->sp[k] -= 10;
			}
			k--;
		}
		i++;
		j++;
	}
	return (k);
}

void	sum_reverse(char *tmp, t_struct *st)
{
	int		i;
	int		j;
	int		k;
	char	*arr;

	i = ft_strlen(st->sp);
	j = ft_strlen(tmp);
	arr = ft_memalloc(j + 1);
	ft_strcpy(arr, tmp);
	arr = get_char(arr);
	while ((i - 1) == j || j > i)
	{
		st->sp = ft_realloc(st->sp, (i * 2));
		i = ft_strlen(st->sp);
	}
	k = sum_reverse2(arr, st);
	if (k == 0 && st->sp[k] > '9')
		rounding_fp(st);
	ft_memdel((void **)(&arr));
}

void	*get_zero(char *arr)
{
	char	*newptr;
	int		i;

	newptr = ft_memalloc(ft_strlen(arr) + 3);
	i = 0;
	while (arr[i] != '\0')
	{
		newptr[i] = arr[i];
		i++;
	}
	newptr[i] = '0';
	newptr[i + 1] = '\0';
	ft_memdel((void **)(&arr));
	return (newptr);
}

void	*multiplication2(const char *ar, char *newptr)
{
	int j;

	j = 0;
	while (ar[j] != '\0')
	{
		newptr[j] += ar[j] - '0';
		if (newptr[j] > '9')
		{
			if (newptr[j + 1] == '\0')
			{
				newptr[j + 1] = '0';
				newptr[j + 2] = '\0';
			}
			newptr[j + 1]++;
			newptr[j] -= 10;
		}
		j++;
	}
	return (newptr);
}

void	*multiplication(char *arr, int num, int deg)
{
	int		i;
	char	*newptr;

	newptr = ft_memalloc(ft_strlen(arr) + 3);
	ft_strcpy(newptr, arr);
	i = 0;
	while (i < num - 1)
	{
		newptr = multiplication2(arr, newptr);
		i++;
	}
	if (ft_strlen(newptr) < deg)
		newptr = get_zero(newptr);
	ft_memdel((void **)(&arr));
	return (newptr);
}

int		exp_shift(t_sun eeei)
{
	int a;

	a = eeei.v.exp - SIZE_E;
	return (a);
}

int		check_inf_nan(t_sun eeei, t_struct *st)
{
	if (eeei.f == eeei.f * 10 && eeei.f != 0.0)
	{
//		st->tmp = ft_memalloc(5);
		st->tmp = ft_strjoin(st->tmp, "inf");
		return (1);
	}
	else if (eeei.f != eeei.f)
	{
//		st->tmp = ft_memalloc(4);
		st->tmp = ft_strjoin(st->tmp, "nan");
		return (1);
	}
	return (0);
}

int		check_zero1(t_sun eeei, t_struct *st)
{
	int i;

	i = check_inf_nan(eeei, st);
	if (i == 1)
	{
		st->f_nul = 0;
		st->wdth_pres = 0;
		st->f_pres = 0;
		return (1);
	}
	return (0);
}

int		check_zero(t_sun eeei, t_struct *st)
{
	int i;
	int j;

	i = -1;
	j = 0;
	if (eeei.v.exp == 0 && eeei.v.mant == 0)
	{
		st->tmp = ft_memalloc(st->round + 4);
		st->tmp[++i] = '0';
		if (st->round != 0 || st->f_resh != 0)
			st->tmp[++i] = '.';
		if (st->round < 0)
			st->round = 6;
		while (j < st->round)
		{
			st->tmp[++i] = '0';
			j++;
		}
		return (1);
	}
	i = check_zero1(eeei, st);
	if (i == 1)
		return (1);
	return (0);
}

int		bits(t_sun eeei, int c)
{
	if (eeei.v.mant & (1L << c))
		return (1);
	return (0);
}

void	after_point(t_sun eeei, t_struct *st)
{
	int count;
	int c;
	int b;

	st->arr = ft_memalloc(2);
	st->arr[0] = '1';
	count = 0;
	c = (SIZE_M - st->shift - 2);
	while (c >= 0)
	{
		count++;
		b = bits(eeei, c);
		if (c > SIZE_M)
		{
			st->arr = multiplication(st->arr, 5, count);
			c--;
			continue;
		}
		st->arr = multiplication(st->arr, 5, count);
		if (b == 1 && c != SIZE_M)
			sum_reverse(st->arr, st);
		c--;
	}
	ft_memdel((void **)(&st->arr));
}

void 	init_array(t_struct *st)
{
	st->arr = ft_memalloc(2);
	st->arr[0] = '1';
	st->arr[1] = '\0';
	st->sp = ft_memalloc(st->size);
	st->sp = ft_realloc(st->sp, st->size);
	st->fp = ft_memalloc(st->size);
	st->fp = ft_realloc(st->fp, st->size);
}

void	init_chars(t_struct *st)
{
	ft_memdel((void **)(&st->tmp));
	st->size = 8;
//	st->arr = ft_memalloc(2);
//	st->arr[0] = '1';
//	st->arr[1] = '\0';
//	st->sp = ft_memalloc(st->size);
//	st->sp = ft_realloc(st->sp, st->size);
//	st->fp = ft_memalloc(st->size);
//	st->fp = ft_realloc(st->fp, st->size);
	st->f_zero = 0;
	st->neg_round = 0;
	st->sign_bit = 0;
	if (st->f_pres == 1)
		st->round = st->wdth_pres;
	else
		st->round = 6;
}

void	circle(t_struct *st, t_sun eeei)
{
	int c;
	int b;

	c = (SIZE_M - st->shift - 1);
	while (c < SIZE_M)
	{
		if (c == (SIZE_M - st->shift - 1) || c < 0)
		{
			if (c == (SIZE_M - st->shift - 1))
			{
				b = bits(eeei, c);
				if (b == 1 && c > 0)
					st->fp = sum_char(st->fp, st->arr, st);
			}
			else if (c < 0)
				two_degree(st);
			c++;
			continue ;
		}
		b = bits(eeei, c);
		two_degree(st);
		if (b == 1)
			st->fp = sum_char(st->fp, st->arr, st);
		c++;
	}
}

void	bit_parcer(long double f, t_struct *st)
{
	t_sun	eeei;
	int		c;

	eeei.f = f;
	init_chars(st);
	if (eeei.v.sign == 1)
		st->sign_bit = 1;
	c = check_zero(eeei, st);
	if (c == 1)
		return ;
	init_array(st);
	st->shift = exp_shift(eeei);
	if (st->shift >= 0)
	{
		circle(st, eeei);
		st->fp = get_char(st->fp);
		ft_memdel((void **)(&st->arr));
	}
	else
		st->f_zero = 1;
	after_point(eeei, st);
	ft_out(st->fp, st->sp, st);
}
