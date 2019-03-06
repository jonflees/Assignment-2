#ifndef LIFE_H
#define LIFE_H

#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cmath>


class Grid
{
public:
  int height;
  int width;
  double initPop;
  char gridLayout[10][10];
  int neighbors=0;
  int nArray[10][10];
  char updatedGridLayout[10][10];
  int modeChoice;
  int births=0;
  int deaths=0;
  int quitProg=0;
  int numLines=0;
  char char_array[10][10];
  char line_array[10];

  Grid();

  void setHeight(int h);

  int getHeight();

  void setWidth(int w);

  int getWidth();

  void setInitPop(double ip);

  double getInitPop();

  void createGrid();

  int classicMode();

  int doughnutMode();

  int mirrorMode();

  int stopGen();

  void outFile();

  void createGridFromFile();

};

#endif
