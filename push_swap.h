/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 21:07:16 by rbicanic          #+#    #+#             */
/*   Updated: 2022/02/07 14:07:58 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define TRUE 1
# define FALSE 0

typedef struct s_list
{
	int				content;
	unsigned int	index;
	char			cmd[5];
	struct s_list	*next;
	struct s_list	*before;
}	t_list;

typedef struct s_clearlst
{
	t_list	**list_a;
	t_list	**list_b;
	t_list	**inst;
	int		bad_arg;
}				t_clearlst;

int				ft_strlen(char *str);
t_list			*ft_lstnew(int content, int index);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstlen(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstclear(t_list **lst);
void			ft_swap(t_list **list, char *cmd_name, t_list **inst);
void			ft_push(t_list **list_dest, t_list **list_src,
					char *cmd, t_list **inst);
void			ft_rotate(t_list **list, char *cmd, t_list **inst);
void			ft_reverse_rotate(t_list **list, char *cmd, t_list **inst);
int				create_list(t_list **list_a, char **argv);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				is_sorted(t_list **list_a);
void			lst_indexation(t_list **list_a);
void			three_el_algo(t_list **list_a, t_list **list_b, t_list **com);
void			three_el_algo_opti(t_list **list_a, t_list **com);
void			five_numbers_algo(t_list **list_a,
					t_list **list_b, t_list **com);
unsigned int	median(t_list **list, int len, int divider);
int				under_pivot_sorted(t_list **list, unsigned int pivot, int len);
int				over_pivot_sorted(t_list **list, unsigned int pivot, int len);
int				sort_right(t_list **src, t_list **dest,
					unsigned int pivot, t_list **com);
t_list			*ft_lstnew_inst(char *inst);
void			quick_sort(t_list **a, t_list **b,
					unsigned int lst_len, t_list **com);
int				sort_left(t_list **src, t_list **dest,
					unsigned int pivot, t_list **com);
void			replace_instructions(t_list **inst);
void			print_instructions(t_list **inst);
char			**ft_split(char const *s, char c);
int				ft_atoi(const char *nptr);
t_clearlst		*lsts(void);
void			clear_all_lists(t_list **list_a,
					t_list **list_b, t_list **inst);
int				ft_is_numeric(char *s);

#endif
