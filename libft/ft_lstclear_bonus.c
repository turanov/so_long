#include "libft.h"

static void	ft_del(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	ft_del(lst->next, del);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!(*lst))
		return ;
	ft_del(*lst, del);
	*lst = 0;
}
