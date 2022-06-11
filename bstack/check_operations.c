/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:15:15 by lpfleide          #+#    #+#             */
/*   Updated: 2021/12/14 20:47:05 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_rot_count(t_dll **stack, t_dll *checkOP, t_rot *rot, int opStk)
{
	t_dll	*tempOP;

	tempOP = checkOP;
	while (*stack != checkOP)
	{
		checkOP = checkOP->prev;
		rot->r[opStk]++;
	}
	checkOP = tempOP;
	while (*stack != checkOP)
	{
		checkOP = checkOP->next;
		rot->rr[opStk]++;
	}
}

static void	ft_set_rot_zero(t_rot *rot)
{
	rot->r[0] = 0;
	rot->r[1] = 0;
	rot->rr[0] = 0;
	rot->rr[1] = 0;
	rot->rboth = 0;
	rot->rrboth = 0;
	rot->total = 0;
}

static int	ft_operations(t_dll **astk, t_dll **bstk, t_dll *B, t_rot *topRot)
{
	t_rot	checkRot;
	t_dll	*A;

	A = B->partner;
	ft_set_rot_zero(&checkRot);
	ft_rot_count(astk, A, &checkRot, OP_A);
	ft_rot_count(bstk, B, &checkRot, OP_B);
	ft_is_best_operations(&checkRot, topRot);
	return (topRot->total);
}

t_dll	*ft_find_least_operations(t_dll **astack, t_dll **bstack, t_rot **minR)
{
	t_rot	rot;
	t_dll	*leastRotations;
	t_dll	*Apartner;
	t_dll	*Bpartner;

	leastRotations = *bstack;
	Bpartner = *bstack;
	while (1)
	{
		Apartner = Bpartner->partner;
		ft_set_rot_zero(&rot);
		ft_operations(astack, bstack, Bpartner, &rot);
		if (rot.total < (*minR)->total || Bpartner == *bstack)
		{
			**minR = rot;
			leastRotations = Bpartner;
			ft_set_rot_zero(&rot);
		}
		else
			Bpartner->partner = NULL;
		Bpartner = Bpartner->next;
		if (Bpartner == *bstack)
			break ;
	}
	return (leastRotations);
}
