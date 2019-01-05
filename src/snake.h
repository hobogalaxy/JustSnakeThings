#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "winsys.h"
#include "cpoint.h"
#include <list>


class CSnake:public CFramedWindow
{
  CPoint UP = CPoint(0,-1);
  CPoint DOWN = CPoint(0,1);
  CPoint LEFT = CPoint(-1,0);
  CPoint RIGHT = CPoint(1,0);

  list<CPoint> body;  //  list of snake segments positions relative to CSnake window
  CPoint starting_point = CPoint(4,1);
  CPoint head_direction = RIGHT;
  CPoint fruit;
  bool paused = false;
  bool help = true;
  int update_delay = 120000;  // snake position wil be updated each 120000 microseconds

public:
  CSnake(CRect r, char _c = ' ');
  void paint();
  void paintSnake();
  void paintFruit();
  void paintHelp();
  void moveSnakeByOne();

  void runS();
  bool handleEvent(int key);

  void restart();
  bool checkForFood();
  void grow();
  void generateFood();
  bool find(CPoint point);  //supplemental function for generateFood()



};

#endif
