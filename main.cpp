//Author: Adam Oberg
//Date: 1/29/2021
//Description: Program for cs325 assignment 4
/*

*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <chrono>
#include <algorithm>

struct Activity {
  int index;
  int timeStart;
  int timeEnd;
};
std::vector <Activity> actVector;
std::vector <int> outVector;

bool compare(Activity activity1, Activity activity2){
  if (activity1.timeEnd < activity2.timeEnd)
    return true;
  return false;
}

void print_output(int set){
  int outSize = outVector.size();
  std::cout << "set num " << set << std::endl;
  std::cout << "Num act Selected= " << outSize << std::endl;
  std::cout << "Acts:";
  for (int i = 0; i < outSize; ++i)
  {
    std::cout << " " << outVector[i];
  }
  std::cout << std::endl;
}
// main algo
// Greedy approach
// Select the activity with least possible timeEnd at each step.
void select_act(int num){
  int i = 0;
  int sizeOut = 0;
  sizeOut++;
  sizeOut.resize(sizeOut);
  sizeOut[sizeOut - 1] = actVector[0].index;
  for (int j = 1; j < num; j++){
    if (actVector[j].timeStart >= actVector[i].timeEnd){
      outSize++;
      outVector.resize(outSize);
      outVector[outSize - 1] = actVector[j].index;
      i = j;
    }
  }
}


int main(){
  std::ifstream file;
  if (myFile.is_open()){
    int numAct = 0; // num  acitivities
    int set = 0;
    Activity temp;
    while (!myFile.eof()){
      actVector.clear();
      myFile >> numAct;
      for (int i = 0; i < numAct; ++i){
        myFile >> temp.index;
        myFile >> temp.timeStart;
        myFile >> temp.timeEnd;
        actVector.push_back(temp);
      }
      sort(actVector.begin(), actVector.end(), compare);
      select_act(numAct);
      set++;
      print_output(set);
    }
    myFile.close();
  } else {
    std::cout << "Unable to open file";
  }
  return 0;
}
