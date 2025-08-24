#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (len--)
		((unsigned char *)s)[i++] = (unsigned char)c;
	return (s);
}
