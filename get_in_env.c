/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_in_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 08:25:34 by jbahus            #+#    #+#             */
/*   Updated: 2015/10/13 16:16:37 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*get_in_env(char *str, char **env)
{
	int		i;
	char	*tmp;

	i = 0;
	while (ft_strncmp(env[i], str, ft_strlen(str)) != 0 && env[i])
		i++;
	if (!env[i])
		return (NULL);
	tmp = env[i];
	while (*tmp != '=' && env)
		tmp++;
	tmp++;
	return (tmp);
}
