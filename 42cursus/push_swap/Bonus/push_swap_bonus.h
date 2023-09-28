/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:12:08 by yerilee           #+#    #+#             */
/*   Updated: 2023/09/28 16:00:42 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

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

char			*get_next_line(int fd);
char			*get_one_line(int fd, char *buf, char **backup);
char			*read_line(char *buf, char **backup);
char			*extract_line(char	*backup);
char			*meet_eof(char *buf, char **backup);

size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char *s1, char *s2, int len1, int len2);
char			*ft_strchr(const char *s, int c);
void			ft_gnl_free(char **p);

void			get_operation_line(t_stack *a, t_stack *b);
int				do_operation(t_stack *a, t_stack *b, char *op);
int				ft_strcmp(char *s1, char *s2);

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
char			**ft_split_free(char **p);

void			push_top(t_stack *stack, int val);
void			push_bottom(t_stack *stack, int val, int flag);
int				pop_top(t_stack *stack);
int				pop_bottom(t_stack *stack);

t_stack			*stack_init(void);
int				setting_stack(int argc, char **argv, t_stack *stack);
void			push_node_in_stack(t_stack *stack, char *argv);
void			setting_node_rank(t_stack *stack);
void			ranking(t_stack *stack, t_node *target);

void			free_stack(t_stack *stack);
void			free_list(char **p);

void			print_success(void);
void			print_error(int num);

#endif