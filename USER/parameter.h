#ifndef PARAMETER_H
#define PARAMETER_H

#include "sys.h"

#define RANK_LIST_LEN 10

typedef struct{
  char name[10];
  uint16_t score;
}Hiscore_t;

extern Hiscore_t rank_list[RANK_LIST_LEN];

void save_rank_list(void);
void read_rank_list(void);
void add_rank(Hiscore_t hiscore);

#endif
