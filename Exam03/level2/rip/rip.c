#include <unistd.h>

int balanced(char *s)
{
	int b = 0;
    int i = 0;
	while (s[i])
	{
		if (s[i] == '(')
            b++;
		if (s[i] == ')')
            b--;
		if (b < 0)
            return 0;
		i++;
	}
	return (b == 0);
}

int need(char *s)
{
	int i = 0;
    int o = 0;
    int r = 0;

	while (s[i])
	{
		if (s[i] == '(')
			o++;
		else if (s[i] == ')')
		{
			if (o)
				o--;
            else
                r++;
		}
		i++;
	}
	return (o + r);
}

void print(char *s)
{
	int i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void dfs(char *s, int i, int r, int need)
{
	if (!s[i])
	{
		if (r == need && balanced(s))
			print(s);
		return;
	}
	if (s[i] == '(' || s[i] == ')')
	{
		char c = s[i];
		s[i] = ' ';
		dfs(s, i + 1, r + 1, need);
		s[i] = c;
	}
	dfs(s, i + 1, r, need);
}

int main(int ac, char **av)
{
    if (ac != 2)
		return (1);
	if (ac == 2)
		dfs(av[1], 0, 0, need(av[1]));
}
