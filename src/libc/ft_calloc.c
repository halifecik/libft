#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*byte;
	size_t			total;
	void			*ptr;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	total = count * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	byte = (unsigned char *)ptr;
	while (total--)
		*byte++ = 0;
	return (ptr);
}
