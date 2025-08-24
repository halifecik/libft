#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*ret;

	if (!dst && !src)
		return (0);
	ret = dst;
	if (dst > src)
		while (len--)
			*((char *)dst + len - 1) = *((char *)src + len - 1);
	else
		while (len--)
			*((char *)dst++) = *((char *)src++);
	return (ret);
}
