/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:45:14 by lpfleide          #+#    #+#             */
/*   Updated: 2022/01/06 19:11:24 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_double_rot(t_dll **astack, t_dll **bstack, char *op)
{
	if (ft_memcmp(op, "rr\n", 3) == 0)
	{
		ft_rotate_nodes(astack);
		ft_rotate_nodes(bstack);
	}
	else if (ft_memcmp(op, "rrr\n", 4) == 0)
	{
		ft_reverse_rotate_nodes(astack);
		ft_reverse_rotate_nodes(bstack);
	}
}

static int	ft_do_operation(t_dll **astack, t_dll **bstack, char *op)
{
	if (ft_memcmp(op, "ra\n", 3) == 0)
		ft_rotate_nodes(astack);
	else if (ft_memcmp(op, "rb\n", 3) == 0)
		ft_rotate_nodes(bstack);
	else if (ft_memcmp(op, "rra\n", 4) == 0)
		ft_reverse_rotate_nodes(astack);
	else if (ft_memcmp(op, "rrb\n", 4) == 0)
		ft_reverse_rotate_nodes(bstack);
	else if (ft_memcmp(op, "rr\n", 3) == 0)
		ft_double_rot(astack, bstack, op);
	else if (ft_memcmp(op, "rrr\n", 4) == 0)
		ft_double_rot(astack, bstack, op);
	else if (ft_memcmp(op, "sa\n", 3) == 0)
		ft_swap_node(astack);
	else if (ft_memcmp(op, "sb\n", 3) == 0)
		ft_swap_node(bstack);
	else if (ft_memcmp(op, "pa\n", 3) == 0)
		ft_push_node(bstack, astack);
	else if (ft_memcmp(op, "pb\n", 3) == 0)
		ft_push_node(astack, bstack);
	else
		return (FAIL);
	return (SUCCESS);
}

static int	ft_is_indexsorted(t_dll **astack, t_dll **bstack)
{
	char	*operation;

	operation = NULL;
	while (1)
	{
		operation = get_next_line(0);
		if (operation == NULL)
		{
			free(operation);
			break ;
		}
		if (ft_do_operation(astack, bstack, operation) == FAIL)
			return (2);
		free(operation);
	}
	if (ft_is_sorted(*astack) && *bstack == NULL && (*astack[0]).index == 0)
		return (SUCCESS);
	else
		return (FAIL);
}

int	main(int argc, char *argv[])
{
	t_dll	*astack;
	t_dll	*bstack;
	int		stacksize;
	int		checkValue;

	astack = NULL;
	bstack = NULL;
	stacksize = 0;
	if (argc < 2)
		return (0);
	if (ft_inputhandler(argc, argv, &astack, &stacksize) == FAIL)
	{
		ft_free_list(&astack);
		write(2, "Error\n", 6);
		return (1);
	}
	checkValue = ft_is_indexsorted(&astack, &bstack);
	if (checkValue == SUCCESS)
		write(1, "OK\n", 3);
	else if (checkValue == FAIL)
		write(1, "KO\n", 3);
	else if (checkValue == 2)
		write(2, "Error\n", 6);
	ft_free_list(&astack);
	ft_free_list(&bstack);
	return (0);
}
