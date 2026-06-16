/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 11:25:57 by btheveny          #+#    #+#             */
/*   Updated: 2026/05/28 13:14:28 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static char	*get_arg_name(int index)
{
	char	*name;

	name = "unknown";
	if (index == 1)
		name = "number_of_coders";
	else if (index == 2)
		name = "time_to_burnout";
	else if (index == 3)
		name = "time_to_compile";
	else if (index == 4)
		name = "time_to_debug";
	else if (index == 5)
		name = "time_to_refactor";
	else if (index == 6)
		name = "number_of_compiles_required";
	else if (index == 7)
		name = "dongle_cooldown";
	else if (index == 8)
		name = "scheduler";
	return (name);
}

static t_arg_error	get_arg_error(char *arg, int must_be_positive)
{
	long	nb;

	nb = 0;
	if (!arg || *arg == '\0')
		return (ARG_EMPTY);
	if (*arg == '-')
		return (ARG_NEGATIVE);
	if (*arg == '+')
		arg++;
	if (*arg == '\0')
		return (ARG_SIGN_ONLY);
	while (*arg)
	{
		if (!is_digit(*arg))
			return (ARG_NOT_INTEGER);
		nb = (nb * 10) + (*arg - '0');
		if (nb > INT_MAX)
			return (ARG_OVERFLOW);
		arg++;
	}
	if (must_be_positive && nb == 0)
		return (ARG_NOT_POSITIVE);
	return (ARG_OK);
}

static t_arg_error	get_scheduler_error(char *arg)
{
	t_arg_error	error;

	error = ARG_OK;
	if (!arg)
		error = ARG_EMPTY;
	else if (strcmp(arg, "fifo") != 0 && strcmp(arg, "edf") != 0)
		error = ARG_BAD_SCHEDULER;
	return (error);
}

static void	fill_config(t_config *config, char **av)
{
	config->number_of_coders = atoi(av[1]);
	config->time_to_burnout = atoi(av[2]);
	config->time_to_compile = atoi(av[3]);
	config->time_to_debug = atoi(av[4]);
	config->time_to_refactor = atoi(av[5]);
	config->number_of_compiles_required = atoi(av[6]);
	config->dongle_cooldown = atoi(av[7]);
	if (strcmp(av[8], "fifo") == 0)
		config->scheduler = SCHEDULER_FIFO;
	else
		config->scheduler = SCHEDULER_EDF;
}

int	parser(int ac, char **av, t_config *config)
{
	int			i;
	t_arg_error	error;

	if (ac != 9)
		return (parser_error_arg_number());
	i = 1;
	while (i <= 7)
	{
		error = get_arg_error(av[i], i == 1);
		if (error != ARG_OK)
			return (invalid_arg_error(get_arg_name(i), av[i], error));
		i++;
	}
	error = get_scheduler_error(av[8]);
	if (error != ARG_OK)
		return (invalid_arg_error(get_arg_name(8), av[8], error));
	fill_config(config, av);
	return (0);
}
