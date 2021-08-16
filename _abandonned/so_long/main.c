
#include "./includes/solong.h"
void	ft_putstr(const char *s)
{
	if (s)
	{
		while (*s)
		{
			write(1, s, 1);
			s++;
		}
	}
}


int	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int main (int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("Error\n.ber map required as only argument");
		exit(1);
	}
	// check .ber
	int len;
	len = ft_strlen(av[1]);
	if (len < 5)
	{
		ft_putstr("Error\nInvalid map description file");
		exit(1);
	}
	if (ft_strcmp(&av[1][len - 4], ".ber") != 0)
	{
		ft_putstr("Error\nMust have .ber extension");
		exit(1);

	}





}

