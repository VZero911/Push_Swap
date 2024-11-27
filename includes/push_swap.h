/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/20 03:26:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_median
{
	int	len;
	int	octile1;
	int	quartile1;
	int	octile3;
	int	med;
	int	octile5;
	int	quartile3;
	int	octile7;
	int	octile1_val;
	int	quartile1_val;
	int	octile3_val;
	int	median_val;
	int	octile5_val;
	int	quartile3_val;
	int	octile7_val;
}	t_median;

typedef struct s_stack
{
	int					value;
	int					index;
	struct s_stack		*target;
	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

// Commands

void			pa(t_stack **stack_a, t_stack **stack_b,
					t_median **mq, int print);
void			pb(t_stack **stack_a, t_stack **stack_b,
					t_median **mq, int print);

void			rra(t_stack **a, int print);
void			rrb(t_stack **a, int print);
void			rrr(t_stack **b, t_stack **a, int print);

void			ra(t_stack **a, int print);
void			rb(t_stack **a, int print);
void			rr(t_stack **b, t_stack **a, int print);

void			sa(t_stack **a, int print);
void			sb(t_stack **b, int print);
void			ss(t_stack **a, t_stack **b, int print);

// stacks utils

void			free_all(t_stack **stack_a, t_stack **stack_b, t_median **mq);
int				add_to_list(t_stack **stack, int nbr);
void			free_stack(t_stack **stack);
int				stack_len(t_stack *stack);
int				new_node(int nbr, t_stack **node);
void			replace_stack(t_stack **stack);
int				inner(t_stack *stack, int q1, int q2);
int				stack_sorted(t_stack *stack);

// get utils

int				get_index(t_stack *stack, int node);
int				get_min(t_stack *stack);
int				get_max(t_stack *stack);
int				get_pos_to_place(t_stack *stack, int node);
int				get_best_move(t_stack *stack_a, t_stack *stack_b);

// Median and quartill + Error gestion

void			sort_int_tab(int array[], int low, int high);
char			**my_split(int argc, char **argv);
int				ft_atol_and_check(const char *nptr, int *error);
long long		ft_atol(const char *nptr);

//Parsing

int				count_split(char **split);
void			free_split_array(char **split);
int				check_array_errors(int *array, char **split, t_median *mq);
int				*create_array(char **split, int split_len);
int				fill_array(int *array, char **split, int *len, int *error);
t_median		*create_mq(int *array, int len);
int				handle_split(char **split);
int				handle_array(int *array, char **split, int error, int len);
void			fill_mq(t_median *mq, int *array, int len);

// MAIN

int				initialize_stacks(t_stack **stack_a,
					t_stack **stack_b, char **spl);
void			start_algo(t_stack *stack_a, t_stack *stack_b, t_median *mq);
void			sort_to_b(t_stack *pile_a, t_stack *pile_b, t_median *mq);
void			sort_three(t_stack **stack_a);

#endif
