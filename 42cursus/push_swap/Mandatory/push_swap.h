/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:57:33 by yerilee           #+#    #+#             */
/*   Updated: 2023/09/27 20:47:14 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				val;
	int				rank;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		pivot1;
	int		pivot2;
	int		size;
	t_node	*first;
	t_node	*last;
}	t_stack;

void			check_argv(int argc, char **argv);
int				check_duplicate(t_stack	*stack, int val);
int				is_only_space(const char *s, char c);
int				is_sorted(t_stack *stack);
int				is_empty(t_stack *stack);

void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *a, t_stack *b);
void			ra(t_stack *a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);
void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);

int				ft_atoi(const char *str);

char			**ft_split(char const *s, char c);
unsigned int	word_count(char const *s, char c);
char			*word_alloc(char const *s, char c);
char			**ft_free(char **p);

void			push_top(t_stack *stack, int val);
void			push_bottom(t_stack *stack, int val, int flag);
int				pop_top(t_stack *stack);
int				pop_bottom(t_stack *stack);

t_stack			*stack_init(void);
int				setting_stack(int argc, char **argv, t_stack *stack);
void			push_node_in_stack(t_stack *stack, char *argv);
void			setting_node_rank(t_stack *stack);
void			ranking(t_stack *stack, t_node *target);

int				sorting(t_stack *a, t_stack *b);
void			sorting_a_stack(t_stack *a, t_stack *b);
void			sort_3(t_stack *stack);
void			sort_4(t_stack *a, t_stack *b);
void			sort_5(t_stack *a, t_stack *b);

void			select_pivot(t_stack *stack);
void			classifying_by_pivot(t_stack *a, t_stack *b);

int				find_min_index(t_stack *stack);
void			move_min_element(t_stack *a, t_stack *b);
void			set_min_top(t_stack *a);

void			greedy(t_stack *a, t_stack *b);
void			find_minimum_times(t_stack *a, t_stack *b, int *m_a, int *m_b);
int				rb_times(t_stack *b, int index);
int				ra_times(t_stack *a, int data_b);
void			find_index_to_push(t_stack *a, int data_b, int *index);

void			run_rb(t_stack *b, int rb_cnt);
void			run_ra(t_stack *a, int ra_cnt);

void			free_stack(t_stack *stack);
void			free_list(char **p);

int				ft_abs(int value);
void			print_error(void);

#endif