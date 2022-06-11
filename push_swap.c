/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:00:13 by lpfleide          #+#    #+#             */
/*   Updated: 2022/01/06 19:23:34 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_dll	*astack;
	t_dll	*bstack;
	int		stacksize;

	astack = NULL;
	bstack = NULL;
	stacksize = 0;
	if (argc < 2)
		return (0);
	if (ft_inputhandler(argc, argv, &astack, &stacksize) == FAIL)
	{
		ft_free_list(&astack);
		system ("leaks push_swap"); // why leak????
		write(2, "Error\n", 6);
		return (1);
	}
	if (!ft_is_sorted(astack))
	{
		ft_check_and_push_lis(&astack, &bstack);
		ft_push_partner(&astack, &bstack);
	}
	if ((*astack->asize) > 1)
		ft_set_index_to_astack(&astack);
	ft_free_list(&astack);
	ft_free_list(&bstack);
	return (0);
}

// ++ und -- abfangen
// leak split error
// empty string leak
// 
