#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*new;

	len = ft_strlen(s1) + 1;
	new = malloc(len * sizeof(char));
	if (!new)
		return (NULL);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	new[i] = '\0';
	return (new);
}
