/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 03:16:00 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/13 03:37:37 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

static void	do_test(char *s)
{
	printf("try... $%s$\n", s);
	if (strlen(s) != ft_strlen(s))
		exit(1);
	printf("Success!\n");
}

void	test_strlen(void)
{
	printf("testing ft_strlen();\n");
	do_test(CASE_1);
	do_test(CASE_2);
	do_test(CASE_3);
}
