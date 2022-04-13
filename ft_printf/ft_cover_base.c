/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cover_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:14:16 by yeblee            #+#    #+#             */
/*   Updated: 2022/04/13 16:48:35 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_malloc(char **nbr_str, int *is_neg, long *nbrl)
{
	*nbr_str = (char *)malloc(sizeof(char) * 33);
	if (*nbr_str == NULL)
		return (0);
	*is_neg = 1;
	if (*nbrl < 0)
	{
		*nbrl *= -1;
		*is_neg = -1;
	}
	return (1);
}

int	ft_base_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_change(long nbr, char *base, int len)
{
	int	i;

	i = nbr % len;
	if (nbr / len != 0)
		ft_change(nbr / len, base, len);
	write(1, &base[i], 1);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	long	nbrl;
	char	*nbr_str;
	int		base_len;
	int		cur;
	int		is_neg;

	nbrl = nbr;
	if (ft_malloc(&nbr_str, &is_neg, &nbrl) == 0)
		return (0);
	base_len = ft_strlen(base);
	cur = 0;
	while (nbrl > 0)
	{
		nbr_str[cur++] = base[nbrl % base_len];
		nbrl /= base_len;
	}
	if (nbr == 0)
	{
		cur = 1;
		nbr_str[0] = '0';
	}
	if (is_neg == -1)
		nbr_str[cur++] = '-';
	nbr_str[cur] = 0;
	return (rev_str(nbr_str));
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	long	nbrl;

	nbrl = nbr;
	len = ft_strlen(base);
	if (!ft_base_valid(base))
		return ;
	if (nbrl >= 0)
		ft_change(nbrl, base, len);
	else
	{
		write(1, "-", 1);
		ft_change(nbrl * -1, base, len);
	}
}

// char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
// {
// 	int		str_to_int;
// 	char	*int_to_str;

// 	if (ft_check_base(base_from) == 0)
// 		return (0);
// 	if (ft_check_base(base_to) == 0)
// 		return (0);
// 	str_to_int = ft_atoi_base(nbr, base_from);
// 	int_to_str = ft_putnbr_base(str_to_int, base_to);
// 	return (int_to_str);
// }
