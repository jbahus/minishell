/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 15:52:37 by jbahus            #+#    #+#             */
/*   Updated: 2015/10/20 18:28:47 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# define BUFF_SIZE 1024
# define ENV_SIZE 4096

void	do_stuff(char *line, char ***e);
char	**ft_cd(char **split, char **e);
void	write_user(char **env);
char	*get_in_env(char *str, char **env);
char	**ft_new_env(char **env, char *new_e);
char	**ft_del_env(char **env, char *str);
int		ft_check_cd(char **split);
void	ft_check_path(char **split, char **e);

#endif
