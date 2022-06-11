/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:59:00 by lpfleide          #+#    #+#             */
/*   Updated: 2021/10/28 21:59:15 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_remalloc(void **arr, int len)
{
	void	**newarr;

	newarr = malloc(sizeof(char *) * len);
	if (newarr == 0)
		return ;
	ft_memcpy(newarr, arr, len);
	free(arr);
	arr = newarr;
}
