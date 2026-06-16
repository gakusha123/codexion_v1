/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 11:30:17 by btheveny          #+#    #+#             */
/*   Updated: 2026/05/28 13:12:29 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static void	put_error(char *message)
{
	write(2, message, strlen(message));
}

int	parser_error_arg_number(void)
{
	int	result;

	result = 1;
	put_error("Usage: ./codexion number_of_coders time_to_burnout ");
	put_error("time_to_compile time_to_debug time_to_refactor ");
	put_error("number_of_compiles_required dongle_cooldown scheduler\n");
	return (result);
}

static char	*get_reason(t_arg_error error)
{
	char	*reason;

	reason = "unknown error";
	if (error == ARG_EMPTY)
		reason = "empty value";
	else if (error == ARG_SIGN_ONLY)
		reason = "sign without digits";
	else if (error == ARG_NEGATIVE)
		reason = "negative value";
	else if (error == ARG_NOT_INTEGER)
		reason = "not an integer";
	else if (error == ARG_OVERFLOW)
		reason = "greater than INT_MAX";
	else if (error == ARG_NOT_POSITIVE)
		reason = "must be greater than 0";
	else if (error == ARG_BAD_SCHEDULER)
		reason = "expected fifo or edf";
	return (reason);
}

int	invalid_arg_error(char *name, char *value, t_arg_error error)
{
	int	result;

	result = 1;
	fprintf(stderr, "Invalid argument `%s`: `%s` (%s)\n",
		name, value, get_reason(error));
	return (result);
}
