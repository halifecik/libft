#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*trmd;
	char	*tmp;

	tmp = (char *)s1;
	if (!tmp || !set)
		return (NULL);
	while (*tmp && ft_strchr(set, *tmp))
		tmp++;
	i = ft_strlen(tmp);
	while (i != 0 && ft_strchr(set, tmp[i]))
		i--;
	trmd = ft_substr((char *)tmp, 0, (i + 1));
	return (trmd);
}
