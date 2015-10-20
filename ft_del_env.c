/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 11:36:26 by jbahus            #+#    #+#             */
/*   Updated: 2015/10/13 16:16:35 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	**ft_del_env(char **env, char *str)
{
	int		i;
	char	**split1;
	char	**split2;

	if (!str)
	{
		ft_putendl("No parameter.");
		return (env);
	}
	i = 0;
	split1 = ft_strsplit(str, '=');
	split2 = ft_strsplit(env[i], '=');
	while (ft_strequ(split1[0], split2[0]) == 0)
	{
		i++;
		if (!env[i])
		{
			ft_putendl("Env not found.");
			return (env);
		}
		ft_del_tab_char(split2);
		split2 = ft_strsplit(env[i], '=');
	}
	ft_del_tab_char(split1);
	while(env[i] && env[i + 1])
	{
		env[i] = env[i + 1];
		i++;
	}
	env[i] = NULL;
	return (env);
}