/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 21:19:47 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/16 02:43:02 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test_bonus.h"

static void	put_str(char *s)
{
	while (*s)
	{
		if (*s == '\t')
			write(1, "\\t", 2);
		else if (*s == '\v')
			write(1, "\\v", 2);
		else if (*s == '\f')
			write(1, "\\f", 2);
		else if (*s == '\r')
			write(1, "\\r", 2);
		else if (*s == '\n')
			write(1, "\\n", 2);
		else
			write(1, s, 1);
		++s;
	}
}

static void	do_test(char *s, char *base)
{
	int	ori;
	int	ft;

	put_str("try... ft_atoi_base(\"");
	put_str(s);
	put_str("\", \"");
	put_str(base);
	printf("\");\n");
	ft = ft_atoi_base(s, base);
	ori = atoi_base(s, base);
	if (ori != ft)
	{
		printf("KO: diff ori: %d, ft: %d\n", ori, ft);
		exit(1);
	}
}

void	ft_atoi_base_test(void)
{
	printf("===================================================\n");
	printf("testing ft_atoi_base();\n");
	do_test(" \t\v\r\n\f+-abc", "abcdefghij");
	do_test("34343434343434", "01234567");
	do_test("424242", "424242");
	do_test("424242", "42");
	do_test("NO BASE!!!", "");
	do_test("INCLUDE WHITESPACE!!!", " \t\v\r\n\f+-");
	do_test(" a", " a");
	do_test("1234", "");
	do_test("1234", "0");
	do_test("1234", "01");
	printf("SUCCESS!\n");
}
