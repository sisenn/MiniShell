/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarakus <ckarakus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 02:24:27 by ckarakus          #+#    #+#             */
/*   Updated: 2023/12/11 06:23:38 by ckarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quotes(t_main	*main)
{
	int	i;
	int	double_quotes;
	int	single_quotes;

	i = 0;
	double_quotes = 0;
	single_quotes = 0;
	while (main->input[i] != '\0')
	{
		if (single_quotes % 2 == 0 && main->input[i] == '\"')
			double_quotes++;
		if (double_quotes % 2 == 0 && main->input[i] == '\'')
			single_quotes++;
		i++;
	}
	if (double_quotes % 2 != 0 || single_quotes % 2 != 0)
	{
		main->err_no = 258;
		printf("monkeshell: syntax error near unexpected token\n");
		return (0);
	}
	return (1);
}

int	error_control(t_main *main)
{
	int	i;

	i = 0;
	if (!check_quotes(main))
		return (0);
	if (main->input[0] == ';' || main->input[0] == '|' || main->input[0] == '>'
		|| main->input[0] == '<')
	{
		main->err_no = 258;
		printf("monkeshell: syntax error near unexpected token\n");
		return (0);
	}
	while (main->input[i] != '\0')
	{
		if (main->input[i] == '|' && main->input[i + 1] == '|')
		{
			main->err_no = 258;
			printf("monkeshell: syntax error near unexpected token\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	free_main(t_main *main)
{
	lex_lstclear(&main->lexer_head);
	free(main->input);
}

void	start_shell(t_main *main)
{
	int		status;

	status = 0;
	while (1)
	{
		reset_main(main);
		main->input = readline(main->shell_name);
		if (!main->input)
			exit(1);
		if (history_check(main))
			add_history(main->input);
		if (main->input == NULL)
			exit(1);
		if (!error_control(main))
			free_main(main);
		/*else if (!ft_strncmp(main->input, "$?", 2))
		{
			error_code(main);
			main->err_no = 0;
		}*/
		else
			start_shell2(main, status);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_main	*main;

	(void)argc, (void)argv;
	clean_shell();
	main = malloc(sizeof(t_main));
	if (!main)
		return (0);
	init_main(main);
	init_lists(env, main);
	g_signal = 0;
	init_signal();
	main->shell_name = ft_strjoin(main->pwd, " > monkeshell$ ");
	start_shell(main);
	return (0);
}

/*#tab ls'i çalıştırıyor,
exit | exit command not found exit döndürüyor,
 heredocta ctrl + \ düzgün çalışmıyor, 
 grep a'da ctrl d 2. seferde çıkıyor tek seferde çıkmıyor, 
env'lerde son elemanı almıyor listeye,
env + argüman command not found döndürmeli*/