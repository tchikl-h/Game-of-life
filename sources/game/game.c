/*
** game.c for game in /home/tchikl_h/rendu/B2/Infography/gfx_game_of_life
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Thu Apr 28 18:48:05 2016 Hervé TCHIKLADZE
** Last update Sat Jul  2 01:23:33 2016 Hervé TCHIKLADZE
*/

#include "life.h"

int		init_board(t_life *data)
{
  int		x;
  int		y;

  y = 0;
  data->board = NULL;
  if (!(data->board = malloc(sizeof(*data->board) * (100 + 1))))
    return (ERROR);
  while (y < 100)
    {
      if (!(data->board[y] = malloc(sizeof(*data->board[y]) * (100 + 1))))
	return (ERROR);
      x = 0;
      while (x < 100)
	{
	  data->board[y][x] = 0;
	  x++;
	}
      data->board[y][x] = -1;
      y++;
    }
  data->board[y] = NULL;
  return (SUCCESS);
}

int		init_save(t_life *data)
{
  int		x;
  int		y;

  y = 0;
  /* I'm actually working with two arrays (board and save) because we can't apply the changes in just one */
  data->save = NULL;
  if (!(data->save = malloc(sizeof(*data->save) * (100 + 1))))
    return (ERROR);
  while (y < 100)
    {
      if (!(data->save[y] = malloc(sizeof(*data->save[y]) * (100 + 1))))
	return (ERROR);
      x = 0;
      while (x < 100)
	{
	  data->save[y][x] = 0;
	  x++;
	}
      data->save[y][x] = -1;
      y++;
    }
  data->save[y] = NULL;
  return (SUCCESS);
}

int		count_around(int **board, int x, int y)
{
  int		nb;

  nb = 0;
  /* the purpose of this function is to count the neighbours of the cell */
  if (x > 0 && board[y][x - 1] == 1)
    nb++;
  if (x < 100 && board[y][x + 1] == 1)
    nb++;
  if (y > 0 && board[y - 1][x] == 1)
    nb++;
  if (y < 99 && board[y + 1][x] == 1)
    nb++;
  if (x > 0 && y > 0 && board[y - 1][x - 1] == 1)
    nb++;
  if (x < 100 && y < 99 && board[y + 1][x + 1] == 1)
    nb++;
  if (x > 0 && y < 99 && board[y + 1][x - 1] == 1)
    nb++;
  if (x < 100 && y > 0 && board[y - 1][x + 1] == 1)
    nb++;
  return (nb);
}

void		cpy_board(t_life *data)
{
  int		x;
  int		y;

  y = 0;
  while (y < 100)
    {
      x = 0;
      while (x < 100)
	{
	  data->board[y][x] = data->save[y][x];
	  x++;
	}
      y++;
    }
}

int		game_of_life(t_life *data)
{
  int		x;
  int		y;
  int		neighbour;
  int		dep;

  y = 0;
  while (y < 100)
    {
      x = 0;
      while (x < 100)
	{
	  neighbour = count_around(data->board, x, y);
	  dep = 0;
	  /* Here we will create a cell if we need to */
	  if (data->board[y][x] == 0 && neighbour == 3)
	    {
	      data->save[y][x] = 1;
	      dep++;
	    }
	  if (data->board[y][x] == 1 && dep == 0 && (neighbour < 2 || neighbour > 3))
	    {
	      data->save[y][x] = 0;
	      dep++;
	    }
	  if (data->board[y][x] == 1 && dep == 0)
	    data->save[y][x] = 1;
	  x++;
	}
      y++;
    }
  cpy_board(data);
  return (SUCCESS);
}
