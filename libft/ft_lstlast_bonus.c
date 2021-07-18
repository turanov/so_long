#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	if (!lst->next)
		return (lst);
	return (ft_lstlast(lst->next));
}
