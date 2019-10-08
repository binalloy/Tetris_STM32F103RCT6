#include "led.h"
#include "sys.h"
#include "usart.h"
#include "lcd.h"
#include "Remote.h"
#include "button.h"
#include "game.h"
#include "millis.h"
#include "grid.h"
#include "tetromino.h"
#include "scene.h"
#include "parameter.h"


int main(void){
  // init
  button_init();
  millis_init();
  uart_init(9600);
  LCD_Init();
  // save_rank_list();
  read_rank_list();
  // get into game scene
  sprintf(hiscore.name, "%s%d", "Player", (rand()%9)+1);
  game_reset();
  sw_game_scene();


  uint32_t button_task_stamp = millis();
  while(1){
    // update button status
    if(millis() - button_task_stamp >= button_scan_interval){
      button_task_stamp += button_scan_interval;
      button_task();
    }
    if(scene_task){
      scene_task();
    }
  }
}
