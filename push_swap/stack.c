/*
1. stack init

2. add to head

3. add to tail

4. del node

*/

#include "./push_swap.h"
#include "./libft/libft.h"

t_stack	*stackalloc()
{
}

void	stack_init(int *cnt)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->cnt = cnt;

}

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	return (node);
}