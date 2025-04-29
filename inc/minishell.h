/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:39:13 by ertrigna          #+#    #+#             */
/*   Updated: 2025/04/29 15:57:50 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/syscall.h>
# include <sys/sysinfo.h>
# include <sys/wait.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum	e_token_type
{
	WORD,
	PIPE,
	REDIR_OUT, // >
	REDIR_IN, // <
	APPEND, // >>
	HEREDOC, // <<
}	t_token_type;
/**************************/
/******PARSING STRUCT******/
/**************************/
typedef struct t_command
{
	char	**args; // arguments
	int		redir_in; // redirection d'entrée
	int		redir_out; // redirection de sortie
	struct s_command *next; // prochaine commande
} t_command;
/**************************/
/*******LEXER STRUCT*******/
/**************************/
typedef struct s_lexer
{
	char			*value;
	t_token_type	type;
	struct s_lexer	*next;
} t_lexer;

typedef struct s_token_list
{
	t_lexer	*head;
	t_lexer *last;
}	t_token_list;
/**************************/
/*******SHELL STRUCT*******/
/**************************/
typedef struct s_shell
{
	int		temp_excode; // code d'exit temporaire
	int		excode; //code d'exit globale
	char	*input;	//pointeur vers la ligne de commande acutelle
	int		last_exit;
} t_shell;
/*LEXER*/
t_token_list	*lexer(char *input);
/*LEXER_UTILS*/
void			free_tokens(t_lexer	*head);
int				is_quote(char c);
int				is_space(char c);
int				is_token(char *str, int i);
t_lexer			*create_token(char *value, t_token_type type);
void			add_token_to_list(t_token_list *list, t_lexer *new_token);
int				check_unclosed_quote(const char *input);
void			handle_word(t_token_list *tokens, char *input, int *index);
/*PARSING*/

/*PARS_UTILS*/

/*EXEC*/

/*EXEC_UTILS*/

/*MAIN*/

/*UTILS*/

#endif