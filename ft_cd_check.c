/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 14:25:38 by jbahus            #+#    #+#             */
/*   Updated: 2015/10/20 15:40:49 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		ft_check_cd(char **split)
{
	if (!opendir(split[1]))
	{
		if (split[2])
		{
			ft_putstr("cd: string not in pwd: ");
			ft_putendl(split[1]);
			return (0);
		}
		else if (access(split[1], F_OK) == -1)
		{
			ft_putstr("cd: no such file or directory: ");
			ft_putendl(split[1]);
			return (0);
		}
		else if (access(split[1], R_OK) == -1)
		{
			ft_putstr("cd : permission denied: ");
			ft_putendl(split[1]);
			return (0);
		}
	}
	return (1);
}
