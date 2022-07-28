#include <stdio.h>

void	get_remaining_stash(char *stash)
{
	int	i;
	char	*tmp;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if ((stash[i] == '\n' && stash[i + 1] == '\0') || stash[i] == '\0')
	{
		clean_tmp(stash);
		return ;
	}
	tmp = &stash[i + 1];
	i = 0;
	while (tmp[i] != '\0')
	{
		stash[i] = tmp[i];
		i++;
	}
	stash[i] = '\0';
	return ;
}

int main ()
{
	char stash[] = "Salut\ntoi";

	get_remaining_stash(stash);
	printf("%s\n", stash);

	return 0;
}
