/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_stuff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 16:31:14 by jbahus            #+#    #+#             */
/*   Updated: 2015/10/20 18:49:44 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	aff_env(char **env)
{
	int		i;

	i = 0;
	while (env[i])
		ft_putendl(env[i++]);
}

void	do_stuff(char *line, char ***e)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_strsplit(line, ' ');
	if (ft_strequ(split[0], "exit"))
	{
		ft_del_tab_char(split);
		ft_strdel(&line);
		exit(0);
	}
	else if (ft_strcmp(split[0], "cd") == 0)
		*e = ft_cd(split, *e);
	else if (ft_strcmp(split[0], "env") == 0)
	{
		if (*e)
			aff_env(*e);
	}
	else if (ft_strcmp(split[0], "setenv") == 0)
		*e = ft_new_env(*e, split[1]);
	else if (ft_strcmp(split[0], "unsetenv") == 0)
		*e = ft_del_env(*e, split[1]);
	else if (split[0])
		ft_check_path(split, *e);
	else
	{
		ft_putstr("zsh: command not found: ");
		ft_putendl(split[0]);
	}
	ft_del_tab_char(split);
}
