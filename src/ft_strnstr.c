#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ret;

	ret = (char *)haystack;
	if (!*needle)
		return (ret);
	i = 0;
	while (i < len && ret[i])
	{
		j = 0;
		while (ret[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return (ret + i);
			j++;
		}
		i++;
	}
	return (0);
}
