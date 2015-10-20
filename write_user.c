/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_user.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 08:45:11 by jbahus            #+#    #+#             */
/*   Updated: 2015/10/13 16:16:38 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	write_user(char **env)
{
	if (get_in_env("USER=", env) != NULL)
	{
		ft_putstr("\033[1;34m");
		ft_putstr(get_in_env("USER=", env));
		ft_putstr("\033[0m ");
	}
	ft_putstr("\033[1;31m$> \033[0m");
}
