/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:32:18 by valentin          #+#    #+#             */
/*   Updated: 2025/04/29 16:53:49 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_literal(char *res, const char *token, int *i)
{
    int	start;

    (*i)++;
    start = *i;
    while (token[*i] && token[*i] != '\'')
    	(*i)++;
    res = ft_strjoin(res, ft_substr(token, start, *i - start));
    if (token [*i])
    	(*i)++;
    return (res);
}

char	*join_dollar(char *res, const char *token, int *i)
{
	char	*key;
	char	*val;
	int		start;

	(*i)++;
	// if (token[*i] == '?')
	// {
	// 	val = ft_itoa(g_exit_status)
		//(*i)++;
	// }  
	// else
	// {
	start = *i;
	while (ft_isalnum(token[*i]) || token[*i] == '_')
		(*i)++;
	key = ft_substr(token, start, *i - start);
	printf("KEY = %s\n", key);
	val = get_env_value(key);
	printf ("Join_dollar = %s\n", val);
	free(key);
	//}
	return (ft_strjoin(res, val));
}

char	*join_char(char *res, char c)
{
	char	tmp[2];

	tmp[0] = c;
	tmp[1] = '\0';
	return (ft_strjoin(res, ft_strdup(tmp)));
}

char	*join_double_quote(char *res, const char *token, int *i)
{
	(*i)++;
	while (token[*i] && token[*i] != '\"')
	{
		if (token[*i] == '$')
			res = join_dollar(res, token, i);
		else
			res = join_char(res, token[(*i)++]);
	}
	if (token[*i])
		(*i)++;
	return (res);
}

