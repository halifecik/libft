#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	tch;

	tch = (unsigned char)c;
	i = ft_strlen(s);
	if (s)
	{
		while (i >= 0)
		{
			if (s[i] == tch)
				return ((char *)&s[i]);
			i--;
		}
	}
	return (0);
}
