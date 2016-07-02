/*
** life.h for life in /home/tchikl_h/rendu/B2/Infography/gfx_game_of_life
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Thu Apr 28 17:16:00 2016 Hervé TCHIKLADZE
** Last update Tue May  3 15:26:31 2016 Hervé TCHIKLADZE
*/

#ifndef GAME_OF_LIFE_H_
# define GAME_OF_LIFE_H_

#define SUCCESS 0
#define ERROR -1

#include <stdio.h>
#include <lapin.h>
#include <math.h>
#include "life_struct.h"

void		tekpixel(t_bunny_pixelarray *, t_bunny_position, unsigned int);
void		teksquare(t_bunny_pixelarray *, int, int, unsigned int);
void            display_board(t_life *);
int             init_board(t_life *);
int             game_of_life(t_life *);
int             init_save(t_life *);
void            my_free_all(t_life *);
void            my_free_tab(void ***);
void            my_free(void **);

#endif /* GAME_OF_LIFE_H_ */
