/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:24:56 by rbicanic          #+#    #+#             */
/*   Updated: 2022/02/02 18:09:07 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_swap_content(t_list *el_1, t_list *el_2)
{
	int	tmp;

	tmp = el_1->content;
	el_1->content = el_2->content;
	el_2->content = tmp;
}

void	lst_bubblesort(t_list **list_to_sort)
{
	t_list	*tmp;
	t_list	*tmp_sort;

	tmp = *list_to_sort;
	while (tmp != NULL)
	{
		tmp_sort = tmp->next;
		while (tmp_sort != NULL)
		{
			if (tmp_sort->content < tmp->content)
				ft_lst_swap_content(tmp, tmp_sort);
			tmp_sort = tmp_sort->next;
		}
		tmp = tmp->next;
	}
}

void	add_index(t_list **list_a, t_list **list_to_sort)
{
	unsigned int	i;
	t_list			*tmp;
	t_list			*tmp_sort;

	i = 0;
	tmp_sort = *list_to_sort;
	while (tmp_sort != NULL)
	{
		tmp = *list_a;
		while (tmp != NULL)
		{
			if (tmp->content == tmp_sort->content)
				tmp->index = i;
			tmp = tmp->next;
		}
		tmp_sort = tmp_sort->next;
		i++;
	}
}

void	lst_indexation(t_list **list_a)
{
	t_list			*tmp;
	t_list			**list_to_sort;

	list_to_sort = malloc(sizeof(t_list *));
	if (list_to_sort == NULL)
	{
		clear_all_lists(lsts()->list_a, lsts()->list_b, lsts()->inst);
		exit(EXIT_FAILURE);
	}
	tmp = *list_a;
	*list_to_sort = NULL;
	while (tmp != NULL)
	{
		ft_lstadd_back(list_to_sort, ft_lstnew(tmp->content, tmp->index));
		tmp = tmp->next;
	}
	lst_bubblesort(list_to_sort);
	add_index(list_a, list_to_sort);
	ft_lstclear(list_to_sort);
	free(list_to_sort);
}
