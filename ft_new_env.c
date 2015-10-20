/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 10:35:08 by jbahus            #+#    #+#             */
/*   Updated: 2015/10/13 16:16:36 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	**ft_create(char **env, char *str)
{
	env = (char**)malloc(sizeof(char*) * ENV_SIZE);
	env[0] = ft_strdup(str);
	env[1] = NULL;
	return (env);
}

char	**ft_new_env(char **env, char *new_e)
{
	int		i;
	char	**split1;
	char	**split2;

	if (!env)
	{
		env = ft_create(env, new_e);
		return (env);
	}
	if (!new_e)
	{
		ft_putendl("No parameter.");
		return (env);
	}
	i = 0;
	split1 = ft_strsplit(new_e, '=');
	while (env[i])
	{
		split2 = ft_strsplit(env[i], '=');
		if (ft_strequ(split1[0], split2[0]))
		{
			ft_strdel(&env[i]);
			env[i] = ft_strdup(new_e);
			ft_del_tab_char(split1);
			ft_del_tab_char(split2);
			return (env);  
		}
		ft_del_tab_char(split2);
		i++;
	}
	ft_strdel(&env[i]);
	env[i] = ft_strdup(new_e);
	ft_del_tab_char(split1);
	return (env);
}
