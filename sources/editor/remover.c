/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remover.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:39:39 by eharrag-          #+#    #+#             */
/*   Updated: 2019/11/18 21:23:24 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	remove_last_sprite(t_ed_sprite **sprites)
{
	t_ed_sprite *cur_sprite;
	t_ed_sprite *prev_sprite;

	prev_sprite = *sprites;
	cur_sprite = (*sprites)->next;
	if (cur_sprite == NULL)
	{
		free(prev_sprite);
		*sprites = NULL;
		return ;
	}
	while (cur_sprite->next != NULL)
	{
		prev_sprite = cur_sprite;
		cur_sprite = cur_sprite->next;
	}
	if (cur_sprite->next == NULL)
	{
		prev_sprite->next = NULL;
		free(cur_sprite);
	}
}

void	remove_last_point(t_ed_sector **head)
{
	t_ed_sector *cur_sector;
	t_ed_sector *prev_sector;

	prev_sector = *head;
	cur_sector = (*head)->next;
	if (cur_sector == NULL)
	{
		if (prev_sector->size > 0)
			delete_point(prev_sector);
		return ;
	}
	while (cur_sector->next != NULL)
	{
		prev_sector = cur_sector;
		cur_sector = cur_sector->next;
	}
	if (cur_sector->size > 0)
		delete_point(cur_sector);
	else if (cur_sector->size == 0)
	{
		prev_sector->next = NULL;
		free(cur_sector);
		delete_point(prev_sector);
	}
}
