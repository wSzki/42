/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:57:24 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/13 21:21:52 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./display.h"

int     max_displayable_width(void)
{
	t_curse	*c;

	c = (t_curse *)get_curse();
	return (get_max_width(c->main));
}

int     board_max_displayable_height(void)
{
	t_curse	*c;

	c = (t_curse *)get_curse();
	return (get_max_height(c->main));
}

void    init_display(void)
{
	t_curse	*c;

	c = (t_curse *)get_curse();
	display_init(c);
}

void    display_board(void)
{
	t_curse	*c;
	t_board	*board;

	board = get_board();
	display_board_curse(c, board);
}



void    display_welcome(void)
{
	t_curse	*c;
	char	*msg;
	char	*m;

	c = (t_curse *)get_curse();
	msg = "Welcome to 42 NIM";
	m = "Press any key to continue";
	box(stdscr, 0, 0);
	wrefresh(stdscr);
	attron(A_BOLD);
	mvprintw(c->row / 2, (c->col - strlen(msg))/2,"%s",msg);
	attroff(A_BOLD);
	mvprintw(c->row / 2 + 1, (c->col - strlen(m))/2,"%s",m);
	getch();
	wclear(stdscr);
	wrefresh(stdscr);
	getch();
}

void    display_ai_move(int move)
{
	t_curse	*c;
	char *msg;

	msg = "Number of matches taken by AI: 0";
	msg[31] = move + 48;
	c = (t_curse *)get_curse();
	display_message(c->input, -1, msg);
}

void    display_info(char *msg)
{
	t_curse	*c;

	c = (t_curse *)get_curse();
	display_message(c->inst, -1, msg);
}

void    display_error(char *error)
{
	t_curse	*c;
	char	*msg;
	char	*m;

	c = (t_curse *)get_curse();
	msg = "[ERROR]";
	m = error;
	box(stdscr, 0, 0);
	wrefresh(stdscr);
	attron(A_BOLD);
	mvprintw(c->row / 2, (c->col - strlen(msg))/2,"%s",msg);
	attroff(A_BOLD);
	mvprintw(c->row / 2 + 1, (c->col - strlen(m))/2,"%s",m);
	getch();
	wclear(stdscr);
	wrefresh(stdscr);
}

void    display_winner(int player)
{
	t_curse	*c;
	char	*msg;
	char	*m;
	char *winner;


	c = (t_curse *)get_curse();
	msg = "GAME OVER";
	m = "The winner is ";
	if (player)
		winner = "player";
	else
		winner = "AI";
	box(stdscr, 0, 0);
	wrefresh(stdscr);
	attron(A_BOLD);
	mvprintw(c->row / 2, (c->col - strlen(msg))/2,"%s",msg);
	attroff(A_BOLD);
	mvprintw(c->row / 2 + 1, (c->col - strlen(m))/2,"%s",m);
	mvprintw(c->row / 2 + 2, (c->col - strlen(m))/2,"%s",winner);
	getch();
	wclear(stdscr);
	wrefresh(stdscr);
}

void    endgame(void);
