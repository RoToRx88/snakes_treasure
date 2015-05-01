#include "snake.h"
#include "assert.h"

void	display_guardian(t_snake *snake)
{
}



int		init_guardian(t_snake *snake, int i)
{
  t_guardian	*n;
  int		j = -1;

  n = &(snake->guardian[i]);
  while (++j < snake->guardian_size)
    {
      if (!(n->next = malloc(sizeof(t_guardian)))) return 1;
      n = n->next;
    }
  n->next = NULL;
  return 0;
}
