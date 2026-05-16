/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:22:14 by malhendi          #+#    #+#             */
/*   Updated: 2026/01/26 19:22:14 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//DONE
#include<unistd.h>
#include<stdio.h>
 void swap(char*a,char *b)
 {
    char t = *a;
    *a = *b;
    *b = t;
 }
 void sort(char *str)
 {
    int i =0;
    int j;
    while (str[i])
    {
        j= i+1;
        while (str[j])
        {
            if(str[i]> str[j])
            swap(&str[i], &str[j]);
            j++;
        }
        
      i++;  
    }
    
 }
  void perm(char *str ,int start)
  {
    int i = start;
    if(!str[start +1])
    {
        puts(str);
    }
    while (str[i])
    {
        swap(&str[i], &str[start]);
        sort(str+start+1);
        perm(str,start+1);
        sort(str+start);
      i++; 
    }
    
  }
   int main(int ac ,char *av[])
   {
    if(ac != 2 || !av[1])
      return (1); 

    sort(av[1]);
    perm(av[1],0);
   }