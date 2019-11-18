/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:51:43 by djast             #+#    #+#             */
/*   Updated: 2019/11/18 21:12:56 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int	get_ed_sector_count(t_ed_sector *sect)
{
	int count;

	count = 0;
	while (sect != NULL)
	{
		count++;
		sect = sect->next;
	}
	return (count);
}
