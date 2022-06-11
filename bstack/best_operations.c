/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:56:07 by lpfleide          #+#    #+#             */
/*   Updated: 2021/12/14 20:46:56 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_best_operations2(t_rot2 *r, t_rot *rot, t_rot *bestRot, char c)
{
	if (c == 'a')
	{
		bestRot->r[OP_A] = rot->r[OP_A];
		bestRot->rr[OP_B] = rot->rr[OP_B];
		bestRot->total = r->rarrb;
	}
	else if (c == 'b')
	{
		bestRot->rr[OP_A] = rot->rr[OP_A];
		bestRot->r[OP_B] = rot->r[OP_B];
		bestRot->total = r->rrarb;
	}
}

static void	ft_best_operations(t_rot2 *r, t_rot *rot, t_rot *bestRot, char c)
{
	if (c == 'r')
	{
		bestRot->r[OP_A] = rot->r[OP_A] - rot->rboth;
		bestRot->r[OP_B] = rot->r[OP_B] - rot->rboth;
		bestRot->rboth = rot->rboth;
		bestRot->total = r->r;
	}
	else if (c == 'R')
	{
		bestRot->rr[OP_A] = rot->rr[OP_A] - rot->rrboth;
		bestRot->rr[OP_B] = rot->rr[OP_B] - rot->rrboth;
		bestRot->rrboth = rot->rrboth;
		bestRot->total = r->rr;
	}
	else if (c == 'a' || c == 'b')
		ft_best_operations2(r, rot, bestRot, c);
}

void	ft_is_best_operations(t_rot *rot, t_rot *bestRot)
{
	t_rot2	r2;

	r2.r = 0;
	r2.rr = 0;
	r2.rarrb = 0;
	r2.rrarb = 0;
	if (rot->r[OP_A] < rot->rboth && rot->r[OP_B] < rot->rboth)
		rot->rboth++ ;
	if (rot->rr[OP_A] < rot->rrboth && rot->rr[OP_B] < rot->rrboth)
		rot->rrboth++ ;
	r2.r = (rot->r[OP_A] + rot->r[OP_B]) - rot->rboth;
	r2.rr = (rot->rr[OP_A] + rot->rr[OP_B]) - rot->rrboth;
	r2.rarrb = (rot->r[OP_A] + rot->rr[OP_B]);
	r2.rrarb = (rot->rr[OP_A] + rot->r[OP_B]);
	if (r2.r <= r2.rr && r2.r <= r2.rarrb && r2.r <= r2.rrarb)
		ft_best_operations(&r2, rot, bestRot, 'r');
	else if (r2.rr <= r2.r && r2.rr <= r2.rarrb && r2.rr <= r2.rrarb)
		ft_best_operations(&r2, rot, bestRot, 'R');
	else if (r2.rarrb <= r2.r && r2.rarrb <= r2.rr && r2.rarrb <= r2.rrarb)
		ft_best_operations(&r2, rot, bestRot, 'a');
	else if (r2.rrarb <= r2.r && r2.rrarb <= r2.rr && r2.rrarb <= r2.rarrb)
		ft_best_operations(&r2, rot, bestRot, 'b');
}
