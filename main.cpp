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

std::vector<Activity> insert_sort(std::vector<Activity> v){
  int i, key, j, n;
  n = v.size();
    for (i = 1 ; i < n; i++) { //start at 1 not 0
      // std::cout << "begining of for loop" << '\n';
      key = v[i].timeEnd; //set key
      j = i - 1; // set key - 1
      /*moving elements of v that are greater than the key
      to one pos ahead of their current pos*/
      while (j >= 0 && v[j].timeEnd > key) {
        // std::cout << "begining of while loop" << '\n';
        v[j + 1].timeEnd = v[j].timeEnd;
        j = j - 1;
      //end while loop
      }
      v[j + 1].timeEnd = key;
  //end for loop
  }
  return v;
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
  int outSize = 0;
  outSize++;
  outVector.resize(outSize);
  outVector[outSize - 1] = actVector[0].index;
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
  if (file.is_open()){
    int numAct = 0; // num  acitivities
    int set = 0;
    Activity temp;
    while (!file.eof()){
      actVector.clear();
      file >> numAct;
      for (int i = 0; i < numAct; ++i){
        file >> temp.index;
        file >> temp.timeStart;
        file >> temp.timeEnd;
        actVector.push_back(temp);
      }
      insert_sort(actVector);
      select_act(numAct);
      set++;
      print_output(set);
    }
    file.close();
  } else {
    std::cout << "Unable to open file";
  }
  return 0;
}
