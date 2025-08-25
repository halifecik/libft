#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	if (!dest && !size)
		return (0);
	while (dest[i])
		i++;
	while (src[len])
		len++;
	if (i >= size)
		return (len + size);
	ft_strlcpy((dest + i), src, size - i);
	return (len + i);
}
