/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 21:07:01 by rbicanic          #+#    #+#             */
/*   Updated: 2022/02/03 17:16:14 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_all_lists(t_list **list_a, t_list **list_b, t_list **inst)
{
	if (*list_a != NULL)
		ft_lstclear(list_a);
	if (*list_b != NULL)
		ft_lstclear(list_b);
	if (*inst != NULL)
		ft_lstclear(inst);
	if (inst != NULL)
		free(inst);
	if (list_a != NULL)
		free(list_a);
	if (list_b != NULL)
		free(list_b);
}

void	algo(t_list **list_a, t_list **list_b, t_list **inst, unsigned int l)
{
	if (l < 2 || is_sorted(list_a))
		return ;
	lst_indexation(list_a);
	if (l == 3)
		three_el_algo_opti(list_a, inst);
	else if (l == 2 && (*list_a)->index > (*list_a)->next->index)
		ft_swap(list_a, "sa\n", inst);
	else if (l > 3 && l < 6)
		five_numbers_algo(list_a, list_b, inst);
	else
		quick_sort(list_a, list_b, l, inst);
	if (ft_lstlen(*inst) > 0)
	{
		replace_instructions(inst);
		print_instructions(inst);
	}
}

void	init_lists(t_list ***list_a, t_list ***list_b, t_list ***inst)
{
	*list_b = NULL;
	*list_a = NULL;
	*inst = NULL;
	*list_a = malloc(sizeof(t_list *));
	if (*list_a == NULL)
		exit(EXIT_FAILURE);
	*list_b = malloc(sizeof(t_list *));
	if (*list_b == NULL)
	{
		free(*list_a);
		exit(EXIT_FAILURE);
	}
	*inst = malloc(sizeof(t_list *));
	if (*inst == NULL)
	{
		free(*list_a);
		free(*list_b);
		exit(EXIT_FAILURE);
	}
	**list_b = NULL;
	**list_a = NULL;
	**inst = NULL;
}

t_clearlst	*lsts(void)
{
	static t_clearlst	clear_lst;

	return (&clear_lst);
}

int	main(int ac, char **av)
{
	t_list				**list_a;
	t_list				**list_b;
	t_list				**inst;

	if (ac < 2)
		return (0);
	init_lists(&list_a, &list_b, &inst);
	lsts()->inst = inst;
	lsts()->list_a = list_a;
	lsts()->list_b = list_b;
	if (!create_list(list_a, av))
	{
		write(2, "Error\n", 6);
		clear_all_lists(list_a, list_b, inst);
		exit(EXIT_FAILURE);
	}
	algo(list_a, list_b, inst, ft_lstlen(*list_a));
	clear_all_lists(list_a, list_b, inst);
}
