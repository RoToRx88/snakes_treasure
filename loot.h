#ifndef _LOOT_H_
# define _LOOT_H_

# include <stdio.h>
# include <stdlib.h>
# include "snake.h"


/**
@brief place les trésors et les vies
@param snake est un pointeur de structure t_snake

generate_loot place les trésors et les vies dans les salles

@return none
*/

void			generate_loot(t_snake *snake);

#endif //_LOOT_H_
