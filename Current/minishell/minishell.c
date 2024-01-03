/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:38:04 by ariazano          #+#    #+#             */
/*   Updated: 2024/01/02 18:31:04 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// start. still reading ...

# include "minishell.h"


int	main(int argc, char **argv, char *env)
{
	t_data	*data;

	init_shell_struct(&shell);

	data->input_argc = argc;
	data->input_argv = argv;


}

void	argv_to_list(t_data *data)
{

}

t_token *lstnew(char *type, int value)
{
	t_token	*new_node;

	new_node = (t_token *)malloc(sizeof(t_token));
	if (new_node)
	{
		new_node->type = type;
		new_node->value = value;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	return new_node;
}


