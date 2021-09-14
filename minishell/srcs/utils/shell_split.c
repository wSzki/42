/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:27:46 by wszurkow          #+#    #+#             */
/*   Updated: 2021/09/13 14:47:36 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
 *	; | < << > >> SPACE QUOTE DQUOTE
 */

/*static int is_token(char *c, char **tokens)*/
/*{*/
	/*int i;*/

	/*i = 0;*/
	/*while (tokens[i])*/



/*}*/


char **shell_split(char *cmd_str)
{
	int i;
	int origin;
	int head;

	char *tokens[10] = {";", "|", "<", "<", ">", ">", " ", "\"", "\'", NULL};

	i = 0;
	origin = 0;
	while (cmd_str[i])
	{


	}









}
