/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 03:11:03 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/15 21:37:13 by jaeskim          ###   ########.fr       */
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

#endif