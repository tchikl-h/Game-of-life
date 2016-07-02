/*
** life_struct.h for life_struct in /home/tchikl_h/rendu/B2/Infography/gfx_game_of_life
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Thu Apr 28 17:27:49 2016 Hervé TCHIKLADZE
** Last update Thu Apr 28 20:08:48 2016 Hervé TCHIKLADZE
*/

#ifndef LIFE_STRUCT_H_
# define LIFE_STRUCT_H_

typedef struct		s_graph
{
  t_bunny_pixelarray	*pix;
  t_bunny_window	*win;
}			t_graph;

typedef struct		s_life
{
  t_graph		*graph;
  int			**board;
  int			**save;
  int			pause;
}			t_life;

#endif /* LIFE_STRUCT_H_ */
