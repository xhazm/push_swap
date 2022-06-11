/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:41:35 by lpfleide          #+#    #+#             */
/*   Updated: 2022/01/06 19:06:27 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_is_smallest_index(t_dll *astack, t_dll **indexNode)
{
	t_dll	*aStart;
	t_dll	*nextIndex;
	int		smallestIndex;

	aStart = astack;
	smallestIndex = 0;
	*indexNode = astack;
	while (1)
	{
		nextIndex = astack->next;
		if (astack->index < nextIndex->index)
			*indexNode = astack;
		astack = astack->next;
		if (aStart == astack)
			break ;
	}
}

int	ft_is_sorted(t_dll *astack)
{
	t_dll	*indexNode;
	t_dll	*nextIndex;
	int		start;

	if ((*astack->asize) == 1)
		return (SUCCESS);
	start = 0;
	indexNode = NULL;
	nextIndex = NULL;
	ft_is_smallest_index(astack, &indexNode);
	indexNode = astack;
	while (1)
	{
		nextIndex = astack->next;
		if (astack->index > nextIndex->index)
			start++;
		astack = astack->next;
		if (astack == indexNode)
			break ;
	}
	if (start > 1)
		return (FAIL);
	else
		return (SUCCESS);
}

/*	sets index of nodes, depending on their num relative to
other nums in the list. 0 to n-1. Returns 1 at doublicated numbers */
static int	ft_set_index(t_dll **list, t_dll *node)
{
	t_dll	*iterate_node;
	int		index;

	while (1)
	{
		index = 0;
		iterate_node = node->next;
		while (1)
		{
			if (node->num > iterate_node->num)
				index++;
			else if (node->num == iterate_node->num)
				return (1);
			iterate_node = iterate_node->next;
			if (node == iterate_node)
			{
				node->index = index;
				break ;
			}
		}
		node = node->next;
		if (node == *list)
			break ;
	}
	return (0);
}

/* splits a str of multiple numbers at whitespaces to multiple nodes*/
static int	ft_split_argv(char *str, t_dll **list, int stacksize[2])
{
	char	**split;
	int		num;
	int		i;

	i = 0;
	split = ft_split(str, ' ');
	if (split[i] == NULL)
		return (FAIL);
	while (split[i] != NULL)
	{
		if (ft_str_isnum(split[i]))
		{
			num = ft_atoi(split[i]);
			if (num > INT_MAX || num < INT_MIN)
				return (FAIL);
			ft_create_node(list, (int)num, stacksize);
		}
		else
			return (FAIL);
		i++;
	}
	ft_free2darr((void **)split);
	return (SUCCESS);
}

/* creates circular doubly linked list nodes for nums given and sets indices */
int	ft_inputhandler(int argc, char *argv[], t_dll **list, int *stacksize)
{
	int		i;
	long	num;

	i = 1;
	while (argc > i)
	{
		if (ft_str_isnum(argv[i]))
		{
			num = ft_atoi(argv[i]);
			if (num > INT_MAX || num < INT_MIN
				|| ft_create_node(list, (int)num, stacksize) == FAIL)
				return (FAIL);
			if (argc <= 2)
				return (SUCCESS);
		}
		else if (ft_split_argv(argv[i], list, stacksize) == FAIL)
			return (FAIL);
		i++;
	}
	if (ft_set_index(list, *list))
		return (FAIL);
	if (ft_is_sorted(*list) && list[0]->index == 0)
		return (SUCCESS);
	return (SUCCESS);
}
