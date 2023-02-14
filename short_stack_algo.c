/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_stack_algo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:40:27 by rbicanic          #+#    #+#             */
/*   Updated: 2022/02/04 18:18:32 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_el_algo_opti(t_list **list_a, t_list **com)
{
	unsigned int	first;
	unsigned int	second;
	unsigned int	third;

	first = (*list_a)->index;
	second = (*list_a)->next->index;
	third = (*list_a)->next->next->index;
	if (first < second && second > third && first < third)
	{
		ft_reverse_rotate(list_a, "rra\n", com);
		ft_swap(list_a, "sa\n", com);
	}
	else if (first > second && second < third && first < third)
		ft_swap(list_a, "sa\n", com);
	else if (first < second && second > third && first > third)
		ft_reverse_rotate(list_a, "rra\n", com);
	else if (first > second && second < third && first > third)
		ft_rotate(list_a, "ra\n", com);
	else if (first > second && second > third && first > third)
	{
		ft_rotate(list_a, "ra\n", com);
		ft_swap(list_a, "sa\n", com);
	}
}

void	put_el_to_top(t_list **list_src, int mooves, t_list **com)
{
	if (mooves < 0)
	{
		while (mooves < 0)
		{
			ft_reverse_rotate(list_src, "rra\n", com);
			mooves++;
		}
	}
	else
	{
		while (mooves > 0)
		{
			ft_rotate(list_src, "ra\n", com);
			mooves--;
		}
	}
}

int	ft_abs(int mooves)
{
	if (mooves < 0)
		return (-mooves);
	return (mooves);
}

void	sort_five(t_list **src, t_list **dest, unsigned int pivot, t_list **com)
{
	int		i;
	int		mooves;
	t_list	*tmp;

	tmp = *src;
	i = 0;
	mooves = ft_lstlen(*src);
	while (tmp != NULL)
	{
		if (tmp->index < pivot)
		{
			if (i < (ft_abs(mooves)))
				mooves = i;
			else if (ft_lstlen(*src) - i < (ft_abs(mooves)))
				mooves = i - ft_lstlen(*src);
		}
		tmp = tmp->next;
		i++;
	}
	put_el_to_top(src, mooves, com);
	ft_push(dest, src, "pb\n", com);
}

void	five_numbers_algo(t_list **list_a, t_list **list_b, t_list **com)
{
	unsigned int	mediane;

	mediane = median(list_a, ft_lstlen(*list_a), 2);
	while (ft_lstlen(*list_a) > 3)
		sort_five(list_a, list_b, mediane, com);
	three_el_algo_opti(list_a, com);
	ft_push(list_a, list_b, "pa\n", com);
	if (*list_b != NULL)
		ft_push(list_a, list_b, "pa\n", com);
	if ((*list_a)->index > (*list_a)->next->index)
		ft_swap(list_a, "sa\n", com);
}
