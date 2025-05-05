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



// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	if (n < 1)
// 		return (0);
// 	while (i < (n - 1) && s1[i] != '\0' && s2[i] != '\0')
// 	{
// 		if (s1[i] != s2[i])
// 			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
// 		i++;
// 	}
// 	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
// }

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
