/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 03:10:06 by malhendi@st       #+#    #+#             */
/*   Updated: 2025/12/11 06:51:24 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi(const char *str)
{
	int i = 0;
	int s = 1;
	int t = 0;

	while(str[i] > 8 && str[i] < 14 || str[i] == ' ')
		i++;
	if(str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
			s *= -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		t = t * 10 + (str[i] - 48);
		i++;
	}
	return(t * s);
}

/*
int main()
{
	char str[] = "   -12345abc";
	int num = ft_atoi(str);
	printf("%d\n", num);
	return 0;
}
*/