/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_first_el_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:12:30 by rbicanic          #+#    #+#             */
/*   Updated: 2022/02/07 14:07:31 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_case_three_el(t_list **list_a, t_list **list_b, t_list **com)
{
	ft_push(list_b, list_a, "pb\n", com);
	ft_swap(list_a, "sa\n", com);
	ft_push(list_a, list_b, "pa\n", com);
}

void	second_case_three_el(t_list **list_a, t_list **list_b, t_list **com)
{
	ft_push(list_b, list_a, "pb\n", com);
	ft_swap(list_a, "sa\n", com);
	ft_push(list_a, list_b, "pa\n", com);
	ft_swap(list_a, "sa\n", com);
}

void	third_case_three_el(t_list **list_a, t_list **list_b, t_list **com)
{
	ft_swap(list_a, "sa\n", com);
	ft_push(list_b, list_a, "pb\n", com);
	ft_swap(list_a, "sa\n", com);
	ft_push(list_a, list_b, "pa\n", com);
}

void	three_el_algo(t_list **list_a, t_list **list_b, t_list **com)
{
	unsigned int	first;
	unsigned int	second;
	unsigned int	third;

	first = (*list_a)->index;
	second = (*list_a)->next->index;
	third = (*list_a)->next->next->index;
	if (first < second && second > third && first < third)
		first_case_three_el(list_a, list_b, com);
	else if (first > second && second < third && first < third)
		ft_swap(list_a, "sa\n", com);
	else if (first < second && second > third && first > third)
		second_case_three_el(list_a, list_b, com);
	else if (first > second && second < third && first > third)
		third_case_three_el(list_a, list_b, com);
	else if (first > second && second > third && first > third)
	{
		ft_swap(list_a, "sa\n", com);
		ft_push(list_b, list_a, "pb\n", com);
		ft_swap(list_a, "sa\n", com);
		ft_push(list_a, list_b, "pa\n", com);
		ft_swap(list_a, "sa\n", com);
	}
}

int	ft_is_numeric(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}
