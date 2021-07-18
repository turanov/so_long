#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ans;
	t_list	*new;

	ans = 0;
	while (lst != 0)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
			ft_lstclear(&ans, del);
		ft_lstadd_back(&ans, new);
		lst = lst->next;
	}
	return (ans);
}
