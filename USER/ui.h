#ifndef __UI_H
#define __UI_H
#include "sys.h"
#include "lcd.h"

void draw_bg(void);
void update_bg(void);
void update_main_bg(void);
void update_sub_bg(void);
void draw_block(u8 x, u8 y, u16 color, u8 mode);
void grid_render(void);
void sub_grid_render(void);
void draw_tetromino(uint8_t clear);
void draw_next_tetromino(uint8_t clear);
void draw_name(char* name);
void update_score(u16 score);
void draw_rank_list(void);

#endif
