/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:22:09 by fwechsle          #+#    #+#             */
/*   Updated: 2023/09/12 19:06:04 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	count_digi(long long n)
{
	long long	count;

	count = 0;
	if (n == 0 || n < 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static long long	set_pre(long long n, char *a)
{
	if (n < 0)
	{
		a[0] = '-';
		n *= -1;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	int			count;
	char		*a;
	int			digit;
	int			i;
	long long	n1;

	n1 = n;
	count = count_digi(n1);
	a = (char *)malloc((count + 1) * sizeof(char));
	if (a == 0)
		return (0);
	i = count_digi(n1);
	a[i] = 0;
	if (n1 == 0)
		a[0] = n1 + 48;
	n1 = set_pre(n1, a);
	while (n1 != 0)
	{
		i--;
		digit = n1 % 10;
		a[i] = digit + 48;
		n1 /= 10;
	}
	return (a);
}
