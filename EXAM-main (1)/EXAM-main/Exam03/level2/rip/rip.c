/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:22:14 by malhendi          #+#    #+#             */
/*   Updated: 2026/01/26 19:22:14 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int balanced(char *s)
{
    int i = 0;
    int b = 0;

    while (s[i])
    {
        if (s[i] == '(')
            b++;
        else if (s[i] == ')')
        {
            b--;
            if (b < 0)
                return (0);
        }
        i++;
    }
    return (b == 0);
}

void print(char *s)
{
    int i = 0;

    while (s[i])
        write(1, &s[i++], 1);
    write(1, "\n", 1);
}

int count_need(char *s)
{
    int i = 0;
    int open = 0;
    int need = 0;

    while (s[i])
    {
        if (s[i] == '(')
            open++;
        else if (s[i] == ')')
        {
            if (open > 0)
                open--;
            else
                need++;
        }
        i++;
    }
    return (need + open);
}

void dfs(char *s, int i, int r, int need)
{
    char c;

    if (!s[i])
    {
        if (r == need && balanced(s))
            print(s);
        return;
    }
    c = s[i];
    s[i] = ' ';
    dfs(s, i + 1, r + 1, need);
    s[i] = c;
    dfs(s, i + 1, r, need);
}

int main(int argc, char **argv)
{
    int need;

    if (argc != 2)
        return (1);
    need = count_need(argv[1]);
    dfs(argv[1], 0, 0, need);
    return (0);
}

/*
#include <stdio.h>
#include <unistd.h>
#include <time.h>      // add this for clock()

int ft_strlen(char *s)
{
    int len = 0;
    if (!s)
        return len;
    while (*s++)
        len++;
    return (len);
}

int compute_diff_and_validate(char *str)
{
    int open = 0;
    int close = 0;

    for (int i = 0; str[i] ; i++)
    {
        if (str[i] == '(')
            open++;
        else if (str[i] == ')')
        {
            if (open > 0)
                open--;
            else
                close++;
        }
    }
    return open + close;
}

void solve_rip(char *str, int removals, char *sol, int len, int index)
{
    if (index == len - 1) {
        sol[index] = '\0';
        if (!compute_diff_and_validate(sol)) {
            puts(sol);
        }
        return;
    }
    if (str[index] != '(' && str[index] != ')')
    {
        sol[index] = str[index];
        solve_rip(str, removals, sol, len, index + 1); 
    }
    else
    {
        if (removals > 0)
        {
            // option 1, to remove
            sol[index] = ' ';
            solve_rip(str, removals - 1, sol, len, index + 1);
        }
        // option 2, to keep it
        sol[index] = str[index];
        solve_rip(str, removals, sol, len, index + 1);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;

    // clock_t start = clock();

    int offset = compute_diff_and_validate(argv[1]);
    if (!offset)
    {
        puts(argv[1]);
        // clock_t end = clock();
        // double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
        // printf("Time: %.6f seconds\n", time_spent);
        return 0;
    }
    int len = ft_strlen(argv[1]) + 1;
    char sol[len];
    solve_rip(argv[1], offset, sol, len, 0);
    // clock_t end = clock();
    // double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    // printf("Time: %.6f seconds\n", time_spent);
    return 0;
}
*/