/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:30:57 by lpfleide          #+#    #+#             */
/*   Updated: 2021/12/14 20:46:47 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_set_LISnodes(t_dll *stk, t_dll LISnode, t_dll **LIS, t_dll **swap)
{
	t_dll	*iterateLIS;

	*swap = NULL;
	iterateLIS = LIS[0];
	while (LISnode.swap >= 0)
	{
		if (LISnode.swap == 0)
			ft_swap_node(&stk);
		*swap = stk;
		stk = stk->next;
		LISnode.swap--;
	}
	while (LISnode.lis > 0)
	{
		LIS[LISnode.lis - 1] = iterateLIS;
		iterateLIS = iterateLIS->next;
		LISnode.lis--;
	}
	if (*swap)
	{
		stk = *swap;
		ft_swap_node(&stk);
	}
}

static void	ft_check_for_lis(t_dll *list, t_dll **LISnode, int swap, int i)
{
	t_dll	*LIStest;
	t_dll	*num;
	t_dll	*nextnum;

	LIStest = list;
	while (1)
	{
		i = 1;
		num = LIStest;
		nextnum = num->next;
		while ((num->index < nextnum->index) && nextnum != LIStest && i++)
		{
			num = num->next;
			nextnum = num->next;
		}
		if (i > (*LISnode)->lis)
		{
			(*LISnode) = LIStest;
			(*LISnode)->lis = i;
			(*LISnode)->swap = swap - 1;
		}
		LIStest = LIStest->next;
		if (list == LIStest)
			break ;
	}
}

void	ft_lowest_increasing_subsequence(t_dll *list, t_dll **LISnode, int swp)
{
	t_dll	*LIScheck;
	t_dll	*swapNode;
	t_dll	*aStart;

	LIScheck = list;
	swapNode = list;
	aStart = list;
	while (1)
	{
		if ((*LISnode)->lis > 0 && list == aStart)
		{
			ft_swap_node(&swapNode);
			swp++;
		}
		ft_check_for_lis(list, LISnode, swp, 1);
		if (swp && list == LIScheck->prev)
		{
			ft_swap_node(&swapNode);
			LIScheck = LIScheck->next;
			swapNode = swapNode->next;
		}
		list = list->next;
		if (list == aStart && swp == (*aStart->asize) - 1)
			break ;
	}
}
