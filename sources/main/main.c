/*
** main.c for main in /home/tchikl_h/rendu/B2/Infography/gfx_game_of_life
** 
** Made by Hervé TCHIKLADZE
** Login   <tchikl_h@epitech.net>
** 
** Started on  Thu Apr 28 17:14:15 2016 Hervé TCHIKLADZE
** Last update Sat Jul  2 01:15:22 2016 Hervé TCHIKLADZE
*/

#include "life.h"

t_bunny_response        mouse_draw(t_bunny_event_state  state,
                                   t_bunny_mousebutton  button,
                                   void                 *your_data)
{
  t_life                *data;
  const t_bunny_position *pos;

  data = (t_life *)your_data;
  (void)button;
  if (state == GO_DOWN)
    {
      /* Here we interrupt mouse position and apply it to the board */
      pos = bunny_get_mouse_position();
      data->board[pos->x / 10][pos->y / 10] = 1;
    }
  return (GO_ON);
}

t_bunny_response	echap_down(t_bunny_event_state	state,
				   t_bunny_keysym	key,
				   void			*your_data)
{
  t_life		*data;
  int			dep;

  dep = 0;
  data = (t_life *)your_data;
  if (state == GO_DOWN)
    {
      if (key == BKS_ESCAPE)
	return (EXIT_ON_SUCCESS);
      if (key == BKS_SPACE)
	{
	  if (data->pause == 0)
	    {
	      data->pause = 1;
	      dep++;
	    }
	  if (data->pause == 1 && dep == 0)
	    data->pause = 0;
	}
    }
  return (GO_ON);
}

t_bunny_response	loop(void *pass)
{
  t_life		*data;
  t_bunny_key		key;
  t_bunny_click		mouse;

  data = (t_life *)pass;
  key = &echap_down;
  mouse = &mouse_draw;
  /* These functions below will interrupt signals from the mouse/keyboard */
  bunny_set_key_response(key);
  bunny_set_click_response(mouse);
  if (data->pause == 1)
    game_of_life(data);
  display_board(data);
  /* Blitting the buffer to the clipable in order to "synchronize" the changes */
  bunny_blit(&data->graph->win->buffer, &data->graph->pix->clipable, NULL);
  bunny_display(data->graph->win);
  return (GO_ON);
}

int			main()
{
  t_life		data;
  t_bunny_loop		main_loop;

  main_loop = &loop;
  if (!(data.graph = malloc(sizeof(*data.graph))))
    return (ERROR);
  data.pause = 0;
  /* Initialization of the Window */
  data.graph->pix = bunny_new_pixelarray(1000, 1000);
  data.graph->win = bunny_start(1000, 1000, false, "Game Of Life");
  if (init_board(&data) == ERROR)
    return (ERROR);
  if (init_save(&data) == ERROR)
    return (ERROR);
  /* Initialization and settings of the Main Loop which will allow you to modify/refresh your display */
  bunny_set_loop_main_function(main_loop);
  bunny_loop(data.graph->win, 10, &data);
  bunny_stop(data.graph->win);
  bunny_delete_clipable(&data.graph->pix->clipable);
  return (SUCCESS);
}
