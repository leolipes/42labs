#include <cli.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (start > strlen(s))
	{
		sub = malloc(sizeof(char));
		if (!sub)
			return (NULL);
		sub[0] = 0;
		return (sub);
	}
	if (len > strlen(&s[start]))
		len = strlen(&s[start]);
	sub = malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	sub[len] = 0;
	while (len--)
		sub[len] = s[len + start];
	return (sub);
}
