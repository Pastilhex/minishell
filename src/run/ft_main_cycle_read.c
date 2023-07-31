/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_cycle_read.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:59:46 by ialves-m          #+#    #+#             */
/*   Updated: 2023/07/31 09:46:06 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_main_cycle_read(t_ms *ms, char **read_content, char *prompt)
{
	ms->processes = 0;
	ft_handle_signals();
	*read_content = readline(prompt);
	ft_is_not_read_content(ms, *read_content);
	if (ft_strcmp(*read_content, "") == 0)
	{
		ft_free(*read_content);
		return (false);
	}
	return (true);
}
