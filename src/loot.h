#ifndef _LOOT_H_
# define _LOOT_H_

# include <stdio.h>
# include <stdlib.h>

typedef struct		s_Loot
{
  unsigned int		pos_x;
  unsigned int		pos_y;
  unsigned int		type; /*ORBE ou LIFE*/
  unsigned int		taked; /*0 = non pris, 1 = pris*/
}			t_Loot;

#endif //_LOOT_H_
