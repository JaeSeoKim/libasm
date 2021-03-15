/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 04:29:50 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/16 05:20:59 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test_bonus.h"

static void	malloc_fail(void)
{
	printf("malloc_fail....\n");
	exit(1);
}

static void	do_test(void)
{
	const char	*data = "data";
	t_list		*list;
	t_list		*list_old;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		malloc_fail();
	list_old = list;
	list->next = 0;
	ft_list_push_front(&list, (void *)data);
	if (list == list_old || list->data != data || list->next != list_old)
	{
		printf("KO: diff ori list %p, list %p, list->next %p\n",
			list_old, list, list->next);
		printf("data %p, list->data %p\n",
			data, list->data);
		exit(1);
	}
}

void	ft_list_push_front_test(void)
{
	printf("===================================================\n");
	printf("testing ft_list_push_front();\n");
	do_test();
	printf("SUCCESS!\n");
}
