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

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void error_exit(char *msg)
{
    fprintf(stderr,"Error %s\n",msg);
    exit(1);
}

int main(int argc, char **argv)
{
    char buffer[1024];
    char *stash = NULL;
    size_t stash_len = 0;
    size_t s_len;
    ssize_t r;

    if(argc!=2 || !argv[1][0])
        return (1);
    s_len = strlen(argv[1]);
    while((r = read(0,buffer,sizeof(buffer)))>0)
    {
        char *tmp = realloc(stash,stash_len + r);
        if(!tmp)
            error_exit("malloc failed");
        stash = tmp;
        memmove(stash + stash_len, buffer, r);
        stash_len +=r;
        while(1)
        {
            char *pos = memmem(stash,stash_len,argv[1],s_len);
            if(!pos)
                break;
            write(1,stash,pos - stash);
            size_t i = 0;
            while(i<s_len)
            {
                write(1,"*",1);
                i++;
            }
            stash_len = stash_len - (pos - stash + s_len);
            memmove(stash,pos + s_len,stash_len);
        }
        char *pos = memmem(stash,stash_len,argv[1],s_len);
        if(pos)
        {
            write(1,stash,stash_len);
            stash_len = 0;
        }
    }
    if(r<0)
        error_exit("read failed");
    if(stash_len > 0)
        write(1,stash,stash_len);
    free(stash);
    return(0);
}