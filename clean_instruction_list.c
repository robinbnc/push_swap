/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_instruction_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 01:31:09 by rbicanic          #+#    #+#             */
/*   Updated: 2022/02/04 18:23:04 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	copy_instructions(t_list *tmp, char *inst)
{
	ft_strcpy(tmp->cmd, inst);
	ft_strcpy(tmp->next->cmd, "");
}

void	replace_instructions(t_list **inst)
{
	t_list	*tmp;

	tmp = *inst;
	while (tmp->next != NULL)
	{
		if (!ft_strncmp(tmp->cmd, "pa\n", 3)
			&& !ft_strncmp(tmp->next->cmd, "pb\n", 3))
			copy_instructions(tmp, "");
		else if (!ft_strncmp(tmp->cmd, "rb\n", 3)
			&& !ft_strncmp(tmp->next->cmd, "ra\n", 3))
			copy_instructions(tmp, "rr\n");
		else if (!ft_strncmp(tmp->cmd, "sa\n", 3)
			&& !ft_strncmp(tmp->next->cmd, "sb\n", 3))
			copy_instructions(tmp, "ss\n");
		else if (!ft_strncmp(tmp->cmd, "ra\n", 3)
			&& !ft_strncmp(tmp->next->cmd, "rb\n", 3))
			copy_instructions(tmp, "rr\n");
		else if (!ft_strncmp(tmp->cmd, "rrb\n", 4)
			&& !ft_strncmp(tmp->next->cmd, "rra\n", 4))
			copy_instructions(tmp, "rrr\n");
		else if (!ft_strncmp(tmp->cmd, "rra\n", 4)
			&& !ft_strncmp(tmp->next->cmd, "rrb\n", 4))
			copy_instructions(tmp, "rrr\n");
		tmp = tmp->next;
	}
}

void	print_instructions(t_list **inst)
{
	t_list	*tmp;

	tmp = *inst;
	while (tmp != NULL)
	{
		ft_putstr(tmp->cmd);
		tmp = tmp->next;
	}
}
