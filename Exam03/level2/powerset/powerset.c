#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
void print_subset(int *subset, int len)
{
	int i = 0;
	while (i < len)
	{
		printf("%d", subset[i]);
		if (i + 1 < len)
			printf(" ");
		i++;
	}
	printf("\n");
}
void	backtrack(int *arr, int size, int index, int *subset, int subset_len, int sum, int target)
{
	if (index == size)
	{
		if (sum == target)
			print_subset(subset, subset_len);
		return;
	}
	subset[subset_len] = arr[index];
	backtrack(arr, size, index + 1, subset, subset_len + 1, sum + arr[index], target);
	backtrack(arr, size, index + 1, subset, subset_len, sum, target);
}
int	main(int argc, char **argv)
{
	int target;
	int *arr;
	int *subset;
	int i;
	if (argc <= 2)
		return (1);
	target = atoi(argv[1]);
	arr = malloc(sizeof(int) * (argc - 2));
	subset = malloc(sizeof(int) * (argc - 2));
	if (!arr || !subset)
		return (1);
	i = 0;
	while (i < argc - 2)
	{
		arr[i] = atoi(argv[i + 2]);
		i++;
	}
	backtrack(arr, argc - 2, 0, subset, 0, 0, target);
	free(arr);
	free(subset);
	return (0);
}
