
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

# define MIN_INT -2147483647
# define MAX_INT 2147483647

typedef struct s_stack
{
	int				amount;
	struct s_num	*num;
	int				last_ch;
	char			c;
}		t_stack;

typedef struct s_num
{
	int				value;
	int				rank;
	int				chunk;
	struct s_stack	*stack;
}		t_num;

int			ft_parser(t_stack *stack_a, char **argv, int argc, t_num *num);
int			main(int argc, char **argv);
void		ft_putstr_fd(char *s, int fd);
int			true_num(char *s);
long long	ft_atoi(char *str);
int			no_reply(t_num *num, int argc);
void		get_rank(t_num *num, int *Ar, int argc);
void		zero_values(t_stack *a, t_stack *b);
void		sx(t_stack *x);
void		ss(t_stack *x1, t_stack *x2);
void		px(t_stack *x1, t_stack *x2);
void		rx(t_stack *x);
void		rr(t_stack *x1, t_stack *x2);
void		rrx(t_stack *x);
void		rrx_base(t_stack *x);
void		rrr(t_stack *x1, t_stack *x2);
int			is_sorted(t_stack *s);
void		get_rang(int *Ar, int n);
int			get_mid(t_stack *s, int ch);
int			get_n(t_stack *st, int ch);
void		transfer(t_stack *stack1, t_stack *stack2, int ch);
void		b_three(t_stack *stack1, t_stack *stack2);
void		cat_bthree3(t_stack *stack1, t_stack *stack2);
void		cat_bthree4(t_stack *stack1, t_stack *stack2);
void		cat_bthree5(t_stack *stack1, t_stack *stack2);
int			mark_nums(t_stack *stack1, t_stack *stack2, int ch);
void		go_three(t_stack *stack1);
void		short_case(t_stack *stack1, t_stack *stack2);
void		right_scroll(t_stack *a, int x);
void		go_four(t_stack *stack1, t_stack *stack2);
void		go_game(t_stack *stack_a, t_stack *stack_b);
void		end_ch(t_stack *stack_x, int n);
void		rem_a(t_stack *stack_a);
void		b_two(t_stack *stack1, t_stack *stack2);
int			recura(t_stack *stack_a, t_stack *stack_b);
void		all_sorted(t_stack *stack_a, t_stack *stack_b);

#endif
