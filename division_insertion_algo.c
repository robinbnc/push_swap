/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   division_insertion_algo.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:14:46 by rbicanic          #+#    #+#             */
/*   Updated: 2022/01/16 19:24:58 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	position_of_index(unsigned int ind, t_list **lst)
{
	int		i;
	t_list	*tmp;

	tmp = *lst;
	i = 0;
	while (tmp->index != ind)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	first_clean_large_stack(t_list **list_a, t_list **list_b, t_list **com)
{
	unsigned int	pivot;

	pivot = median(list_a, ft_lstlen(*list_a), 3);
	while (!under_pivot_sorted(list_a, pivot, ft_lstlen(*list_a)))
		sort_left(list_a, list_b, pivot, com);
	while (ft_lstlen(*list_b) > 3)
	{
		pivot = median(list_b, ft_lstlen(*list_b), 2);
		while (!over_pivot_sorted(list_b, pivot, ft_lstlen(*list_b)))
			sort_right(list_b, list_a, pivot, com);
	}
}

void	division_sort(t_list **a, t_list **b, int div, t_list **com)
{
	unsigned int	pivot;
	unsigned int	lst_len;

	lst_len = ft_lstlen(*a) + ft_lstlen(*b);
	while (ft_lstlen(*a) > div)
	{
		pivot = median(a, ft_lstlen(*a), div);
		while (!under_pivot_sorted(a, pivot, ft_lstlen(*a)))
			sort_left(a, b, pivot, com);
	}
	if (lst_len > 200)
		five_numbers_algo(a, b, com);
	else
		three_el_algo_opti(a, com);
	while (*b != NULL && (*b)->index == (*a)->index - 1)
	{
		ft_push(a, b, "pa\n", com);
		if ((*a)->index > (*a)->next->index)
			ft_swap(a, "sa\n", com);
		div--;
	}
}

void	insertion_sort(t_list **a, t_list **b, unsigned int m, t_list **com)
{
	while ((*a)->index != m && (*a)->next->index != m
		&& (*a)->next->next->index != m
		&& (*a)->next->next->next->index != m)
	{
		if ((*b)->index == m - 3 || (*b)->index == m - 2)
		{
			ft_push(a, b, "pa\n", com);
			ft_rotate(a, "ra\n", com);
		}
		else if ((*b)->index == m || (*b)->index == m - 1)
		{
			ft_push(a, b, "pa\n", com);
			three_el_algo(a, b, com);
		}
		else
		{
			if (position_of_index(m, b) < ft_lstlen(*b) / 2)
				ft_rotate(b, "rb\n", com);
			else
				ft_reverse_rotate(b, "rrb\n", com);
		}
	}
}

void	quick_sort(t_list **a, t_list **b, unsigned int lst_len, t_list **com)
{
	unsigned int	min;

	if (lst_len > 200)
	{
		first_clean_large_stack(a, b, com);
		division_sort(a, b, 4, com);
	}
	else
		division_sort(a, b, 3, com);
	min = (*a)->index;
	while (*b != NULL)
	{
		min--;
		insertion_sort(a, b, min, com);
		while (ft_lstlast(*a)->index != lst_len - 1)
		{
			if (ft_lstlast(*a)->index == min - 3
				|| ft_lstlast(*a)->index == min - 2)
				ft_reverse_rotate(a, "rra\n", com);
			if ((*a)->index > (*a)->next->index)
				ft_swap(a, "sa\n", com);
		}
	}
}
