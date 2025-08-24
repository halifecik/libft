#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (!dest && !size)
		return (0);
	i = ft_strlen(dest);
	if (i >= size)
		return (ft_strlen(src) + size);
	ft_strlcpy((dest + i), src, size - i);
	return (i + ft_strlen(src));
}
