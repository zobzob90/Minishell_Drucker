/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:31:39 by ertrigna          #+#    #+#             */
/*   Updated: 2025/04/28 13:32:40 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*create_token(char *value, t_token_type type)
{
	t_lexer	*token;

	token = malloc(sizeof(t_lexer));
	if (!token)
		return (NULL);
	if (value)
		token->value = ft_strdup(value);
	else
		token->value = NULL;
	token->type = type;
	token->next = NULL;
	return (token);
}

void	add_token_to_list(t_token_list *list, t_lexer *new_token)
{
	if (!list->head)
	{
		list->head = new_token;
		list->last = new_token;
	}
	else
	{
		list->last->next = new_token;
		list->last = new_token;
	}
}

