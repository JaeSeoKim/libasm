/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 03:11:03 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/16 21:37:23 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TEST_BONUS_H
# define FT_TEST_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

extern char	*g_string[10];

int		atoi_base(char *str, char *base);
int		ft_atoi_base(char *str, char *base);
void	ft_atoi_base_test(void);

void	ft_lstclear(t_list *lst, void (*del)(void *));

void	ft_list_push_front(t_list **begin_list, void *data);
void	ft_list_push_front_test(void);

int		ft_list_size(t_list *begin_list);
void	ft_list_size_test(void);

void	ft_list_sort(t_list **begin_list, int (*cmp)());
void	ft_list_sort_test(void);

void	ft_list_remove_if(
			t_list **begin_list,
			void *data_ref,
			int (*cmp)(),
			void (*free_fct)(void *));
void	ft_list_remove_if_test(void);

#endif
