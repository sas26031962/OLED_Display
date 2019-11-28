/*********************************************************************
Структура для эмуляции на экране изображения стрелочного прибора, 
отображающего текущее значение сигнала 
*********************************************************************/
#ifndef S_DEVICE
#define S_DEVICE

extern OLED  myOLED;

struct sDevice{
  const int NEEDLE_BOTTOM_X = 64;
  const int NEEDLE_BOTTOM_Y = 63;
  const int NEEDLE_TOP_Y = 28;
  const int NEEDLE_TOP_X0 = 16;
  const int NEEDLE_TOP_X1 = 24;
  const int NEEDLE_TOP_X2 = 36;
  const int NEEDLE_TOP_X3 = 46;
  const int NEEDLE_TOP_X4 = 56;
  const int NEEDLE_TOP_X5 = 66;
  const int NEEDLE_TOP_X6 = 76;
  const int NEEDLE_TOP_X7 = 86;
  const int NEEDLE_TOP_X8 = 98;
  const int NEEDLE_TOP_X9 = 108;
  const int NEEDLE_TOP_X10 = 120;

  const int TOP_BORDER_Y = 14;
  const int CIRCLE_RADIUS = 10;

  const int OWERFLOW_MESSAGE_PADDING = 32;
  
  int Value;

  void drawMeterNeedle();
  void drawDeviceShield();
  
};

//
// Рисование стрелки на экране прибора
//
void sDevice::drawMeterNeedle()
{
   switch(this->Value)
   {
    case 0:
    myOLED.drawLine(
      this->NEEDLE_TOP_X0, 
      this->NEEDLE_TOP_Y, 
      this->NEEDLE_BOTTOM_X, 
      this->NEEDLE_BOTTOM_Y
      );
    break;

    case 1:
    myOLED.drawLine(
      this->NEEDLE_TOP_X1, 
      this->NEEDLE_TOP_Y, 
      this->NEEDLE_BOTTOM_X, 
      this->NEEDLE_BOTTOM_Y
      );
    break;

    case 2:
    myOLED.drawLine(
      this->NEEDLE_TOP_X2, 
      this->NEEDLE_TOP_Y, 
      this->NEEDLE_BOTTOM_X, 
      this->NEEDLE_BOTTOM_Y
      );
    break;

    case 3:
    myOLED.drawLine(
      this->NEEDLE_TOP_X3, 
      this->NEEDLE_TOP_Y, 
      this->NEEDLE_BOTTOM_X, 
      this->NEEDLE_BOTTOM_Y
      );
    break;

    case 4:
    myOLED.drawLine(
      this->NEEDLE_TOP_X4, 
      this->NEEDLE_TOP_Y, 
      this->NEEDLE_BOTTOM_X, 
      this->NEEDLE_BOTTOM_Y
      );
    break;

    case 5:
    myOLED.drawLine(
      this->NEEDLE_TOP_X5, 
      this->NEEDLE_TOP_Y, 
      this->NEEDLE_BOTTOM_X, 
      this->NEEDLE_BOTTOM_Y
      );
    break;

    case 6:
    myOLED.drawLine(
      this->NEEDLE_TOP_X6, 
      this->NEEDLE_TOP_Y, 
      this->NEEDLE_BOTTOM_X, 
      this->NEEDLE_BOTTOM_Y
      );
    break;

    case 7:
    myOLED.drawLine(
      this->NEEDLE_TOP_X7, 
      this->NEEDLE_TOP_Y, 
      this->NEEDLE_BOTTOM_X, 
      this->NEEDLE_BOTTOM_Y
      );
    break;

    case 8:
    myOLED.drawLine(
      this->NEEDLE_TOP_X8, 
      this->NEEDLE_TOP_Y, 
      this->NEEDLE_BOTTOM_X, 
      this->NEEDLE_BOTTOM_Y
      );
    break;

    case 9:
    myOLED.drawLine(
      this->NEEDLE_TOP_X9, 
      this->NEEDLE_TOP_Y, 
      this->NEEDLE_BOTTOM_X, 
      this->NEEDLE_BOTTOM_Y
      );
    break;

    case 10:
    myOLED.drawLine(
      this->NEEDLE_TOP_X10, 
      this->NEEDLE_TOP_Y, 
      this->NEEDLE_BOTTOM_X, 
      this->NEEDLE_BOTTOM_Y
      );
    break;

    default:
    myOLED.print("OWERFLOW", CENTER, this->OWERFLOW_MESSAGE_PADDING);
    break;
   }
   
}//End of void drawMeterNeedle()

void sDevice::drawDeviceShield()
{
    myOLED.clrScr();

    String S1 = "Value=";
    S1 = S1 + String(this->Value);
    String S2 = "0_1_2_3_4_5_6_7_8_9_";
    myOLED.print(S1, CENTER, 0);
    myOLED.print(S2, CENTER, 16);

   //Рисование круга у основания стрелки
   myOLED.drawCircle(this->NEEDLE_BOTTOM_X, this->NEEDLE_BOTTOM_Y, this->CIRCLE_RADIUS);

   //Рисование двух половин нижней границы изображения прибора
   myOLED.drawLine(0, this->NEEDLE_BOTTOM_Y, Screen.WIDTH/2 - this->CIRCLE_RADIUS, this->NEEDLE_BOTTOM_Y);
   myOLED.drawLine(Screen.WIDTH/2 + this->CIRCLE_RADIUS, this->NEEDLE_BOTTOM_Y, Screen.WIDTH, this->NEEDLE_BOTTOM_Y);
   
   //Рисование левой и правой границ изображения прибора
   myOLED.drawLine(0, this->NEEDLE_BOTTOM_Y, 0, this->TOP_BORDER_Y - 1);
   myOLED.drawLine(Screen.WIDTH - 1, this->NEEDLE_BOTTOM_Y, Screen.WIDTH - 1, this->TOP_BORDER_Y);

   //Рисование нижней границы изображения прибора
   myOLED.drawLine(0, this->TOP_BORDER_Y - 1, Screen.WIDTH - 1, this->TOP_BORDER_Y - 1);

   //Рисование стрелки прибора 
   this->drawMeterNeedle();
    
    myOLED.update();
  
}//End of void sDevice::drawDeviceShield()


#endif
