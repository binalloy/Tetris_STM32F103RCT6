#ifndef SCENE_H
#define SCENE_H

#include "sys.h"

extern void (*scene_task)(void);

void sw_game_scene(void);
void sw_rank_sence(void);

#endif
