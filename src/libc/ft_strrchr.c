#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	ch;

	ch = (unsigned char)c;
	i = 0;
	while (s[i])
		i++;
	if (s)
		while (i--)
			if (s[i] == ch)
				return ((char *)&s[i]);
	return (0);
}
