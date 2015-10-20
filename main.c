/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 14:11:40 by jbahus            #+#    #+#             */
/*   Updated: 2015/10/20 16:49:48 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	**ft_create_env(char **envp)
{
	char	**e;
	int		i;

	e = (char**)malloc(sizeof(char*) * ENV_SIZE);
	i = 0;
	while (envp[i])
	{
		e[i] = ft_strdup(envp[i]);
		i++;
	}
	e[i] = NULL;
	return (e);
}

int		main(int ac, char **av, char **envp)
{
	char	**e;
	char	*buf;
	int		ret;
	char	*line;

	e = NULL;
	(void)ac;
	(void)av;
	line = NULL;
	buf = ft_strnew(BUFF_SIZE);
	if (envp)
		e = ft_create_env(envp);
	write_user(e);
	while ((ret = read(0, buf, BUFF_SIZE)))
	{
		buf[ret - 1] = '\0';
		if (buf[0])
			do_stuff(buf, &e);
		write_user(e);
	}
	ft_putendl("");
	return (0);
}
