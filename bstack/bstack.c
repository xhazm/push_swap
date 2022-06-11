/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bstack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:03:29 by lpfleide          #+#    #+#             */
/*   Updated: 2021/12/14 20:47:02 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_is_partner(t_dll **astack, int maxindex,
							t_dll *ApartnerCheck, t_dll *BpartnerCheck)
{
	int	i;

	if (BpartnerCheck->index == 0)
	{
		while (ApartnerCheck->index < maxindex)
			ApartnerCheck = ApartnerCheck->next;
		BpartnerCheck->partner = ApartnerCheck->next;
	}
	else
	{
		i = 0;
		ApartnerCheck = *astack;
		while (BpartnerCheck->index != ApartnerCheck->index - i)
		{
			ApartnerCheck = ApartnerCheck->next;
			if (ApartnerCheck == *astack)
				i++;
		}
		BpartnerCheck->partner = ApartnerCheck;
	}
}

static void	ft_search_partner(t_dll **astack, t_dll **bstack,
								t_dll *ApartnerCheck, t_dll *BpartnerCheck)
{
	t_dll	*AnullNode;
	int		maxindex;

	AnullNode = *astack;
	maxindex = ft_is_maxindex(ApartnerCheck, *astack, -1);
	while (1)
	{
		if (ApartnerCheck->index < AnullNode->index)
			AnullNode = ApartnerCheck;
		ApartnerCheck = ApartnerCheck->next;
		if (ApartnerCheck == *astack)
			break ;
	}
	while (1)
	{
		ApartnerCheck = *astack;
		if (BpartnerCheck->index > maxindex)
			BpartnerCheck->partner = AnullNode;
		else
			ft_is_partner(astack, maxindex, ApartnerCheck, BpartnerCheck);
		BpartnerCheck = BpartnerCheck->next;
		if (BpartnerCheck == *bstack)
			break ;
	}
}

static void	ft_push_least_operations(t_dll **astack, t_dll **bstack)
{
	t_dll		*pushNode;
	t_rot		*rotateOperations;

	rotateOperations = ft_calloc(1, sizeof(t_rot));
	pushNode = ft_find_least_operations(astack, bstack, &rotateOperations);
	ft_execute_operations(astack, bstack, rotateOperations);
	free(rotateOperations);
	ft_print_exec_operation(bstack, astack, PUSH, STACK_A);
	(*(*astack)->asize)++;
}

int	ft_push_partner(t_dll **astack, t_dll **bstack)
{
	t_dll	*ApartnerCheck;
	t_dll	*BpartnerCheck;

	if (*bstack == NULL)
		return (FAIL);
	while (1)
	{
		ApartnerCheck = *astack;
		BpartnerCheck = *bstack;
		ft_search_partner(astack, bstack, ApartnerCheck, BpartnerCheck);
		ft_push_least_operations(astack, bstack);
		if (*bstack == NULL)
			break ;
	}
	return (SUCCESS);
}
