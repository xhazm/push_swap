/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_lis_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:32:47 by lpfleide          #+#    #+#             */
/*   Updated: 2021/12/15 18:31:08 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_LIS(t_dll *checkLIS, t_dll **LISnodes, t_dll LISnode)
{
	while (LISnode.lis > 0)
	{
		if (checkLIS == LISnodes[LISnode.lis - 1])
			return (SUCCESS);
		LISnode.lis--;
	}
	return (FAIL);
}

static void	ft_define_rot(t_dll **a, t_dll **b, t_dll **LIS, t_dll *LISnode)
{
	t_dll	*astart;
	int		r;
	int		rr;
	int		rotate;

	astart = *a;
	rotate = ROTATE;
	r = 0;
	rr = 0;
	while (ft_is_LIS(*a, LIS, *LISnode) && (*(*a)->asize) > LISnode->lis)
	{
		*a = (*a)->prev;
		rr++;
	}
	*a = astart;
	while (ft_is_LIS(*a, LIS, *LISnode) && (*(*a)->asize) > LISnode->lis)
	{
		*a = (*a)->next;
		r++;
		if (r > rr)
			rotate = R_ROTATE;
	}
	*a = astart;
	ft_print_exec_operation(a, b, rotate, STACK_A);
}

int	ft_push_lis_b(t_dll **astack, t_dll **bstack, t_dll **LIS, t_dll *LISnode)
{
	int		maxIndex;

	maxIndex = ft_is_maxindex(*astack, *astack, -1);
	while (!ft_is_sorted(*astack))
	{
		if (LISnode->swapNode == *astack && LISnode->swap != -1)
		{
			ft_print_exec_operation(astack, bstack, SWAP, STACK_A);
			LISnode->swap = -1;
			continue ;
		}
		if (ft_is_LIS(*astack, LIS, *LISnode) && LISnode->swap == -1)
			ft_define_rot(astack, bstack, LIS, LISnode);
		else if (ft_is_LIS(*astack, LIS, *LISnode) && LISnode->swap >= 0)
			ft_print_exec_operation(astack, NULL, ROTATE, STACK_A);
		else if (!ft_is_LIS(*astack, LIS, *LISnode))
		{
			ft_print_exec_operation(astack, bstack, PUSH, STACK_B);
			(*LISnode->asize)--;
		}
		if ((LISnode->swap == -1 && (*LISnode->asize) <= LISnode->lis))
			break ;
	}
	return (0);
}
