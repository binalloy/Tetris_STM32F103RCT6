#include "scene.h"
#include "millis.h"
#include "button.h"
#include "game.h"
#include "ui.h"
#include <stdlib.h>

void (*scene_task)(void);

void start_scene() {
  ;
}

void rank_scene() {
  ;
}

void game_scene() {
  // tetromino fall down task
  if(millis() - fall_task_stamp >= tet_fall_interval){
    fall_task_stamp += tet_fall_interval;
    fall_down_task();
  }
}

void sw_game_scene(){
  // asign button function
  r_up->press_fun = tet_rotation;
  r_down->press_fun = tet_fall_speedup;
  r_left->press_fun = tet_move_left;
  r_right->press_fun = tet_move_right;
  r_confirm->press_fun = sw_rank_sence;
  r_return->press_fun = NULL;
  k_wakeup->press_fun = tet_rotation;
  k_key0->press_fun = tet_move_right;
  k_key1->press_fun = tet_move_left;
  r_up->release_fun = NULL;
  r_down->release_fun = tet_fall_normal;
  r_left->release_fun = NULL;
  r_right->release_fun = NULL;
  r_confirm->release_fun = NULL;
  r_return->release_fun = NULL;
  k_wakeup->release_fun = NULL;
  k_key0->release_fun = NULL;
  k_key1->release_fun = NULL;
  // scene_task
  scene_task = game_scene;
  fall_task_stamp = millis();
  // display
  LCD_Clear(WHITE);
  draw_bg();
  draw_name(hiscore.name);
  grid_render();
  draw_tetromino(0);
  draw_next_tetromino(0);
}

void sw_rank_sence() {
  // asign button function
  r_up->press_fun = NULL;
  r_down->press_fun = NULL;
  r_left->press_fun = NULL;
  r_right->press_fun = NULL;
  r_confirm->press_fun = sw_game_scene;
  r_return->press_fun = NULL;
  k_wakeup->press_fun = NULL;
  k_key0->press_fun = NULL;
  k_key1->press_fun = NULL;
  r_up->release_fun = NULL;
  r_down->release_fun = NULL;
  r_left->release_fun = NULL;
  r_right->release_fun = NULL;
  r_confirm->release_fun = NULL;
  r_return->release_fun = NULL;
  k_wakeup->release_fun = NULL;
  k_key0->release_fun = NULL;
  k_key1->release_fun = NULL;
  // scence task
  scene_task = NULL;
  // display
  draw_rank_list();
}

void scence_switch(){
  ;
}
