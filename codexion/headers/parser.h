/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 11:29:06 by btheveny          #+#    #+#             */
/*   Updated: 2026/05/28 13:08:01 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_config	t_config;

typedef enum e_arg_error
{
	ARG_OK,
	ARG_EMPTY,
	ARG_SIGN_ONLY,
	ARG_NEGATIVE,
	ARG_NOT_INTEGER,
	ARG_OVERFLOW,
	ARG_NOT_POSITIVE,
	ARG_BAD_SCHEDULER
}	t_arg_error;

int	parser_error_arg_number(void);
int	invalid_arg_error(char *name, char *value, t_arg_error error);
int	parser(int ac, char **av, t_config *config);

#endif
