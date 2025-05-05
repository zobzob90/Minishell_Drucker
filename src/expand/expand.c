/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:32:47 by valentin          #+#    #+#             */
/*   Updated: 2025/04/29 15:52:44 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char *expand_token(char *token)
{
    char    *res;
    int     i;

    res = malloc(sizeof(char *));
    if (!res)
        return (NULL);
    i = 0;
    while (token[i])
    {
        if (token[i] == '\'')
            res = join_literal(res, token, &i);
        else if (token[i] == '\"')
            res = join_double_quote(res, token, &i);
        else if (token[i] == '$')
            res = join_dollar(res, token, &i);
        else
            res = join_char(res, token[i++]);
    }
    return (res);
}

void    expand_all_tokens(t_lexer *head)
{
    char    *new;
    while (head)
    {
        new = expand_token(head->value);
        if (!new)
            return ;
        free(head->value);
        head->value = new;
        head = head->next;
    }
}

