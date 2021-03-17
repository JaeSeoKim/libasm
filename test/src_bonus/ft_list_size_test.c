/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 05:35:17 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/16 21:31:17 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test_bonus.h"

static void	noting(void *c)
{
	if (c)
		return ;
}

static void	malloc_fail(void)
{
	printf("malloc_fail....\n");
	exit(1);
}

static void	do_test(int	n)
{
	int		i;
	t_list	*list;
	int		list_size;

	printf("try... ft_list_size(list_size_%d);\n", n);
	list = 0;
	if (n > 0)
	{
		list = malloc(sizeof(t_list));
		if (list == NULL)
			malloc_fail();
		list->next = NULL;
	}
	i = 0;
	while (i < n - 1)
		ft_list_push_front(&list, g_string[i++]);
	list_size = ft_list_size(list);
	if (list_size != n)
	{
		printf("KO: diff ft_list_size: %d, real_size %d\n", list_size, n);
		exit(1);
	}
	ft_lstclear(list, noting);
}

void	ft_list_size_test(void)
{
	int	i;

	printf("===================================================\n");
	printf("testing ft_list_size();\n");
	i = 0;
	while (i < 10)
		do_test(i++);
	printf("SUCCESS!\n");
}
