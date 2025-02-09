/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_not_read_content.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 00:00:32 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/28 18:52:50 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_is_not_read_content(t_ms *ms, char *read_content)
{
	if (!read_content)
	{
		printf("exit\n");
		ft_free_env(ms->ms_env);
		ft_free_env(ms->export_list);
		ft_free_array(ms->paths);
		exit(0);
	}
}
