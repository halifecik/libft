#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			cnt++;
		while (*s && *s != c)
			s++;
	}
	return (cnt);
}

static void	ft_free_ary(char **ary, int i)
{
	while (i--)
		free(ary[i]);
	free(ary);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		len;
	char	**ret;

	len = ft_word_count(s, c);
	ret = malloc(sizeof(char *) * (len + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		while (*s == c)
			s++;
		j = 0;
		while (s[j] != c && s[j])
			j++;
		ret[i] = ft_substr(s, 0, j);
		if (!ret[i])
			return (ft_free_ary(ret, i), NULL);
		s += j;
	}
	ret[i] = NULL;
	return (ret);
}
