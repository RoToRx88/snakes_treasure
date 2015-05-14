#ifndef _PLAYER_H_
# define _PLAYER_H_

# include <stdio.h>
# include <stdlib.h>
# include "snake.h"




/**
@brief déplace le personnage
@param snake est un pointeur de structure t_snake

move_player déplace le personnage selon la touche saisit par l'utilisateur sans qu'il puisse rentrer dans les murs

@return none
*/

void			move_player(t_snake *snake, int motion);


#endif //_PLAYER_H_
