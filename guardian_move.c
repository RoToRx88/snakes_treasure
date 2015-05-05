#include "snake.h"

void            guard_0(t_guardian *g)
{
  if (g->pos_y == 8 && g->pos_x > 1) g->pos_x -= 1;
  else if (g->pos_x == 1 && g->pos_y > 1) g->pos_y -= 1;
  else if (g->pos_y == 1 && g->pos_x < 8) g->pos_x += 1;
  else if (g->pos_x == 8 && g->pos_y < 8) g->pos_y += 1;
}

void            guard_1(t_guardian *g)
{
  if (g->pos_y == 8 && g->pos_x > 9) g->pos_x -= 1;
  else if (g->pos_x == 9 && g->pos_y > 1) g->pos_y -= 1;
  else if (g->pos_y == 1 && g->pos_x < 16) g->pos_x += 1;
  else if (g->pos_x == 16 && g->pos_y < 8) g->pos_y += 1;
}

void            guard_2(t_guardian *g)
{
  if (g->pos_y == 16 && g->pos_x > 1) g->pos_x -= 1;
  else if (g->pos_x == 1 && g->pos_y > 9) g->pos_y -= 1;
  else if (g->pos_y == 9 && g->pos_x < 8) g->pos_x += 1;
  else if (g->pos_x == 8 && g->pos_y < 16) g->pos_y += 1;
}

void            guard_3(t_guardian *g)
{
  if (g->pos_y == 16 && g->pos_x > 9) g->pos_x -= 1;
  else if (g->pos_x == 9 && g->pos_y > 9) g->pos_y -= 1;
  else if (g->pos_y == 9 && g->pos_x < 16) g->pos_x += 1;
  else if (g->pos_x == 16 && g->pos_y < 16) g->pos_y += 1;
}

void            calc_guardian_pos(t_snake *snake)
{
  int           i = -1;
  t_guardian    *n;

  while (++i < 4)
    {
      n = &(snake->guardian[i]);
      while (n->next)
        {
          if (0 == i) guard_0(n);
          else if (1 == i) guard_1(n);
          else if (2 == i) guard_2(n);
          else if (3 == i) guard_3(n);
          n = n->next;
        }
    }
}
