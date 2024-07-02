// ADDGDB USB Dongle Development Board Sample Program
// 2024.06.25 V1.0 New Create by B.T.O
//
// 書込装置: AVRISP mk2 or Arduino IDE 1.8.19 (ATMEGA32U4)

#include <MsTimer2.h>
#include <Mouse.h>
const int interval = 5000;    // 動作間隔
const int dulation = 100;     // 移動時間
const int movement = 50;      // 移動量

volatile bool moving = false; // マウスが移

void moseMove() {
  int timems;
  if (moving) {
    Mouse.move(movement, 0, 0);
    timems = interval;
  } else {
    Mouse.move(-movement, 0, 0);
    timems = dulation;
  }
  MsTimer2::set(timems, moseMove);
  MsTimer2::start();
  moving = !moving;
}

// Arduino Setup
void setup()
{
  Mouse.begin();

  MsTimer2::set(100, moseMove);
  MsTimer2::start();
}

// Arduino Main Loop
void loop() 
{

}