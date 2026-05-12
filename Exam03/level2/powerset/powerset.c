/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:22:14 by malhendi          #+#    #+#             */
/*   Updated: 2026/01/26 19:22:14 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*
//DONE
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void putnbr(int n)
{
    char c ;
    if(n <0)
    {
        write(1,"-",1);
        n = -n;
     }
     if(n>= 10)
     putnbr(n/10);
     c= (n %10)+'0';
     write(1,&c,1);
}
static void print_subset(int *subset ,int size)
{
    int i =0;
    while (i <size)
    {   putnbr(subset[i]);
        if(i+1<size)
        write(1," ",1);
        i++;
    }
write(1,"\n",1);
}
static void backtrack(int *arr ,int *subset ,int n ,int target ,int sum ,int idx ,int subset_size)
{
    int i;
    if(sum == target)
    {
        print_subset(subset,subset_size);
        return;
    }
    if(sum >target)
    return;
    i =idx;
    while (i <n )
    {
        subset[subset_size]= arr[i];
        backtrack(arr,subset,n ,target ,sum+arr[i] ,i+1,subset_size+1);
        i++;
    }
}
int main(int ac ,char **av)
{
    int target ,n ,i;
    int *arr ,*subset;

    if(ac < 3)
    return 1;
    target = atoi(av[1]);
    n = ac -2;

    arr =malloc(n *sizeof(int));
    subset= malloc(n *sizeof(int));
    if(!arr || !subset)
    return 1;

    i =0;
    while (i <n)
    {
       arr[i] = atoi(av[i+2]);
       i++;
    }
    backtrack(arr ,subset, n, target ,0 , 0 ,0);
    free(arr);
    free(subset);
    return 0;
}
*/