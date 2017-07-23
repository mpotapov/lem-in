/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 14:33:37 by mpotapov          #+#    #+#             */
/*   Updated: 2017/07/22 15:32:37 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void	er(void)
{
	printf(RED"\n"
			" ____  ____  ____   __  ____ \n"
			"(  __)(  _ \\(  _ \\ /  \\(  _ \\\n"
			" ) _)  )   / )   /(  O ))   /\n"
			"(____)(__\\_)(__\\_) \\__/(__\\_)\n");
}

void	input(void)
{
	printf("Num_of_ants"
				GREY" Comments"
				BLUE" Rooms&Coordinates"
				RED" Commands"
				YELLOW" Links"
				"\033[0m\n");
}
