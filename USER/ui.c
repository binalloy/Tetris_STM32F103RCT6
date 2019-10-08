#include "lcd.h"
#include "sys.h"
#include "grid.h"
#include "ui.h"
#include "usart.h"
#include "tetromino.h"
#include "parameter.h"

void draw_bg()
{
    POINT_COLOR = BLACK;
    //main window
    LCD_DrawRectangle(9, 9, 161, 311);
    //sub window
    LCD_DrawRectangle(165, 10, 235, 80);
    LCD_ShowString(170, 85, 200, 16, 16, "Next");
    LCD_ShowString(170, 230, 200, 16, 16, "Score:");
    LCD_ShowString(170, 250, 200, 16, 16, "     0");
    // LCD_Fill(10,10,25,25,BLUE);
}

void update_bg()
{
    //main window
    update_main_bg();
    //sub window
    update_sub_bg();
}

void update_main_bg()
{
    LCD_Fill(10, 10, 160, 310, WHITE);
}

void update_sub_bg()
{
    LCD_Fill(170, 15, 230, 75, WHITE);
}

void draw_block(u8 x, u8 y, u16 color, u8 mode) //mode 0:main window 1:sub winodw
{
    u16 rx, ry;

    if (!mode)
    {
        rx = 10 + x * CELL_LENGTH;
        ry = 295 - y * CELL_LENGTH;
    }
    else
    {
        rx = 170 + x * CELL_LENGTH;
        ry = 60 - y * CELL_LENGTH;
    }
    POINT_COLOR = color;
    LCD_DrawRectangle(rx, ry, rx + 15, ry + 15);
    LCD_Fill(rx + 2, ry + 2, rx + 13, ry + 13, color);
}

void grid_render()
{
    s8 x, y;
    cell_t cell;
    for (y = GRID_HEIGHT-1; y >= 0; y--)
    {
        for (x = 0; x < GRID_WIDTH; x++)
        {
            cell = grid[y][x];
            if (cell.isEmpty){
              draw_block(x, y, WHITE, 0);
            } else {
              draw_block(x, y, cell.color, 0);
            }
        }
    }
}

void sub_grid_render()
{
    u8 x, y;
    cell_t cell;
    for (y = 0; y < 4; y++)
    {
        for (x = 0; x < 4; x++)
        {
            cell = sub_grid[y][x];
            if (cell.isEmpty)
                continue;

            draw_block(x, y, cell.color, 1);
        }
    }
}


void draw_tetromino(uint8_t clear)
{
  u8 i;
	Image_t* it = &tetimg_list[tetromino.shape];
  u16 color = it->color;
  if(clear){color = WHITE;}
	for(i=0;i<4;i++)
	{
	   draw_block(it->x[tetromino.rotation][i] + tetromino.x, it->y[tetromino.rotation][i] + tetromino.y, color, 0);
	}
}

void draw_next_tetromino(uint8_t clear)
{
	u8 i;
	Image_t* it = &tetimg_list[tetromino_next.shape];
  u16 color = it->color;
  if(clear){color = WHITE;}
  for(i=0;i<4;i++)
	{
	   draw_block(it->x[tetromino_next.rotation][i], it->y[tetromino_next.rotation][i], color, 1);
	}

}

void draw_name(char* name){
  LCD_ShowString(170, 210, 200, 16, 16, (u8*)name);
}

void update_score(u16 score)
{
    char str_score[5];
    if (score > 9999)
        score = 9999;
    sprintf(str_score, "%6d", score);
    printf("score:%d str:%s\n",score,str_score);
    POINT_COLOR = BLACK;
    LCD_ShowString(170, 250, 200, 16, 16, (u8*)str_score);
}

void draw_rank_list(){
  POINT_COLOR = BLACK;
  LCD_Clear(WHITE);
  LCD_ShowString(100, 20, 200, 16, 16, (u8*)"Rank");
  uint16_t x = 40, y = 50;
  char rank_str[20];
  for(uint8_t i=0; i<RANK_LIST_LEN; i++){
    sprintf(rank_str, "%-14s%6d", rank_list[i].name, rank_list[i].score);
    LCD_ShowString(x, y, 200, 16, 16, (u8*)rank_str);
    y += 20;
  }
}
