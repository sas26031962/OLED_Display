/*********************************************************************
Структура для управления OLED-дисплеем с набором констант 
для данного дисплея и переменными для позиционирования изображения 
на экране 
*********************************************************************/

#ifndef S_SCREEN
#define S_SCREEN

#include <OLED_I2C.h>

struct sScreen{
  const int WIDTH = 128;
  const int HEIGHT = 64;
  const int GRID = 10;
  const int LEFT_MARGIN_0 = 4;
  const int BOTTOM_MARGIN_0 = 3;

  int LeftMargin;
  
}Screen;

#endif
