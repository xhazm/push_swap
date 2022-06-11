/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:27:53 by lpfleide          #+#    #+#             */
/*   Updated: 2021/12/15 13:01:30 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include <fcntl.h>

# define STACK_A 'a'
# define STACK_B 'b'
# define STACK_BOTH 'r'
# define OP_A 0
# define OP_B 1
# define OP_TOTAL 3
# define FAIL 0
# define SUCCESS 1
# define ROTATE 'r'
# define R_ROTATE 'e'
# define SWAP 's'
# define PUSH 'p'

typedef struct s_dll
{
	int				num;
	int				lis;
	int				swap;
	int				index;
	int				*asize;
	struct s_dll	*swapNode;
	struct s_dll	*next;
	struct s_dll	*prev;
	struct s_dll	*partner;
}					t_dll;

typedef struct s_rotate
{
	int			r[2];
	int			rr[2];
	int			rboth;
	int			rrboth;
	int			total;
}				t_rot;

typedef struct s_rotate2
{
	int			r;
	int			rr;
	int			rarrb;
	int			rrarb;
}				t_rot2;

void	ft_set_LISnodes(t_dll *stk, t_dll LISnode, t_dll **LIS, t_dll **swap);
int		ft_is_sorted(t_dll *astack);
int		ft_create_node(t_dll **list, int num, int *stacksize);
int		ft_attache_node(t_dll **list, t_dll *attache_node);
int		ft_detache_node(t_dll **list, t_dll *detache_node);
int		ft_swap_node(t_dll **list);
int		ft_push_node(t_dll **src, t_dll **dst);
int		ft_rotate_nodes(t_dll **list);
int		ft_reverse_rotate_nodes(t_dll **list);
int		ft_rotate_lists(t_dll **alist, t_dll **blist);
int		ft_reverse_rotate_lists(t_dll **alist, t_dll **blist);
int		ft_check_and_push_lis(t_dll **astack, t_dll **bstack);
void	ft_set_index_to_astack(t_dll **astack);
void	ft_lowest_increasing_subsequence(t_dll *list, t_dll **LISnode, int swp);
int		ft_inputhandler(int argc, char *argv[], t_dll **list, int *stacksize);
t_dll	*ft_find_least_operations(t_dll **astack, t_dll **bstack, t_rot **minR);
void	ft_execute_operations(t_dll **astack, t_dll **bstack, t_rot *rtOP);
int		ft_print_exec_operation(t_dll **main, t_dll **sec, int op, int stk);
int		ft_push_partner(t_dll **astack, t_dll **bstack);
int		ft_push_lis_b(t_dll **astack, t_dll **bstack, t_dll **LIS,
			t_dll *LISnode);
int		ft_is_LIS(t_dll *checkLIS, t_dll **LISnodes, t_dll LISnode);
int		ft_is_maxindex(t_dll *iterNode, t_dll *end, int checkLen);
void	ft_is_best_operations(t_rot *rot, t_rot *bestRot);
void	ft_free_list(t_dll **list);
int		main(int argc, char *argv[]);

#endif