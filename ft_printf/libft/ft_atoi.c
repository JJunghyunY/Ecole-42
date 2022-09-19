/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 09:06:22 by junyoo            #+#    #+#             */
/*   Updated: 2022/07/18 16:28:46 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	unsigned int	num;
	int				sig;
	int				i;

	num = 0;
	sig = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sig *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num > 2147483647)
		{
			if (sig == -1)
				return (0);
			return (-1);
		}
		num *= 10;
		num += (str[i] - '0');
		i++;
	}
	return ((int)num * sig);
}
