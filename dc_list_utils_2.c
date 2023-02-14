/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dc_list_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:42:56 by rbicanic          #+#    #+#             */
/*   Updated: 2022/02/04 18:22:50 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstlen(t_list *lst)
{
	int		len;
	t_list	*tmp;

	len = 1;
	tmp = lst;
	if (tmp == NULL)
		return (0);
	while (tmp->next != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}

int	is_sorted(t_list **list_a)
{
	t_list	*tmp;

	tmp = *list_a;
	while (tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

t_list	*ft_lstnew_inst(char *inst)
{
	t_list	*newlst;
	int		i;

	i = 0;
	newlst = malloc(sizeof(t_list));
	if (newlst == NULL)
	{
		clear_all_lists(lsts()->list_a, lsts()->list_b, lsts()->inst);
		exit(EXIT_FAILURE);
	}
	while (inst[i])
	{
		newlst->cmd[i] = inst[i];
		i++;
	}
	newlst->cmd[i] = '\0';
	newlst->next = NULL;
	newlst->before = NULL;
	return (newlst);
}
