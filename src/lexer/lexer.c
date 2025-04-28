/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:48:41 by ertrigna          #+#    #+#             */
/*   Updated: 2025/04/28 15:33:19 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token_list	*lexer(char *input)
{
    t_token_list	*tokens;
    int				index;

    tokens = malloc(sizeof(t_token_list));
    if (!tokens)
        return (NULL);
    tokens->head = NULL;
    tokens->last = NULL;
    index = 0;
    while (input[index])
    {
        if (is_space(input[index]))
            while (input[index] && is_space(input[index]))
                index++;
        else if (is_token(input, index))
        {
            t_lexer *new_token = create_token(ft_substr(input, index, 
                (is_token(input, index) == HEREDOC || is_token(input, index) == APPEND) ? 2 : 1), 
                is_token(input, index));
            add_token_to_list(tokens, new_token);
            index += (is_token(input, index) == HEREDOC || is_token(input, index) == APPEND) ? 2 : 1;
        }
        else
            handle_word(tokens, input, &index);
    }

    return (tokens);
}
