/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi@student.42amman.com <malhendi>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 06:15:21 by malhendi@st       #+#    #+#             */
/*   Updated: 2025/11/29 06:15:21 by malhendi@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strpbrk(const char *s1, const char *s2)
{
    const char *p1;
    const char *p2;

    if (!s1 || !s2)
        return NULL;

    p1 = s1;
    while (*p1)
    {
        p2 = s2;
        while (*p2)
        {
            if (*p1 == *p2)
                return (char *)p1;
            p2++;
        }
        p1++;
    }
    
    return NULL;
}