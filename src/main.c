/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:50:04 by ertrigna          #+#    #+#             */
/*   Updated: 2025/04/28 11:23:25 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
	t_shell shell;
	shell.excode = 0;
	shell.input = 0;
	
	while (1)
	{
		shell.input = readline("minishell$ > ");
		if (!shell.input)
		{
			printf("exit\n");
			break ;	
		}
		free (shell.input);
	}
	return (0);
}
