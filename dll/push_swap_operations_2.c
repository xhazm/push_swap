/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:38:48 by lpfleide          #+#    #+#             */
/*   Updated: 2021/12/14 20:47:17 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* swaps the first two elements of a list */
int	ft_swap_node(t_dll **list)
{
	t_dll	*swap_node;

	if ((*list)->next == NULL)
		return (1);
	swap_node = *list;
	ft_detache_node(list, swap_node);
	*list = (*list)->next;
	ft_attache_node(list, swap_node);
	*list = (*list)->prev;
	return (0);
}

/* pushes first element from src list and set it as first at dest list */
int	ft_push_node(t_dll **src, t_dll **dest)
{
	t_dll	*push_node;

	if (*src == NULL)
		return (1);
	push_node = *src;
	ft_detache_node(src, push_node);
	ft_attache_node(dest, push_node);
	return (0);
}
