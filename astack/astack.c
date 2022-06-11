/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:34:19 by lpfleide          #+#    #+#             */
/*   Updated: 2021/12/15 18:02:45 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_set_index_to_astack(t_dll **astack)
{
	int		i;
	t_dll	*searchNull;

	searchNull = *astack;
	i = 0;
	while (1)
	{
		searchNull = searchNull->next;
		i++;
		if (searchNull->index == 0)
			break ;
	}
	while ((*astack)->index != 0)
	{
		if (i <= (*(*astack)->asize) / 2)
			ft_print_exec_operation(astack, NULL, ROTATE, STACK_A);
		else
			ft_print_exec_operation(astack, NULL, R_ROTATE, STACK_A);
	}
}

/* searches for maxindex in stack, until checklength is reached.
	CheckLen = -1 if you dont need it. */
int	ft_is_maxindex(t_dll *iterNode, t_dll *end, int checkLen)
{
	t_dll	*start;
	int		maxIndex;

	start = iterNode;
	maxIndex = 0;
	while (checkLen <= -1 || checkLen > 0)
	{
		if (iterNode->index > maxIndex)
			maxIndex = iterNode->index;
		iterNode = iterNode->next;
		if (iterNode == end)
			break ;
		checkLen--;
	}
	iterNode = start;
	return (maxIndex);
}

static void	ft_make_chunks(t_dll **astack, t_dll **bstack)
{
	t_dll	*aStart;
	int		div;
	int		index;
	int		i;

	i = 1;
	if ((*(*astack)->asize) < 200)
		div = 3;
	else
		div = 4;
	index = (*(*astack)->asize) / div;
	aStart = *astack;
	while ((*(*astack)->asize) > 1)
	{
		if ((*astack)->index >= index * (i - 1)
			&& (*astack)->index <= index * i)
		{
			ft_print_exec_operation(astack, bstack, PUSH, STACK_B);
			(*(*astack)->asize)--;
		}
		else
			ft_print_exec_operation(astack, NULL, ROTATE, STACK_A);
		if ((*(*astack)->asize) == ((index * div) - (index * i)))
			i++;
	}
}

int	ft_check_and_push_lis(t_dll **astack, t_dll **bstack)
{
	t_dll	*LISnode;
	t_dll	**LISnodes;
	t_dll	*swapNode;

	LISnode = *astack;
	ft_lowest_increasing_subsequence(*astack, &LISnode, 0);
	LISnodes = malloc(sizeof(t_dll *) * LISnode->lis);
	if (LISnodes == NULL)
		return (FAIL);
	LISnodes[0] = LISnode;
	ft_set_LISnodes(*astack, *LISnode, LISnodes, &swapNode);
	if (swapNode && LISnode->swap >= 0)
		LISnode->swapNode = swapNode->prev;
	if ((*(*astack)->asize) <= 50)
		ft_push_lis_b(astack, bstack, LISnodes, LISnode);
	else
		ft_make_chunks(astack, bstack);
	free (LISnodes);
	return (0);
}
