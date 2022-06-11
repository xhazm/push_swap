/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:18:28 by lpfleide          #+#    #+#             */
/*   Updated: 2021/12/15 15:14:06 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_print_exec_operation(t_dll **main, t_dll **sec, int op, int stack)
{
	if (*main == NULL)
		return (FAIL);
	if (op == ROTATE)
	{
		ft_rotate_nodes(main);
		if (stack == STACK_BOTH)
			ft_rotate_nodes(sec);
	}
	else if (op == R_ROTATE)
	{
		ft_reverse_rotate_nodes(main);
		if (stack == STACK_BOTH)
			ft_reverse_rotate_nodes(sec);
	}
	else if (op == SWAP)
		ft_swap_node(main);
	else if (op == PUSH)
		ft_push_node(main, sec);
	if (op == R_ROTATE)
		ft_printf("rr%c\n", stack);
	else
		ft_printf("%c%c\n", (char)op, stack);
	return (SUCCESS);
}

static void	ft_execute_operations2(t_dll **astack, t_dll **bstack, t_rot *rtOP)
{
	while (rtOP->r[OP_A] > 0 || rtOP->rr[OP_A] > 0)
	{
		if (rtOP->r[OP_A] > 0)
			ft_print_exec_operation(astack, bstack, ROTATE, STACK_A);
		if (rtOP->rr[OP_A] > 0)
			ft_print_exec_operation(astack, bstack, R_ROTATE, STACK_A);
		rtOP->r[OP_A]--;
		rtOP->rr[OP_A]--;
	}
	while (rtOP->r[OP_B] > 0 || rtOP->rr[OP_B] > 0)
	{
		if (rtOP->r[OP_B] > 0)
			ft_print_exec_operation(bstack, astack, ROTATE, STACK_B);
		if (rtOP->rr[OP_B] > 0)
			ft_print_exec_operation(bstack, astack, R_ROTATE, STACK_B);
		rtOP->r[OP_B]--;
		rtOP->rr[OP_B]--;
	}
}

void	ft_execute_operations(t_dll **astack, t_dll **bstack, t_rot *rtOP)
{
	while (rtOP->rboth > 0 || rtOP->rrboth > 0)
	{
		if (rtOP->rboth > 0)
			ft_print_exec_operation(astack, bstack, ROTATE, STACK_BOTH);
		if (rtOP->rrboth > 0)
			ft_print_exec_operation(astack, bstack, R_ROTATE, STACK_BOTH);
		rtOP->rboth--;
		rtOP->rrboth--;
	}
	ft_execute_operations2(astack, bstack, rtOP);
}
