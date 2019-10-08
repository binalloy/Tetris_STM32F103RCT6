#ifndef GAME_H
#define GAME_H

#include "sys.h"
#include "parameter.h"

extern Hiscore_t hiscore;
extern uint32_t tet_fall_interval; //ms
extern uint32_t fall_task_stamp;

void tet_move_left(void);
void tet_move_right(void);
void tet_fall_speedup(void);
void tet_fall_normal(void);
void tet_rotation(void);
void fall_down_task(void);
void game_reset(void);

#endif
