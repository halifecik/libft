#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*rtn;

	if (!s || !f)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	rtn = (char *)malloc(sizeof(char) * (i + 1));
	if (!rtn)
		return (NULL);
	i = -1;
	while (s[++i])
		rtn[i] = f(i, s[i]);
	rtn[i] = '\0';
	return (rtn);
}
