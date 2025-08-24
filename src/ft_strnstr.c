#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	x;
	char	*result;

	result = (char *)haystack;
	if (!*needle)
		return (result);
	i = 0;
	while (i < len && result[i])
	{
		x = 0;
		while (result[i + x] == needle[x] && i + x < len)
		{
			if (needle[x + 1] == '\0')
				return (result + i);
			x++;
		}
		i++;
	}
	return (0);
}
