#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ans;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	ans = *lst;
	while (ans->next != 0)
		ans = ans->next;
	ans->next = new;
}
