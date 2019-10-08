#include "game.h"
#include "tetromino.h"
#include "ui.h"
#include "lcd.h"
#include "grid.h"
#include <stdio.h>
#include <stdlib.h>

Hiscore_t hiscore;
uint32_t tet_fall_interval; //ms
uint32_t fall_task_stamp;

void tet_move_left(){
  if(left_shift_check()){
    draw_tetromino(1);
    tetromino.x -= 1;
    draw_tetromino(0);
  }
}

void tet_move_right(){
  if(right_shift_check()){
    draw_tetromino(1);
    tetromino.x += 1;
    draw_tetromino(0);
  }
}

void tet_fall_speedup(){
  tet_fall_interval = 150;
}

void tet_fall_normal(){
  tet_fall_interval = 500;
}

void tet_rotation(){
  if(rotation_check()){
    draw_tetromino(1);
    tetromino.rotation = (tetromino.rotation + 1)%4;
    draw_tetromino(0);
  }
}

uint8_t game_fail_check() {
  s8 a, b;
	u8 i;
	Image_t* it = &tetimg_list[tetromino.shape];
	for(i=0;i<4;i++)
	{
	  a = it->x[tetromino.rotation][i]+tetromino.x;
	  b = it->y[tetromino.rotation][i]+tetromino.y;
	  if(!grid[b][a].isEmpty) {return 1;}
  }
  return 0;
}

void fall_down_task() {
  if(down_shift_check()){
    draw_tetromino(1);
    tetromino.y -= 1;
    draw_tetromino(0);
  } else {
    flush_tetromino();
    uint8_t row_num = grid_scan();
    if(row_num){
      hiscore.score += row_num*10;
      update_score(hiscore.score);
      grid_render();
    }
    // new tetromino
    draw_next_tetromino(1);
    tetromino_reset();
    if(!game_fail_check()){
      draw_tetromino(0);
      draw_next_tetromino(0);
    } else{
      // game over
      add_rank(hiscore);
      game_reset();
    }
  }
}

void game_reset() {
  // entity
  grid_init();
  sub_grid_init();
  tetromino_init();
  hiscore.score = 0;
  tet_fall_normal();
  // display
  LCD_Clear(WHITE);
  draw_bg();
  draw_name(hiscore.name);
  draw_tetromino(0);
  draw_next_tetromino(0);
}
