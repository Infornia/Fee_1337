#include "libft.h"
#include "fee_1337.h"

void	wfile(char *t, int nb)
{
	int		j;
	int		fd;
	char	*name;
	
	fd = 1;
	name = ft_strjoin("Tests/Fails/fail_", ft_itoa(nb));
//	fd = open(name, O_WRONLY | O_CREAT | O_APPEND);
	
	write(1, t, 20);
	write(1, "\n\n\n", 3);
    //close(fd);
	
}

void	unsharp_it(char *t, int i)
{
	if (i % 5 != 4)
		t[i] = '.';
}

void	sharp_it(char *t, int *i)
{
	if (*i % 5 != 4)
		t[*i] = '#';
	else
		(*i)++;
	(*i)++;
}

void	sharped(char *t)
{
	int		i;
	int		j;
	int		k;
	int		l;
	int		nb;

	nb = 0;
	i = 0;
	j = 1;
	k = 2;
	l = 3;
	while (i < 17)
	{
		unsharp_it(t, i);
		sharp_it(t, &i);
		j = 1;
		while (j < 18)
		{
			unsharp_it(t, j);
			sharp_it(t, &j);
			k = 2;
			while (k < 19)
			{
				unsharp_it(t, k);
				sharp_it(t, &k);
				l = 3;
				while (l < 20)
				{
					unsharp_it(t, l);
					sharp_it(t, &l);
					wfile(t, nb++);
				}
			}
		}
	}
}

int		main(void)
{
	int		j;
	int		nb;
	char	*name;
	char	*t;

	nb = 0;
	t = malloc(21);
	for (j = 0; j < 20; j++)
	{
		if (j % 5 != 4)
			t[j] = '.';
		else
			t[j] = '\n';
	}
	t[20] = '\0';
	sharped(t);
	return (0);
}