/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:50:04 by ertrigna          #+#    #+#             */
/*   Updated: 2025/04/29 14:12:02 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void print_tokens(t_token_list *tokens)
{
    t_lexer *current = tokens->head;
    printf("--------- Tokens list ---------\n");
    while (current)
    {
        printf("Type: ");
        if (current->type == WORD)
            printf("WORD");
        else if (current->type == PIPE)
            printf("PIPE");
        else if (current->type == REDIR_IN)
            printf("REDIR_IN (<)");
        else if (current->type == REDIR_OUT)
            printf("REDIR_OUT (>)");
        else if (current->type == HEREDOC)
            printf("HEREDOC (<<)");
        else if (current->type == APPEND)
            printf("APPEND (>>)");
        else
            printf("UNKNOWN");
        
        printf(" | Value: [%s]\n", current->value);
        current = current->next;
    }
    printf("--------------------------------\n");
}

#include "minishell.h"

int main(void)
{
	t_shell shell;

	shell.excode = 0;
	shell.input = NULL;

	while (1)
	{
		shell.input = readline("minishell$ > ");
		if (!shell.input)
		{
			printf("exit\n");
			break;	
		}
		if (*shell.input) // ligne non vide
			add_history(shell.input);
		// === LEXER ===
		t_token_list *tokens = lexer(shell.input);
		// === DEBUG ===
		print_tokens(tokens);
		expand_all_tokens(tokens->head);
		printf("Expanded :\n");
		print_tokens(tokens);
		// === FREE ===
		free_tokens(tokens->head);
		free(tokens);
		free(shell.input);
	}
	return (0);
}
