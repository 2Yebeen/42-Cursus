/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:00:04 by yeblee            #+#    #+#             */
/*   Updated: 2022/04/13 14:48:13 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_numlen(unsigned	int num, int base)
{
	int	len;

	len = 0;
	while (num)
	{
		len++;
		num = num / base;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n, char *base)
{
	char	*ptr;
	int		base_len;
	size_t	len;

	if (n == 0)
		return ("0");
	base_len = ft_strlen(base);
	len = ft_numlen(n, base_len);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	if (!ptr)
		ptr[0] = '0';
	ptr[len--] = '\0';
	while (n)
	{
		ptr[len] = base[n % base_len];
		n /= base_len;
		len--;
	}
	return (ptr);
}

char	*ft_itoa(int n, char *base)
{
	char	*ptr;
	int		base_len;
	long	nb;
	size_t	len;

	base_len = ft_strlen(base);
	len = ft_numlen(n, base_len);
	nb = (long)n;
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	if (nb < 0)
	{
		ptr[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		ptr[0] = '0';
	ptr[len--] = '\0';
	while (nb)
	{
		ptr[len] = base[nb % 10];
		nb /= base_len;
		len--;
	}
	return (ptr);
}

char	*ft_pitoa(unsigned long long n, char *base)
{
	char	*ptr;
	int		base_len;
	size_t	len;

	base_len = ft_strlen(base);
	len = ft_numlen(n, base_len) + 2;
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	ptr[0] = '0';
	ptr[1] = 'x';
	if (n == 0)
		ptr[2] = '0';
	ptr[len--] = '\0';
	while (n)
	{
		ptr[len] = base[n % 10];
		n /= base_len;
		len--;
	}
	return (ptr);
}