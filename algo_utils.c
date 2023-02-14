/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:14:46 by rbicanic          #+#    #+#             */
/*   Updated: 2022/01/15 18:54:20 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	median(t_list **list, int len, int divider)
{
	t_list			*tmp;
	unsigned int	max;
	unsigned int	min;
	int				i;

	tmp = *list;
	max = tmp->index;
	min = tmp->index;
	i = 0;
	while (i < len && *list != NULL)
	{
		if (tmp->index > max)
			max = tmp->index;
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
		i++;
	}
	return (min + (max - min) / divider);
}

int	under_pivot_sorted(t_list **list, unsigned int pivot, int len)
{
	t_list	*tmp;

	tmp = *list;
	while (len > 0 && (*list)->next->next != NULL)
	{
		if (tmp->index < pivot)
			return (FALSE);
		tmp = tmp->next;
		len--;
	}
	return (TRUE);
}

int	over_pivot_sorted(t_list **list, unsigned int pivot, int len)
{
	t_list	*tmp;

	tmp = *list;
	while (len > 0 && (*list)->next->next != NULL)
	{
		if (tmp->index > pivot)
			return (FALSE);
		tmp = tmp->next;
		len--;
	}
	return (TRUE);
}

int	sort_left(t_list **src, t_list **dest, unsigned int pivot, t_list **com)
{
	if ((*src)->index < pivot)
	{
		ft_push(dest, src, "pb\n", com);
		if ((*dest)->index < ft_lstlast(*dest)->index)
			ft_rotate(dest, "rb\n", com);
		return (1);
	}
	else
		ft_rotate(src, "ra\n", com);
	return (0);
}

int	sort_right(t_list **src, t_list **dest, unsigned int pivot, t_list **com)
{
	if ((*src)->index > pivot)
	{
		ft_push(dest, src, "pa\n", com);
		return (0);
	}
	else
		ft_rotate(src, "rb\n", com);
	return (1);
}
