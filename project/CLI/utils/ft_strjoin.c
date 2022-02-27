#include "../cli.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	counts1;
	size_t	counts2;
	size_t	size;
	char	*str;

	counts1 = 0;
	counts2 = 0;
	if (!s1 || !s2)
		return (0);
	size = strlen(s1) + strlen(s2);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	while (s1[counts1])
	{
		str[counts1] = s1[counts1];
		counts1++;
	}
	while (s2[counts2])
	{
		str[counts1 + counts2] = s2[counts2];
		counts2++;
	}
	str[counts1 + counts2] = 0;
	return (str);
}