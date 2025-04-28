/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:39:55 by ertrigna          #+#    #+#             */
/*   Updated: 2025/04/28 15:27:55 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_quote(char c)
{
	if (c == '\'')
		return (1);
	else if (c == '"')
		return (2);
	return (0);
}

int	is_token(char *str, int i)
{
	if (str[i] == '|')
		return (PIPE);
	if (str[i] == '<')
	{
		if (str[i + 1] == '<')
			return (HEREDOC);
		else
			return (REDIR_IN);
	}
	if (str[i] == '>')
	{
		if (str[i + 1] == '>')
			return (APPEND);
		else
			return (REDIR_OUT);
	}
	return (0);
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	handle_word(t_token_list *tokens, char *input, int *index)
{
	int		start;
	t_lexer	*new_token;
	
	start = *index;
	while (input[*index] && !is_space(input[*index]) && !is_token(input ,*index))
	{
		char	quote;
		if (is_quote(input[*index]))
		{
			quote = input[*index];
			(*index)++;
			while (input[*index] && input[*index] != quote)
				(*index++);
			if (input[*index] == quote)
				(*index)++;
		}
		else
			(*index)++;
	}
	new_token = create_token(ft_substr(input, start, *index - start), WORD);
	add_token_to_list(tokens, new_token);
}

void	free_tokens(t_lexer	*head)
{
	t_lexer *tmp;

	while (head)
	{
		tmp = head->next;
		if (head->value)
			free(head->value);
		free(head);
		head = tmp;
	}
}
