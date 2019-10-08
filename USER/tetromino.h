#ifndef TETROMINO_H
#define TETROMINO_H
#include "sys.h"

typedef struct{
    s8 x[4][4];
    s8 y[4][4];
	  u16 color;
} Image_t;

typedef struct{
    s8 x;
    s8 y;
    u8 shape;
    u8 rotation;
} Tetromino_t;


#define SHAPE_I 0
#define SHAPE_J 1
#define SHAPE_L 2
#define SHAPE_O 3
#define SHAPE_S 4
#define SHAPE_T 5
#define SHAPE_Z 6
#define SHAPE_NUM 7

extern Tetromino_t tetromino;
extern Tetromino_t tetromino_next;
extern Image_t tetimg_list[SHAPE_NUM];

u8 left_shift_check(void);
u8 right_shift_check(void);
u8 down_shift_check(void);
u8 rotation_check(void);
void flush_tetromino(void);
void tetromino_reset(void);
void tetromino_init(void);
#endif
