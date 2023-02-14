/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:20:02 by rbicanic          #+#    #+#             */
/*   Updated: 2022/02/04 18:22:42 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **list, char *cmd_name, t_list **inst)
{
	t_list	*tmp;
	t_list	*last;

	last = ft_lstlast(*list);
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return ;
	ft_lstadd_back(inst, ft_lstnew_inst(cmd_name));
	tmp = (*list)->next;
	(*list)->before = last;
	(*list)->next = NULL;
	last->next = *list;
	tmp->before = NULL;
	*list = tmp;
}

void	ft_reverse_rotate(t_list **list, char *cmd_name, t_list **inst)
{
	t_list	*tmp;

	tmp = ft_lstlast(*list);
	if (list == NULL || *list == NULL || (*list)->next == NULL )
		return ;
	ft_lstadd_back(inst, ft_lstnew_inst(cmd_name));
	tmp->before->next = NULL;
	tmp->before = NULL;
	tmp->next = *list;
	(*list)->before = tmp;
	*list = tmp;
}

void	ft_push(t_list **dest, t_list **src, char *cmd_name, t_list **inst)
{
	t_list	*tmp;

	if (src == NULL || *src == NULL )
		return ;
	ft_lstadd_back(inst, ft_lstnew_inst(cmd_name));
	ft_lstadd_front(dest, ft_lstnew((*src)->content, (*src)->index));
	tmp = *src;
	*src = tmp->next;
	if (tmp->next != NULL)
		(*src)->before = NULL;
	free(tmp);
}

void	ft_swap(t_list **list, char *cmd_name, t_list **inst)
{
	t_list	*tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return ;
	tmp = (*list)->next;
	(*list)->next = tmp->next;
	(*list)->before = tmp;
	if (tmp->next != NULL)
		tmp->next->before = *list;
	tmp->next = *list;
	tmp->before = NULL;
	*list = tmp;
	ft_lstadd_back(inst, ft_lstnew_inst(cmd_name));
}

int	ft_atoi(const char *nptr)
{
	int			i;
	int			nbr;
	int			sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && (nptr[i] <= 13)))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + nptr[i] - 48;
		i++;
	}
	return (nbr * sign);
}
