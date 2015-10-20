/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 17:34:20 by jbahus            #+#    #+#             */
/*   Updated: 2015/10/20 16:50:12 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*ft_del_pwd(char *ret)
{
	int		i;

	i = 0;
	while (ret[i])
		i++;
	while (ret[i] != '/')
		i--;
	if (i - 1 < 0)
		i++;
	while (ret[i])
		ret[i++] = '\0';
	return (ret);
}

char	*ft_add_pwd(char *ret, char *str)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(ret) + ft_strlen(str) + 2);
	tmp = ft_strcat(tmp, ret);
	tmp = ft_strcat(tmp, "/");
	tmp = ft_strcat(tmp, str);
	ft_strdel(&ret);
	return (tmp);
}

char	*ft_pwd(char *str, char *ret)
{
	DIR		*dir;

	dir = NULL;
	if (ft_strequ(str, "."))
		return (ret);
	else if (ft_strequ(str, ".."))
		ret = ft_del_pwd(ret);
	else
		ret = ft_add_pwd(ret, str);
	return (ret);
}

char	**ft_change_pwd(char **e, char *str)
{
	int		i;

	i = 0;
	while (ft_strncmp(e[i], "PWD=", 4) != 0)
		i++;
	ft_strdel(&e[i]);
	e[i] = ft_strnew(ft_strlen(str) + 5);
	e[i] = ft_strcat(e[i], "PWD=");
	e[i] = ft_strcat(e[i], str);
	ft_strdel(&str);
	return (e);
}

char	**ft_cd(char **split, char **e)
{
	int		i;
	char	**path;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (split[1] && e[0] && ft_check_cd(split))
	{
		path = ft_strsplit(split[1], '/');
		tmp = ft_strdup(get_in_env("PWD=", e));
		while (path[i])
		{
			tmp = ft_pwd(path[i], tmp);
			i++;
		}
		e = ft_change_pwd(e, tmp);
	}
	chdir(get_in_env("PWD=", e));
	return (e);
}
