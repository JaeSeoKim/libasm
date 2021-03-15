/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 04:33:36 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/16 02:43:03 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_check(char *str, char *base_char, int base)
{
	int	i;

	i = 0;
	while (i < base)
	{
		if (*str == base_char[i])
			return (1);
		++i;
	}
	return (0);
}

int	ft_get_base_index(char *str, char *base_char, int base)
{
	int	i;

	i = 0;
	while (i < base)
	{
		if (*str == base_char[i])
			break ;
		++i;
	}
	return (i);
}

int	ft_atoi(char *str, char *base_char, int base)
{
	int	minus;
	int	num;

	num = 0;
	minus = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		++str;
	}
	while (ft_atoi_check(str, base_char, base))
	{
		num *= base;
		num += ft_get_base_index(str, base_char, base);
		++str;
	}
	num *= minus;
	return (num);
}

int	ft_base_check(char *base, int *cnt)
{
	int		i;
	int		j;

	i = 0;
	*cnt = 0;
	while (base[i])
	{
		if ((base[i] >= 9 && base[i] <= 13) || \
			base[i] == ' ' || base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
			if (base[i] == base[j++])
				return (0);
		++i;
		++(*cnt);
	}
	return (1);
}

int	atoi_base(char *str, char *base)
{
	int	cnt;

	if (!*base || !*(base + 1))
		return (0);
	if (ft_base_check(base, &cnt))
		return (ft_atoi(str, base, cnt));
	return (0);
}
