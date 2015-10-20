/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ex_bin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 17:13:09 by jbahus            #+#    #+#             */
/*   Updated: 2015/10/20 19:25:19 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_ex_bin(char *ex, char **split, char **e)
{
	pid_t	father;

	father = fork();
	if (father > 0)
	{
		if (wait(&father))
			return ;
	}
	if (father == 0)
		execve(ex, split, e);
}

void	ft_check_path(char **split, char **e)
{
	char	*tmp;
	char	**path;
	int		i;

	i = 0;
	if (access(split[0], F_OK | X_OK) == 0)
		ft_ex_bin(split[0], split, e);
	else
	{
		tmp = get_in_env("PATH", e);
		path = ft_strsplit(tmp, ':');
		while (path[i])
		{
			tmp = ft_strnew(ft_strlen(path[i] + ft_strlen(split[0]) + 2));
			tmp = ft_strcat(tmp, path[i]);
			tmp = ft_strcat(tmp, "/");
			tmp = ft_strcat(tmp, split[0]);
			if (access(tmp, F_OK | X_OK) == 0)
			{
				ft_ex_bin(tmp, split, e);
				return ;
			}
			ft_strdel(&tmp);
			i++;
		}
		ft_putstr("zsh: command not found: ");
		ft_putendl(split[0]);
	}
}