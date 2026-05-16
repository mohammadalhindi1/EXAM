/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi@student.42amman.com <malhendi>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 06:06:22 by malhendi@st       #+#    #+#             */
/*   Updated: 2025/11/29 06:06:23 by malhendi@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_strdup(char *src)
{
	int i = 0;
	int len = 0;
	char *dis;

	while(src[len])
		len++;
	dis = malloc(sizeof(char) *(len + 1));
	while(src[i])
	{
		dis[i] = src[i];
		i++;
	}
	dis[i] = '\0';
	return(dis);
}
