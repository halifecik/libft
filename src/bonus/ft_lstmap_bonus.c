#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*tmp;
	t_list	*new;
	t_list	*node;

	new = NULL;
	while (lst)
	{
		tmp = f(lst->content);
		if (!tmp)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		node = ft_lstnew(tmp);
		if (!node)
		{
			del(tmp);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}
