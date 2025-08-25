#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*tmp;
	char	*ret;

	tmp = (char *)s1;
	if (!tmp || !set)
		return (NULL);
	while (*tmp && ft_strchr(set, *tmp))
		tmp++;
	i = 0;
	while (tmp[i])
		i++;
	while (i && ft_strchr(set, tmp[i]))
		i--;
	ret = ft_substr((char *)tmp, 0, (i + 1));
	return (ret);
}
