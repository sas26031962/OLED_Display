/*********************************************************************
Структура для реализации следующих функций:
- измерения значения сигнала,
- масштабирования его значения для эмуляции на экране изображения стрелочного прибора, 
- выполнение данной эмуляции 
*********************************************************************/
#ifndef S_CONTROL
#define S_CONTROL

extern sDevice Device;

struct sControl{
  long MillisCurrent;
  long MillisPrevious;
  int Resistor;
  void exec(long dwell);
};

void sControl::exec(long dwell)
{
  this->MillisCurrent = millis();
  if(this->MillisCurrent - this->MillisPrevious > dwell)
  {
    this->MillisPrevious = this->MillisCurrent;
    // Чтение входного сигнала
    this->Resistor = (analogRead(A0) >> 4);
    // Масштабирование входного сигнала
    Device.Value = (int)(this->Resistor / 5);
    
    // Отображение значения входного сигнала с эмуляцией стрелочного прибора
    Device.drawDeviceShield();

  }  
}//End of void exec(long dwell)  

#endif
