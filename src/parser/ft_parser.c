/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:56:37 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/03 10:31:39 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_parser(t_ms *ms, t_elem *list)
{
   	int			i;
	int			j;
	int			k;
	char		*tmp_str;
	int			counter;
	enum e_token	tmp;

	i = 0;
	counter = ft_count_tokens(list);
	ms->n_pipes = ft_count_pipes(list);
	ms->cmds = ft_calloc(ms->n_pipes * 2 + 2, sizeof(t_command));
		
	if (!ms->cmds)
		return ;
	while(i <= (ms->n_pipes * 2))
	{
		ms->cmds[i].args = ft_calloc(ms->count_args[i] + 1, sizeof(char *));
		if(!ms->cmds[i].args)
			return ; 
		i++;
	}
	tmp_str = NULL;
	i = 0;
	while (list != NULL)
	{
		j = 0;
		k = 0;
		char	*str;
		ms->cmds[i].redirs = ft_calloc(counter, sizeof(t_redirect));
		ms->cmds[i].type = CMD;
		while (list != NULL && list->type != PIPE_LINE)
		{
			str = NULL;
			if(list->type == ENV && list->status != IN_SQUOTE)
				ms->cmds[i].args[j] = ft_expand(ms->ms_env, list->data);
			else if(list->type == SINGLE_QUOTE)
			{
				if(list->status == IN_DQUOTE)
					str = ft_strjoin(tmp_str, list->data); 
				list = list->next;
				while(list->type != SINGLE_QUOTE)
				{
					if (!tmp_str)
					{
						str = ft_strdup(list->data);
						tmp_str = ft_strdup(list->data);
					}
					else
					{
						if (str)
							free (str);
						str = ft_strjoin(tmp_str, list->data);
						free(tmp_str);
						tmp_str = ft_strdup(str);
					}
					list = list->next;
				}
				if(list->status == IN_DQUOTE)
					str = ft_strjoin(tmp_str, list->data);
				ms->cmds[i].args[j] = str;
				free (tmp_str);
			}
			else if(list->type == DOUBLE_QUOTE)
			{
				if(list->status == IN_SQUOTE)
					str = ft_strjoin(tmp_str, list->data); 
				list = list->next;
				while(list->type != DOUBLE_QUOTE)
				{
					if(list->type == ENV)
					{
						if (str)
							free (str);
						str = ft_strdup(ft_expand(ms->ms_env, list->data));
					}
					else
					{
						if (!tmp_str)
						{
							str = ft_strdup(list->data);
							tmp_str = ft_strdup(list->data);
						}
						else
						{
							if (str)
								free (str);
							str = ft_strjoin(tmp_str, list->data);
							free(tmp_str);
							tmp_str = ft_strdup(str);
						}
					}
					list = list->next;
				}
				free (tmp_str);
				if(list->status == IN_SQUOTE)
					str = ft_strjoin(tmp_str, list->data);
				if(ft_strcmp(str, "") != 0)
					ms->cmds[i].args[j] = str;
			}
			else if(ft_is_redir(list->type))
			{
				ms->cmds[i].redirs[k].type = list->type;
				if (!list->next)
				{
					printf("bash: syntax error near unexpected token `newline'\n");
					return ;
				}
				list = list->next;
				while (list->type == WHITE_SPACE)
					list = list->next;
				if (list->type == DOUBLE_QUOTE || list->type == SINGLE_QUOTE)
				{
					tmp = list->type;
					list = list->next;
					while (tmp != list->type)
					{

						str = ft_strjoin(str, list->data); 
						list = list->next;
					}
					ms->cmds[i].redirs[k].arg = ft_strdup(str);
				}
				else
				{	
					//char *tmp = ms->cmds[i].redirs[k].arg;		
					ms->cmds[i].redirs[k].arg = ft_strdup(list->data);
					//free(tmp);
				}
				j--;
				k++;
			}
			else if (ms->cmds[i].args[j] != NULL)
			{
				ms->cmds[i].args[j] = ft_strjoin(ms->cmds[i].args[j], ft_strdup(list->data));
				if (list->next && (list->next->type == SINGLE_QUOTE || list->next->type == DOUBLE_QUOTE))
					j++;
			}
			else if (list->type != WHITE_SPACE)
			{
				ms->cmds[i].args[j] = ft_strdup(list->data);
				if (list->next && (list->next->type == SINGLE_QUOTE || list->next->type == DOUBLE_QUOTE))
					j++;
			}
			list = list->next;
			if(list && list->type == WHITE_SPACE)
				j++;
		}
		i++;
		j = 0;
		if(list != NULL && list->type == PIPE_LINE)
		{
			ms->cmds[i].args[j] = ft_strdup("|");
			ms->cmds[i].type = PIPE_LINE;
			list = list->next;	
		}
		i++;
	}
}

bool ft_is_not_redir(enum e_token type)
{
	if(type != REDIR_IN && type != REDIR_OUT && type != HERE_DOC && type != D_REDIR_OUT)
		return (true);
	return (false);
}
