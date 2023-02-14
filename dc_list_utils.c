/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dc_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:42:56 by rbicanic          #+#    #+#             */
/*   Updated: 2022/02/02 18:21:40 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = ft_lstlast(*alst);
	if (tmp == NULL)
		*alst = new;
	else
	{
		tmp->next = new;
		new->before = tmp;
	}
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	if (!(*alst == NULL || alst == NULL))
		new->next->before = new;
	*alst = new;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (tmp == NULL)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

t_list	*ft_lstnew(int content, int index)
{
	t_list	*newlst;

	newlst = malloc(sizeof(t_list));
	if (newlst == NULL)
	{
		clear_all_lists(lsts()->list_a, lsts()->list_b, lsts()->inst);
		exit(EXIT_FAILURE);
	}
	newlst->content = content;
	newlst->index = index;
	newlst->next = NULL;
	newlst->before = NULL;
	return (newlst);
}
