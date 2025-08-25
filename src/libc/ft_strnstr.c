#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ret;

	ret = (char *)haystack;
	if (!*needle)
		return (ret);
	i = -1;
	while (++i < len && ret[i])
	{
		j = -1;
		while (i + ++j < len && ret[i + j] == needle[j])
			if (needle[j + 1] == '\0')
				return (ret + i);
	}
	return (NULL);
}
