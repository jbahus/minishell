/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:15:00 by jbahus            #+#    #+#             */
/*   Updated: 2015/09/17 20:06:01 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int ret;
	int sign;

	ret = 0;
	sign = 1;
	while (ft_isspace(*str))
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-' ? -1 : 1);
		str++;
	}
	while (ft_isdigit(*str))
	{
		ret = (ret * 10) + (*str - '0');
		str++;
	}
	return (ret * sign);
}
