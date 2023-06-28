/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:39:38 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/06/28 14:58:44 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_print_env(t_ms *ms)
{
	t_env *list;

	list = ms->ms_env;
	while (list != NULL)
	{	
		if(ft_strcmp(list->name, "PWD") == 0 || ft_strcmp(list->name, "OLDPWD") == 0)
			printf("%s\n", list->full_info);
		list = list->next;
	}
}

