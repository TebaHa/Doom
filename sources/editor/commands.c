/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:25:23 by djast             #+#    #+#             */
/*   Updated: 2019/10/21 13:02:48 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	add_command(t_commands **commands, int type)
{
	t_commands *command;
	t_commands *tmp;

	command = (t_commands *)malloc(sizeof(t_commands));
	command->type = type;
	if (commands == NULL)
		*commands = command;
	else
	{
		tmp = *commands;
		*commands = command;
		(*commands)->next = tmp;
	}
}

void	delete_last_command(t_sdl *sdl)
{
	t_commands	*tmp;
	int			type;

	// (void)*sdl; //НАДО ЛИ?
	if (sdl->commands == NULL)
		return ;
	tmp = sdl->commands;
	sdl->commands = sdl->commands->next;
	type = tmp->type;
	free(tmp);
	if (type == WALL_TYPE)
		remove_last_point(&(sdl->sectors));
	if (type == PLAYER_TYPE)
		delete_player(sdl->player);
	if (type == SPRITE_TYPE)
		remove_last_sprite(&(sdl->sprites));
}
