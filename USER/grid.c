#include "grid.h"
#include "tetromino.h"

cell_t grid[GRID_HEIGHT][GRID_WIDTH];

cell_t sub_grid[4][4];

u8 max_height = 0;

uint8_t grid_scan()
{
  s8 x, y;
  // u8 cnt = 0;
  u8 row_num = 0;
  // cell_t cell;
  //scan up->down
  for (y = GRID_HEIGHT; y >= 0; y--)
  {
    // cnt = 0;
    // for (x = 0; x < GRID_WIDTH; x++)
    // {
    //   cell = grid[y][x];
    //   if (!cell.isEmpty)
    //       cnt++;
    // }
    // if (cnt == 10)
    // {
    //     clear_row(y);
    //     row_num ++;
    // }
    for (x = 0; x < GRID_WIDTH; x++){
      if(grid[y][x].isEmpty) {break;}
      if(x == GRID_WIDTH-1){
        clear_row(y);
        row_num ++;
      }
    }
  }
  return row_num;
}

void clear_row(u8 line)
{
    u8 x, y;
    //shift down->up
    for (y = line; y < GRID_HEIGHT; y++)
    {
        for (x = 0; x < GRID_WIDTH; x++)
        {
            // cell = grid[y + 1][x];
            // grid[y][x].isEmpty = cell.isEmpty;
            // grid[y][x].color = cell.color;
            grid[y][x] = grid[y+1][x];
        }
    }
    // empty_row(max_height);
    // max_height--;
}

void empty_row(u8 line)
{
    u8 x;
    for (x = 0; x < 10; x++)
        grid[line][x].isEmpty = 1;
}

void grid_init()
{
    u8 x, y;
    //scan up->down
    for (y = 0; y < GRID_HEIGHT; y++)
        for (x = 0; x < GRID_WIDTH; x++)
            grid[y][x].isEmpty = 1;
}

void sub_grid_init()
{
    u8 x, y;
    for (y = 0; y < 4; y++)
        for (x = 0; x < 4; x++)
            sub_grid[y][x].isEmpty=1;
}
