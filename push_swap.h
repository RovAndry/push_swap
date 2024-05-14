/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:55:26 by randrina          #+#    #+#             */
/*   Updated: 2024/05/04 01:42:32 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
#include <stdio.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*top;
}	t_stack;

int			index_moov(t_stack *a, t_stack *b, int index);
int			first_moov(t_stack *a);
int			ft_mindex(t_stack *stack);
int			ft_maxindex(t_stack *stack);
int			index_to_mov(t_stack *a, t_stack *b);
int			abs_value(int nbr);
int			ft_check_input_sort(char **argv, int argc);
int			ft_number_check(char *str);
int			ft_stacklen(t_stack *stack);
int			ft_check_stack(t_stack *stack);
int			ft_count_words(char const *s, char c);
int			ft_strlen(char *str);
int			ft_isnumber(char *str);
int			ft_min_index(t_stack *a);
int			ft_max_value(t_stack *stack);
int			ft_min_value(t_stack *stack);
int			ft_last_max(t_stack *stack, int last);
int			index_min(t_stack *a, t_stack *b);
int			mov_nbr(int mov_a, int mov_b);
int			find_cible(t_stack *stack, int index);
int			to_top(t_stack *stack, int index);
int			ft_check_final(t_stack *stack);
int			mov_with_pos(t_stack *a, t_stack *b, int aindex, int bindex);
int			mov_with_neg(t_stack *a, t_stack *b, int aindex, int bindex);
long int	ft_atoi(char *str);
char		**ft_check_input(char **argv, int argc);
char		**init_table(void);
char		**ft_split(char const *str);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_putstr(char *str, int fd);
void		ft_putnbr(long int nbr);
void		ft_show_stack(t_stack *a, t_stack *b);
void		*ft_add_first(t_stack *stack, int value);
void		*ft_add_last(t_stack *stack, int value);
void		ft_swap(t_stack *stack);
void		swap_a(t_stack *a);
void		swap_b(t_stack *b);
void		swap_all(t_stack *a, t_stack *b);
void		ft_push(t_stack *stack1, t_stack *stack2);
void		push_a(t_stack *a, t_stack *b);
void		push_b(t_stack *a, t_stack *b);
void		ft_rotate(t_stack *stack);
void		rotate_a(t_stack *a);
void		rotate_b(t_stack *b);
void		rotate_all(t_stack *a, t_stack *b);
void		ft_reverse(t_stack *stack);
void		reverse_a(t_stack *a);
void		reverse_b(t_stack *b);
void		reverse_all(t_stack *a, t_stack *b);
void		ft_three_sort(t_stack *a);
void		three_sort_sup(t_stack *a);
void		ft_sort_stack(t_stack *a, t_stack *b);
void		ft_sort_stack1(t_stack *a, t_stack *b);
void		ft_insert_index(t_stack *stack);
void		ft_push_b(t_stack *a, t_stack *b);
void		moov_a(t_stack *a, int mov);
void		moov_b(t_stack *b, int mov);
void		first_push(t_stack *a, t_stack *b);
t_stack		*generate_stack_a(char **argv, int argc);
t_stack		*ft_init(void);

#endif
