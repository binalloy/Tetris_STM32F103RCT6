#include "parameter.h"
#include "stmflash.h"

#define FLASH_SAVE_ADDR  0X08020000

Hiscore_t rank_list[RANK_LIST_LEN];

void save_rank_list() {
  STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)rank_list,sizeof(rank_list));
}

void read_rank_list() {
  STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)rank_list,sizeof(rank_list));
}

void add_rank(Hiscore_t hiscore){
  Hiscore_t tmp;
  for(uint8_t i=0; i<RANK_LIST_LEN; i++){
    if(hiscore.score >= rank_list[i].score){
      tmp = rank_list[i];
      rank_list[i] = hiscore;
      hiscore = tmp;
    }
  }
  save_rank_list();
}
