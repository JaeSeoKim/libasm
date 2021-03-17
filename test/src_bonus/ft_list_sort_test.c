/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:56:16 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/16 21:46:31 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test_bonus.h"

static int	cmp(int *a, int *b)
{
	return (*a - *b);
}

static void	do_test_check(t_list *list)
{
	int		i;

	i = 0;
	while (++i < 10 && list)
	{
		if (*(int *)list->data != i)
		{
			printf("KO: diff expect %d, ft %d\n", i, *(int *)list->data);
			exit(1);
		}
		list = list->next;
	}
	if (list && i != 10)
	{
		printf("KO: diff end list %p, i %d\n", list, i);
		exit(1);
	}
}

static void	do_test(void)
{
	int		i;
	int		*n;
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->data = malloc(sizeof(int));
	*(int *)list->data = 1;
	list->next = 0;
	i = 1;
	while (++i < 10)
	{
		n = malloc(sizeof(int));
		*n = i;
		ft_list_push_front(&list, n);
	}
	ft_list_sort(&list, cmp);
	do_test_check(list);
	ft_lstclear(list, free);
}

void	ft_list_sort_test(void)
{
	printf("===================================================\n");
	printf("testing ft_list_sort();\n");
	do_test();
	printf("SUCCESS!\n");
}
