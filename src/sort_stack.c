#include "../push_swap.h"

void		sort_stack(t_stack **stack1, t_stack **stack2, t_com **result,
	int len)
{
	int		rot;

	if (len == 2 || len == 3)
		return ;
	if ((*stack1)->diff == 1)
		rot = div_stack_a(stack1, stack2, result, len);
	else
		rot = div_stack_b(stack1, stack2, result, len);
	if ((*result)->rotator == 1)
		rotate_back(stack1, result, rot);
	if ((*stack1)->diff == 1 && (len / 2 == 3 || len / 2 == 2))
		swap_elements(stack1, stack2, result, len);
	else if ((*stack1)->diff == 2 && (len / 2 == 3 || len / 2 == 2))
		swap_elements(stack1, stack2, result, len);
	sort_stack(stack1, stack2, result, (*stack1)->diff != 1 ?
		len / 2 : len - len / 2);
	sort_stack(stack2, stack1, result, (*stack1)->diff == 1 ?
		len / 2 : len - len / 2);
	if ((*stack1)->diff == 1)
		push_back(stack1, stack2, result, len / 2);
	else
		push_back(stack1, stack2, result, len - len / 2);
}