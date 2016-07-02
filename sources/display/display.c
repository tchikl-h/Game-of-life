/*
** display.c for display in /home/tchikl_h/rendu/B2/Infography/gfx_game_of_life
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Thu Apr 28 18:40:43 2016 Hervé TCHIKLADZE
** Last update Thu Apr 28 18:56:29 2016 Hervé TCHIKLADZE
*/

#include "life.h"

void			display_board(t_life *data)
{
  t_bunny_position	pos;

  pos.y = 0;
  while (pos.y < 100)
    {
      pos.x = 0;
      while (pos.x < 100)
	{
	  if (data->board[pos.y][pos.x] == 0)
	    teksquare(data->graph->pix, pos.x, pos.y, BLACK);
	  if (data->board[pos.y][pos.x] == 1)
	    teksquare(data->graph->pix, pos.x, pos.y, YELLOW);
	  pos.x++;
	}
      pos.y++;
    }
}
