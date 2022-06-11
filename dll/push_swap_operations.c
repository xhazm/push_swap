/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:38:48 by lpfleide          #+#    #+#             */
/*   Updated: 2021/12/14 20:47:19 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* rotates the elements of a list one up */
int	ft_rotate_nodes(t_dll **list)
{
	if (*list == NULL)
		return (1);
	*list = (*list)->next;
	return (0);
}

/* rotates the elements of a list one down */
int	ft_reverse_rotate_nodes(t_dll **list)
{
	if (*list == NULL)
		return (1);
	*list = (*list)->prev;
	return (0);
}

/* rotates the elements of two list one up */
int	ft_rotate_lists(t_dll **alist, t_dll **blist)
{
	if (*alist == NULL || *blist == NULL)
		return (1);
	*alist = (*alist)->next;
	*blist = (*blist)->next;
	return (0);
}

/* rotates the elements of two list one down */
int	ft_reverse_rotate_lists(t_dll **alist, t_dll **blist)
{
	if (*alist == NULL || *blist == NULL)
		return (1);
	*alist = (*alist)->prev;
	*blist = (*blist)->prev;
	return (0);
}
