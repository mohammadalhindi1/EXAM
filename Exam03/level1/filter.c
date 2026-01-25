/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:50:37 by malhendi          #+#    #+#             */
/*   Updated: 2026/01/10 19:50:37 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void error_exit(char *msg)
{
    fprintf(stderr,"Error %s\n", msg);
    exit(1);
}

char *ft_memmem(char *stash, size_t stash_len, char *s, size_t s_len)
{
    size_t i = 0;
    size_t j ;

    if (!stash || !s)
        return NULL;
    if (s_len == 0)
        return stash;
    if (stash_len < s_len)
        return NULL;

    while (i + s_len <= stash_len)
    {
        j = 0;
        while(j < s_len && stash[j + i] == s[j])
            j++;
        if (j == s_len)
            return (stash + i);
        i++;
    }
    return (NULL);
}

int main(int ac, char **av)
{
    if (ac != 2 || !av[1][0])
        return (1);

    char *stash = NULL;
    char buffer[4096];
    size_t stash_len = 0;
    size_t s_len = strlen(av[1]);
    ssize_t r;

    while ((r = read(0, buffer, sizeof(buffer))) > 0)
    {
        char *tmp = realloc(stash, stash_len + r);
        if (!tmp)
            error_exit("malloc failed");
        stash = tmp;        
        memmove(stash + stash_len, buffer, r);
        stash_len = stash_len + r;
        while (1)
        {
            char *pos = ft_memmem(stash, stash_len, av[1], s_len);
            if (!pos)
                break;
            write(1, stash, pos - stash);
            size_t i = 0;
            while (i < s_len)
            {
                write(1, "*", 1);
                i++;
            }
            stash_len = stash_len - (pos - stash + s_len);
            memmove(stash, pos + s_len ,stash_len);
        }
        char *pos = ft_memmem(stash, stash_len, av[1] , s_len);
        if (!pos)
        {
            write(1, stash, stash_len);
            stash_len = 0;
        }
    }
    if (r < 0)
    error_exit("read failed");
    if (stash_len > 0)
        write(1,stash,stash_len);
    free(stash);
}