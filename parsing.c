/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:47:44 by rbicanic          #+#    #+#             */
/*   Updated: 2022/02/07 14:10:46 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_over_max(const char *nptr, int sign)
{
	int	len;

	len = 0;
	while (nptr[len] && nptr[len] >= '0' && nptr[len] <= '9')
		len++;
	if (len > 10)
		return (TRUE);
	else if (len > 8 && sign > 0
		&& ft_strncmp("2147483647", nptr, len) < 0)
		return (TRUE);
	else if (len > 8 && sign < 0
		&& ft_strncmp("2147483648", nptr, len) < 0)
		return (TRUE);
	else
		return (FALSE);
}

int	is_correct_nbr(char *nptr)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && (nptr[i] <= 13)))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	if (nptr[i] >= '0' && nptr[i] <= '9' && !is_over_max(&nptr[i], sign)
		&& ft_is_numeric(&nptr[i]))
		return (TRUE);
	return (FALSE);
}

void	free_string_tab(char **strs)
{
	int	j;

	j = 0;
	while (strs[j])
	{
		free(strs[j]);
		j++;
	}
	free(strs);
}

int	check_doublon(t_list **list)
{
	t_list	*tmp;
	t_list	*tmp_check;

	tmp = *list;
	if (tmp == NULL)
		return (FALSE);
	while (tmp->next != NULL)
	{
		tmp_check = tmp->next;
		while (tmp_check != NULL)
		{
			if (tmp->content == tmp_check->content)
				return (FALSE);
			tmp_check = tmp_check->next;
		}		
		tmp = tmp->next;
	}
	return (TRUE);
}

int	create_list(t_list **list, char **argv)
{
	int		i;
	int		j;
	char	**strs;

	i = 1;
	while (argv[i])
	{
		j = 0;
		strs = ft_split(argv[i], ' ');
		if (!strs || !*strs)
			return (free_string_tab(strs), FALSE);
		while (strs[j])
		{
			if (!is_correct_nbr(strs[j]))
				return (free_string_tab(strs), FALSE);
			ft_lstadd_back(list, ft_lstnew(ft_atoi(strs[j]), 0));
			j++;
		}
		i++;
		free_string_tab(strs);
	}
	if (!check_doublon(list))
		return (FALSE);
	return (TRUE);
}
