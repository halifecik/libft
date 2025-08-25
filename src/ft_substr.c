#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	size = 0;
	while (s[size])
		size++;
	if (size < start)
		return (ft_strdup(""));
	if (len > size - start)
		len = size - start;
	substr = ft_calloc(len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	substr[len] = '\0';
	while (i < len)
		substr[i++] = s[start++];
	return (substr);
}
