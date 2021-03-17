/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 21:37:28 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/17 21:07:09 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test_bonus.h"

static int	cmp(void *data, void *data_ref)
{
	if (*(int *)data == (int)data_ref)
		return (0);
	return (1);
}

static void	do_test_check(t_list *list, int n)
{
	int		i;

	i = 0;
	while (i++ < n && list)
	{
		if ((int)list->data == n / 3)
		{
			printf("KO: list contain %d\n", n / 3);
			exit(1);
		}
		list = list->next;
	}
	if (i != n + 1)
	{
		printf("KO: list contain %d\n", n / 3);
		exit(1);
	}
}

static void	do_test(long n)
{
	long	i;
	int		*num;
	t_list	*list;

	printf("try... list size %ld, ref %ld\n", n + 1, n / 3);
	list = malloc(sizeof(t_list));
	list->data = malloc(sizeof(int));
	*(int *)(list->data) = 0;
	list->next = 0;
	i = 0;
	while (i++ < n)
	{
		num = malloc(sizeof(int));
		*num = i;
		ft_list_push_front(&list, num);
	}
	ft_list_remove_if(&list, (void *)(n / 3), cmp, free);
	do_test_check(list, n);
	ft_lstclear(list, free);
}

void	ft_list_remove_if_test(void)
{
	int		i;

	printf("===================================================\n");
	printf("testing ft_list_remove_if();\n");
	i = 0;
	while (i < 10)
		do_test(i++);
	printf("SUCCESS!\n");
	printf("===================================================\n");
	printf("ft_list_remove_if(); leaks test\n");
	system("leaks ft_test");
	printf("===================================================\n");
}
