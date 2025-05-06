/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-05 11:37:54 by vdeliere          #+#    #+#             */
/*   Updated: 2025-05-05 11:37:54 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isalnum(int character)
{
	if (character >= 'a' && character <= 'z')
		return (1);
	if (character >= 'A' && character <= 'Z')
		return (1);
	if (character >= '0' && character <= '9')
		return (1);
	return (0);
}
char	*get_env_value(const char *name)
{
	int		len;
	char	*value;
	
	len = ft_strlen(name);
	value = getenv(name);
	if (!value)
		return ("");
	else
		return (value + len + 1);
}
