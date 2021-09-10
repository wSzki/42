/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:48:25 by adlancel          #+#    #+#             */
/*   Updated: 2021/09/09 17:29:44 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/adl_minishell.h"

void	store_strings(char *line, int i, size_t j)
{


}
void exit_quote(char *line, int id_quote)
{
	printf("quote open");
}
void quote_parsing(char *line)
{
	char **str;
	int quotes_number;
	int i;
	int j;

	i = 0;
	quotes_number = 0;
	while(line[i])
	{
		if (line[i] == '\'' || line[i] == '\"')
		{
			j = 0;
			while (line[i + j])
			{
				if (line[j] == '\'' || line[j] == '\"')
				{
					quotes_number++;
					store_string(line, i, j);
				}
			}
			quotes_number++;
		}
		i++;
	}


	if (quotes_number % 2)
		exit_quote(line, 1);
	else 
		printf ("quote good");











}
int main()
{
	quote_parsing("ceci est une \"string\"");
}
