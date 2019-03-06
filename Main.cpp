#include"Life.h"
#include<iostream>
#include<unistd.h> //gets me sleep()

using namespace std;

int main()
{

  int answer1;
  string fileName;
  string line;
  string s;
  int h,w, h2, w2;
  double ip, ip2;
  int modeChoice;
  int loopChoice;
  int numLines=0;

  cout << "Game of Life Simulator" << endl;
  cout << endl;
  cout << "Simulation options: " << endl;
  cout << "  1) Use your own Map File from text file" << endl;
  cout << "  2) Random Assignment" << endl;
  cin >> answer1;

  if (answer1 == 1)
  {
    Grid grid2;
    grid2.createGridFromFile();
    //cout << grid2.getHeight() << endl;
    //cout << grid2.getWidth() << endl;

    cout << endl;
    cout << "Mode options: " << endl;
    cout << "  1) Classic" << endl;
    cout << "  2) Doughnut" << endl;
    cout << "  3) Mirror" << endl;
    cin >> modeChoice;
    cout << endl;

    cout << "Looping options: " << endl;
    cout << "  1) Brief Pauses" << endl;
    cout << "  2) User Contolled" << endl;
    cout << "  3) Output a File" << endl;
    cin >> loopChoice;
    cout << endl;

    switch (loopChoice){
      case 1: {
        // Brief Pauses
        cout << "Pauses of 1 seconds will occur between generations." << endl;
        int gen=0;
        int qP=0;
        while(qP!=1){
          switch (modeChoice) {
            case 1:
                cout << "Generation #" << gen+2 << endl;
                cout << endl;
                qP=grid2.classicMode();
                sleep(1);
                gen++;
              break;
            case 2:
                cout << "Generation #" << gen+2 << endl;
                cout << endl;
                qP=grid2.doughnutMode();
                sleep(1);
                gen++;
              break;
            case 3:
                cout << "Generation #" << gen+2 << endl;
                cout << endl;
                qP=grid2.mirrorMode();
                sleep(1);
                gen++;
              break;
          }
        }
        break;
      }
      case 2: {
        // User Contolled
        cout << "Press ENTER to continue." << endl;
        cin.get();
        int gen=0;
        char blah;
        int qP=0;
        while(qP!=1){
          switch (modeChoice) {
            case 1:
                cout << "Generation #" << gen+2 << endl;
                cout << endl;
                qP=grid2.classicMode();
                cin.get(blah);
                gen++;
              break;
            case 2:
                cout << "Generation #" << gen+2 << endl;
                cout << endl;
                qP=grid2.doughnutMode();
                cin.get(blah);
                gen++;
              break;
            case 3:
                cout << "Generation #" << gen+2 << endl;
                cout << endl;
                qP=grid2.mirrorMode();
                cin.get(blah);
                gen++;
              break;
          }
        }
        break;
      }
      case 3: {
        cout << "Writing Results to output file: Life.out" << endl;
        ofstream file_;
        file_.open("Life.out", std::ios_base::app);
        file_ << "Height: " << grid2.getHeight() << endl;
        file_ << "Width: " << grid2.getWidth() << endl;
        file_ << "Population Density: " << grid2.getInitPop() << endl;
        file_ << "Mode: ";
        if (modeChoice ==1){
          file_ << "Classic" << endl;
        }
        if (modeChoice==2){
          file_ << "Doughnut" << endl;
        }
        if (modeChoice==3){
          file_ << "Mirror" << endl;
        }
        file_ << endl;
        file_ << "Generation #1" << endl;
        file_ << endl;
        grid2.outFile();
        file_ << endl;
        int gen=0;
        int qP=0;
        while(qP!=1){
          switch (modeChoice) {
            case 1:
                cout << "Generation #" << gen+2 << endl;
                cout << endl;
                file_ << "Generation #" << gen+2 << endl;
                file_ << endl;
                qP=grid2.classicMode();
                grid2.outFile();
                file_ << endl;
                gen++;
              break;
            case 2:
                cout << "Generation #" << gen+2 << endl;
                cout << endl;
                file_ << "Generation #" << gen+2 << endl;
                file_ << endl;
                qP=grid2.doughnutMode();
                grid2.outFile();
                file_ << endl;
                gen++;
              break;
            case 3:
                cout << "Generation #" << gen+2 << endl;
                cout << endl;
                file_ << "Generation #" << gen+2 << endl;
                file_ << endl;
                qP=grid2.mirrorMode();
                grid2.outFile();
                file_ << endl;
                gen++;
              break;
          }
        }
        cout << "Results appended to 'Life.out'. " << endl;
        file_.close();
        break;
      }
    }

  }
  if (answer1 == 2)
  {
    cout << "Enter the HEIGHT of the world:  ";
    cin >> h;

    cout << "Enter the WIDTH of the world:  ";
    cin >> w;

    cout << "Enter Population Density (Between 0 and 1):  ";
    cin >> ip;

    Grid grid1;
    grid1.setHeight(h);
    grid1.setWidth(w);
    grid1.setInitPop(ip);

    cout << endl;
    cout << "Mode options: " << endl;
    cout << "  1) Classic" << endl;
    cout << "  2) Doughnut" << endl;
    cout << "  3) Mirror" << endl;
    cin >> modeChoice;
    cout << endl;

    cout << "Looping options: " << endl;
    cout << "  1) Brief Pauses" << endl;
    cout << "  2) User Contolled" << endl;
    cout << "  3) Output a File" << endl;
    cin >> loopChoice;
    cout << endl;

    grid1.createGrid();

    switch (loopChoice){
      case 1: {
        // Brief Pauses
        cout << "Pauses of 1 seconds will occur between generations." << endl;
        int gen=0;
        int qP=0;
        while(qP!=1){
          switch (modeChoice) {
            case 1:
                cout << "Generation #" << gen+2 << endl;
                cout << endl;
                qP=grid1.classicMode();
                sleep(1);
                gen++;
              break;
            case 2:
                cout << "Generation #" << gen+2 << endl;
                cout << endl;
                qP=grid1.doughnutMode();
                sleep(1);
                gen++;
              break;
            case 3:
                cout << "Generation #" << gen+2 << endl;
                cout << endl;
                qP=grid1.mirrorMode();
                sleep(1);
                gen++;
              break;
          }
        }
        break;
      }
      case 2: {
        // User Contolled
        cout << "Press ENTER to continue." << endl;
        cin.get();
        int gen=0;
        char blah;
        int qP=0;
        while(qP!=1){
          switch (modeChoice) {
            case 1:
                cout << "Generation #" << gen+2 << endl;
                cout << endl;
                qP=grid1.classicMode();
                cin.get(blah);
                gen++;
              break;
            case 2:
                cout << "Generation #" << gen+2 << endl;
                cout << endl;
                qP=grid1.doughnutMode();
                cin.get(blah);
                gen++;
              break;
            case 3:
                cout << "Generation #" << gen+2 << endl;
                cout << endl;
                qP=grid1.mirrorMode();
                cin.get(blah);
                gen++;
              break;
          }
        }
        break;
      }
      case 3: {
        cout << "Writing Results to output file: Life.out" << endl;
        ofstream file_;
        file_.open("Life.out", std::ios_base::app);
        file_ << "Height: " << h << endl;
        file_ << "Width: " << w << endl;
        file_ << "Population Density: " << ip << endl;
        file_ << "Mode: ";
        if (modeChoice ==1){
          file_ << "Classic" << endl;
        }
        if (modeChoice==2){
          file_ << "Doughnut" << endl;
        }
        if (modeChoice==3){
          file_ << "Mirror" << endl;
        }
        file_ << endl;
        file_ << "Generation #1" << endl;
        file_ << endl;
        grid1.outFile();
        file_ << endl;
        int gen=0;
        int qP=0;
        while(qP!=1){
          switch (modeChoice) {
            case 1:
                cout << "Generation #" << gen+2 << endl;
                cout << endl;
                file_ << "Generation #" << gen+2 << endl;
                file_ << endl;
                qP=grid1.classicMode();
                grid1.outFile();
                file_ << endl;
                gen++;
              break;
            case 2:
                cout << "Generation #" << gen+2 << endl;
                cout << endl;
                file_ << "Generation #" << gen+2 << endl;
                file_ << endl;
                qP=grid1.doughnutMode();
                grid1.outFile();
                file_ << endl;
                gen++;
              break;
            case 3:
                cout << "Generation #" << gen+2 << endl;
                cout << endl;
                file_ << "Generation #" << gen+2 << endl;
                file_ << endl;
                qP=grid1.mirrorMode();
                grid1.outFile();
                file_ << endl;
                gen++;
              break;
          }
        }
        cout << "Results appended to 'Life.out'. " << endl;
        file_.close();
        break;
      }
    }
  }
}
