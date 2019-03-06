#include"Life.h"
#include<iostream>

using namespace std;

Grid::Grid(){
  height = 7;
  width = 5;
  initPop = .98;
}

void Grid::setHeight(int h) {
  height = h;
}

int Grid::getHeight() {
  return height;
}

void Grid::setWidth(int w) {
  width = w;
}

int Grid::getWidth() {
  return width;
}

void Grid::setInitPop(double ip) {
  initPop = ip;
}

double Grid::getInitPop() {
  return initPop;
}

void Grid::createGrid() {
  cout << "Generation #1" << endl;
  cout << endl;
  for (int i=0; i<height; i++) {
    //
    for (int j=0; j<width; j++) {
      int r = (rand() % 100) + 1;
      if (r <= (initPop*100)) {
        gridLayout[i][j] = 'X';
      }
      else if (r > (initPop*100)) {
        gridLayout[i][j] = '-';
      }
      else {
        cout << "Not Valid" << endl;
      }
      cout << gridLayout[i][j] << " ";
    }
    cout << endl;
  }
}

int Grid::classicMode() {
  for (int i=0; i<height; i++){
    for (int j=0; j<width; j++)
    {
      if (gridLayout[i+1][j] == 'X') {
        neighbors++;
      }
      if (gridLayout[i-1][j] == 'X') {
        neighbors++;
      }
      if (gridLayout[i][j-1] == 'X') {
        neighbors++;
      }
      if (gridLayout[i][j+1] == 'X') {
        neighbors++;
      }
      if (gridLayout[i+1][j+1] == 'X') {
        neighbors++;
      }
      if (gridLayout[i+1][j-1] == 'X') {
        neighbors++;
      }
      if (gridLayout[i-1][j+1] == 'X') {
        neighbors++;
      }
      if (gridLayout[i-1][j-1] == 'X') {
        neighbors++;
      }

      nArray[i][j] = neighbors;
      neighbors = 0;
    }
  }
  for (int k=0; k<height; k++) {
    for (int b=0; b<width; b++) {
      switch (nArray[k][b]){
        case 0:
        case 1:
          updatedGridLayout[k][b] = '-';
          deaths++;
          break;
        case 2:
          updatedGridLayout[k][b] = gridLayout[k][b];
          break;
        case 3:
          updatedGridLayout[k][b] = 'X';
          if (updatedGridLayout[k][b] != gridLayout[k][b])
            births++;
          break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
          updatedGridLayout[k][b] = '-';
          deaths++;
          break;
      }
      cout << updatedGridLayout[k][b] << " ";
    }
    cout << endl;
  }
//  cout << "Births:  " << births << endl;
//  cout << "Deaths:  " << deaths << endl;
  cout << endl;
  stopGen();

  for (int y=0; y<height; y++) {
    for (int z=0; z<width; z++) {
      gridLayout[y][z] = updatedGridLayout[y][z];
    }
  }
  return quitProg;
}

int Grid::doughnutMode() {
  for (int i=0; i<height; i++){
    for (int j=0; j<width; j++)
    {
      if (gridLayout[i+1][j] == 'X') {
        neighbors++;
      }
      if (gridLayout[i-1][j] == 'X') {
        neighbors++;
      }
      if (gridLayout[i][j-1] == 'X') {
        neighbors++;
      }
      if (gridLayout[i][j+1] == 'X') {
        neighbors++;
      }
      if (gridLayout[i+1][j+1] == 'X') {
        neighbors++;
      }
      if (gridLayout[i+1][j-1] == 'X') {
        neighbors++;
      }
      if (gridLayout[i-1][j+1] == 'X') {
        neighbors++;
      }
      if (gridLayout[i-1][j-1] == 'X') {
        neighbors++;
      }

      if (i==0) {
        if (gridLayout[height-1][j] == 'X') { //horizontal reflection from left
          neighbors++;
        }
        if (gridLayout[height-1][j+1] == 'X') {
          neighbors++;
        }
        if (gridLayout[height-1][j-1] == 'X') {
          neighbors++;
        }
      }
      if (i==height-1) {
        if (gridLayout[0][j] == 'X') { //horizontal reflection from right
          neighbors++;
        }
        if (gridLayout[0][j+1] == 'X') {
          neighbors++;
        }
        if (gridLayout[0][j-1] == 'X') {
          neighbors++;
        }
      }
      if (j==0) {
        if (gridLayout[i][width-1] == 'X') { //vertical reflection from top
          neighbors++;
        }
        if (gridLayout[i+1][width-1] == 'X') {
          neighbors++;
        }
        if (gridLayout[i-1][width-1] == 'X') {
          neighbors++;
        }
      }
      if (j==width-1) {
        if (gridLayout[i][0] == 'X') { //vertical reflection from bottom
          neighbors++;
        }
        if (gridLayout[i+1][0] == 'X') {
          neighbors++;
        }
        if (gridLayout[i-1][0] == 'X') {
          neighbors++;
        }
      }

      nArray[i][j] = neighbors;
      neighbors = 0;
    }
  }

  for (int k=0; k<height; k++) {
    for (int b=0; b<width; b++) {
      switch (nArray[k][b]){
        case 0:
        case 1:
          updatedGridLayout[k][b] = '-';
          deaths++;
          break;
        case 2:
          updatedGridLayout[k][b] = gridLayout[k][b];
          break;
        case 3:
          updatedGridLayout[k][b] = 'X';
          if (updatedGridLayout[k][b] != gridLayout[k][b])
            births++;
          break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
          updatedGridLayout[k][b] = '-';
          deaths++;
          break;
      }
      cout << updatedGridLayout[k][b] << " ";
    }
    cout << endl;
  }
//  cout << "Births:  " << births << endl;
//  cout << "Deaths:  " << deaths << endl;
  cout << endl;
  stopGen();

  for (int y=0; y<height; y++) {
    for (int z=0; z<width; z++) {
      gridLayout[y][z] = updatedGridLayout[y][z];
    }
  }
  return quitProg;
}

int Grid::mirrorMode() {
  for (int i=0; i<height; i++){
    for (int j=0; j<width; j++)
    {
      if (gridLayout[i+1][j] == 'X') {
        neighbors++;
      }
      if (gridLayout[i-1][j] == 'X') {
        neighbors++;
      }
      if (gridLayout[i][j-1] == 'X') {
        neighbors++;
      }
      if (gridLayout[i][j+1] == 'X') {
        neighbors++;
      }
      if (gridLayout[i+1][j+1] == 'X') {
        neighbors++;
      }
      if (gridLayout[i+1][j-1] == 'X') {
        neighbors++;
      }
      if (gridLayout[i-1][j+1] == 'X') {
        neighbors++;
      }
      if (gridLayout[i-1][j-1] == 'X') {
        neighbors++;
      }
      if (i==0) { // top wall
        if (gridLayout[i][j] == 'X') { //self relection OR diagonal relection if corner
          neighbors++;
        }
        if (j==0) { //top left corner
          if (gridLayout[i][j] == 'X') {
            neighbors++;
          }
        }
        else if (j==(width-1)) { //top right corner
          if (gridLayout[i][j] == 'X') {
            neighbors++;
          }
        }
        else { //not a corner
          if (gridLayout[i][j-1] == 'X') { //left neighbor's reflection
            neighbors++;
          }
          if (gridLayout[i][j+1] == 'X') {//right neighbor's reflection
            neighbors++;
          }
        }
      }
      if (i==(height-1)) {
        if (gridLayout[i][j] == 'X') { //self relection OR diagonal relection if corner
          neighbors++;
        }
        if (j==0) { //bottom left corner
          if (gridLayout[i][j] == 'X') {
            neighbors++;
          }
        }
        else if (j==(width-1)) { //bottom right corner
          if (gridLayout[i][j] == 'X') {
            neighbors++;
          }
        }
        else { //not a corner
          if (gridLayout[i][j-1] == 'X') { //left neighbor's reflection
            neighbors++;
          }
          if (gridLayout[i][j+1] == 'X') {//right neighbor's reflection
            neighbors++;
          }
        }
      }
      if(j==0){
        if (gridLayout[i][j] == 'X') { //self relection OR diagonal relection if corner
          neighbors++;
        }
        if (i==0) { //top left corner
          if (gridLayout[i][j] == 'X') {
            neighbors++;
          }
        }
        else if (i==(height-1)) { //bottom left corner
          if (gridLayout[i][j] == 'X') {
            neighbors++;
          }
        }
        else { //not a corner
          if (gridLayout[i-1][j] == 'X') { //top neighbor's reflection
            neighbors++;
          }
          if (gridLayout[i+1][j] == 'X') {//bototm neighbor's reflection
            neighbors++;
          }
        }
      }
      if(j==(width-1)){
        if (gridLayout[i][j] == 'X') { //self relection OR diagonal relection if corner
          neighbors++;
        }
        if (i==0) { //top right corner
          if (gridLayout[i][j] == 'X') {
            neighbors++;
          }
        }
        else if (i==(height-1)) { //bottom right corner
          if (gridLayout[i][j] == 'X') {
            neighbors++;
          }
        }
        else { //not a corner
          if (gridLayout[i-1][j] == 'X') { //top neighbor's reflection
            neighbors++;
          }
          if (gridLayout[i+1][j] == 'X') {//bototm neighbor's reflection
            neighbors++;
          }
        }
      }
      nArray[i][j] = neighbors;
      neighbors = 0;
    }
  }

  for (int k=0; k<height; k++) {
    for (int b=0; b<width; b++) {
      switch (nArray[k][b]){
        case 0:
        case 1:
          updatedGridLayout[k][b] = '-';
          deaths++;
          break;
        case 2:
          updatedGridLayout[k][b] = gridLayout[k][b];
          break;
        case 3:
          updatedGridLayout[k][b] = 'X';
          if (updatedGridLayout[k][b] != gridLayout[k][b])
            births++;
          break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
          updatedGridLayout[k][b] = '-';
          deaths++;
          break;
      }
      cout << updatedGridLayout[k][b] << " ";
    }
    cout << endl;
  }
//  cout << "Births:  " << births << endl;
//  cout << "Deaths:  " << deaths << endl;
  cout << endl;
  stopGen();

  for (int y=0; y<height; y++) {
    for (int z=0; z<width; z++) {
      gridLayout[y][z] = updatedGridLayout[y][z];
    }
  }
  return quitProg;
}

int Grid::stopGen(){
  int t1=0;
  int t2 = height * width;
  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      if (gridLayout[i][j] == updatedGridLayout[i][j]) {
        t1++;
      }
    }
  }
  if (t1==t2) {
    cout << "World is empty or stable!" << endl;
    cout << "Press ENTER to quit program." << endl;
    quitProg=1;
  }
  return quitProg;
}

void Grid::outFile() {
  ofstream file_;
  file_.open("Life.out", std::ios_base::app);
  for (int i=0; i<height; i++) {
    for (int j=0; j<width; j++) {
      file_ << gridLayout[i][j] << " ";
    }
    file_ << endl;
  }
}

void Grid::createGridFromFile() {
  string fileName;
  string line;
  int charCount=0;
  int numLines=0;
  cout << "Enter the name of your file: ";
  cin >> fileName;
  cout << endl;
  ifstream myfile (fileName);
  if (myfile.is_open()) {
    cout << "Reading file..." << endl;
    cout << endl;
    while (getline(myfile,line)) {
      cout << line << endl;
      for (char e : line) {
        if (numLines==0){
          int hi = e-'0';
          setHeight(hi);
        }
        else if (numLines==1) {
          int wi = e-'0';
          setWidth(wi);
        }
        else {
          gridLayout[numLines-2][charCount] = e;
        }
        charCount++;
      }
      charCount=0;
      numLines++;
    }
    myfile.close();
  }

  cout << endl;
  cout << "Generation #1" << endl;
  int hi = getHeight();
  int wi = getWidth();
  int counter=0;
  for (int i=0; i<hi; i++) {
    for (int j=0; j<wi; j++) {
      if(gridLayout[i][j] == 'X'){
        counter++;
      }
      cout << gridLayout[i][j] << " ";
    }
    cout << endl;
  }
  double ip2 = (counter * 100) / (hi*wi);
  ip2 = (ip2 / 100);
  //cout << "Counter:  " << counter << endl;
  //cout << "IP:  " << ip2 << endl;
  setInitPop(ip2);
}
