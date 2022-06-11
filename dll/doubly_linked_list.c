/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:38:48 by lpfleide          #+#    #+#             */
/*   Updated: 2021/12/14 20:58:40 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_attache_node(t_dll **list, t_dll *attache_node)
{
	t_dll	*prev_node;
	t_dll	*next_node;

	if (*list == NULL)
	{
		prev_node = attache_node;
		next_node = attache_node;
	}
	else
	{
		next_node = *list;
		prev_node = (*list)->prev;
		prev_node->next = attache_node;
		next_node->prev = attache_node;
	}
	attache_node->next = next_node;
	attache_node->prev = prev_node;
	*list = attache_node;
	return (0);
}

int	ft_detache_node(t_dll **list, t_dll *detache_node)
{
	t_dll	*prev_node;
	t_dll	*next_node;

	prev_node = detache_node->prev;
	next_node = detache_node->next;
	if (detache_node->next == detache_node)
		*list = NULL;
	else
		*list = next_node;
	detache_node->next = NULL;
	detache_node->prev = NULL;
	if (detache_node != next_node && detache_node != prev_node)
	{
		prev_node->next = next_node;
		next_node->prev = prev_node;
	}
	else
		*list = NULL;
	return (0);
}

static int	ft_init_node(t_dll *node, int num, int *asize)
{
	if (node == NULL)
		return (FAIL);
	node->asize = asize;
	node->num = num;
	node->swap = -1;
	return (SUCCESS);
}

void	ft_free_list(t_dll **list)
{
	t_dll	*freeNode;

	if (list == NULL)
		return ;
	while (*list != NULL)
	{
		if ((*list)->next == *list || (*list)->next == NULL)
		{
			free (*list);
			list = NULL;
			return ;
		}
		else
		{
			freeNode = *list;
			ft_detache_node(list, freeNode);
			free (freeNode);
		}
	}	
}

/* creates node, sets it as the first element of the list */
int	ft_create_node(t_dll **list, int num, int *astacksize)
{
	t_dll	*node;
	t_dll	*prev_node;

	prev_node = *list;
	node = ft_calloc(1, sizeof(t_dll) * 1);
	if (ft_init_node(node, num, astacksize) == FAIL)
		return (FAIL);
	if (*list == NULL)
		*list = node;
	else
	{
		node->next = *list;
		(*list)->prev = node;
		if (prev_node->next == NULL)
			prev_node->next = node;
		else
		{
			while (prev_node->next != *list)
				prev_node = prev_node->next;
			prev_node->next = node;
		}
		node->prev = prev_node;
	}
	(*node->asize)++;
	return (SUCCESS);
}
