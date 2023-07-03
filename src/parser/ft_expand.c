/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:54:35 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/03 20:22:40 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_expand(t_env *list, char *variable)
{
	char	*str;
	char	*tmp;

	tmp = ft_strtrim(variable, "$");
	printf("%s\n", tmp);
	str = ft_capitalize(tmp);
	printf("%s\n", str);
	free(tmp);
	if(ft_strcmp(str, "?") == 0)
	{
		return (ft_itoa(g_exit_status));
	}
	while (list)
	{
		if (ft_strcmp(str, list->name) == 0)
			return (list->info);
		list = list->next;
	}
	free(str);
	return (NULL);
}

