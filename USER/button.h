#ifndef BUTTON_H
#define BUTTON_H

#include "sys.h"

typedef struct{
  uint8_t status;
  uint8_t last_status;
  void (*press_fun)(void);
  void (*release_fun)(void);
}Button_t;

extern Button_t *r_up;
extern Button_t *r_down;
extern Button_t *r_left;
extern Button_t *r_right;
extern Button_t *r_confirm;
extern Button_t *r_return;
extern Button_t *k_wakeup;
extern Button_t *k_key0;
extern Button_t *k_key1;

extern uint32_t button_scan_interval;

void button_init(void);
void button_task(void);

#endif
