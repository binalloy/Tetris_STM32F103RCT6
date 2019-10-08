#include "button.h"
#include "key.h"
#include "remote.h"

#define BUTTON_LIST_LEN 9

Button_t button_list[BUTTON_LIST_LEN];
Button_t *r_up;
Button_t *r_down;
Button_t *r_left;
Button_t *r_right;
Button_t *r_confirm;
Button_t *r_return;
Button_t *k_wakeup;
Button_t *k_key0;
Button_t *k_key1;

uint32_t button_scan_interval = 10; // ms

void button_init() {
  KEY_Init();
  Remote_Init();

  // init buttons
  r_up = &button_list[0];
  r_down = &button_list[1];
  r_left = &button_list[2];
  r_right = &button_list[3];
  r_confirm = &button_list[4];
  r_return = &button_list[5];
  k_wakeup = &button_list[6];
  k_key0 = &button_list[7];
  k_key1 = &button_list[8];
  for(uint8_t i=0; i<BUTTON_LIST_LEN; i++){
    button_list[i] = (Button_t){0,0,0,0};
  }
}

void button_task() {
  for(uint8_t i=0; i<BUTTON_LIST_LEN; i++){
    button_list[i].last_status = button_list[i].status;
    button_list[i].status = 0;
  }

  // scan remote key
  uint8_t key = Remote_Scan();
  if(key){
		switch(key){
			case 0://str="ERROR";
        break;
			case 162://str="POWER";
        break;
			case 98://str="UP";
        r_up->status=1;break;
			case 2://str="PLAY";
        r_confirm->status=1;break;
			case 226://str="ALIENTEK";
        r_return->status=1;break;
			case 194://str="RIGHT";
        r_right->status=1;break;
			case 34://str="LEFT";
        r_left->status=1;break;
			case 224://str="VOL-";
        break;
			case 168://str="DOWN";
        r_down->status=1;break;
			case 144://str="VOL+";
        break;
			case 104://str="1";
        break;
			case 152://str="2";
        break;
			case 176://str="3";
        break;
			case 48://str="4";
        break;
			case 24://str="5";
        break;
			case 122://str="6";
        break;
			case 16://str="7";
        break;
			case 56://str="8";
        break;
			case 90://str="9";
        break;
			case 66://str="0";
        break;
			case 82://str="DELETE";
        break;
		}
	}

  // scan normal key
  static uint8_t key0_last = 0;
  static uint8_t key1_last = 0;
  static uint8_t wakeup_last = 0;
  uint8_t key0_now = KEY0?0:1;
  uint8_t key1_now = KEY1?0:1;
  uint8_t wakeup_now = WK_UP;

  if(key0_now == key0_last){k_key0->status = key0_now;}
  else{k_key0->status = k_key0->last_status;}

  if(key1_now == key1_last){k_key1->status = key1_now;}
  else{k_key1->status = k_key1->last_status;}

  if(wakeup_now == wakeup_last){k_wakeup->status = wakeup_now;}
  else{k_wakeup->status = k_wakeup->last_status;}

  key0_last = key0_now;
  key1_last = key1_now;
  wakeup_last = wakeup_now;

  // execute function
  for(uint8_t i=0; i<BUTTON_LIST_LEN; i++){
    Button_t *b = button_list + i;
    if(b->status == 1 && b->last_status == 0){
      if(b->press_fun){b->press_fun();}
    }
    if(b->status == 0 && b->last_status == 1){
      if(b->release_fun){b->release_fun();}
    }
  }
}
