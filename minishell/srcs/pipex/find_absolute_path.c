/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_absolute_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:44:11 by adlancel          #+#    #+#             */
/*   Updated: 2021/09/10 14:43:46 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*find_absolute_path(char *cmd)
{
	char	*str;
	char	**all_paths;
	char	*tmp_path;
	char	*valid_path;
	int		i;

	i = 0;
	str = getenv("PATH");
	all_paths = ft_split(str, ':');
	while (all_paths[i])
	{
		tmp_path = ft_strjoin(all_paths[i], "/");
		valid_path = ft_strjoin(tmp_path, cmd);
		if (access(valid_path, F_OK) != -1)
		{
			free(tmp_path);
			free(all_paths[i]);
			free(all_paths);
			return (valid_path);
		}
		free(tmp_path);
		tmp_path = NULL;
		free(valid_path);
		valid_path = NULL;
		free(all_paths[i]);
		i++;
	}
	/*error();*/
	free(all_paths);
	return (NULL);
}
