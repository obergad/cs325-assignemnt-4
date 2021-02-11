//Author: Adam Oberg
//Date: 1/29/2021
//Description: Program for cs325 assignment 4
/*
You may use any language you choose to implement the activity selection
  last-to-start algorithm described in problem 3. If you use a sorting function
  in your program you will need to write that yourself. You can use any of the
  sorting algorithms from previous homework assignments or implement another
  sorting algorithm. Include the time to sort in your overall running time.

In Canvas, submit a verbal description of your algorithm, pseudocode and
  analysis of the theoretical running time.

You do not need to collected experimental running times.

The program should read input from a file named “act.txt”. The file contains
  lists of activity sets with number of activities in the set in the first line
  followed by lines containing the activity number, start time & finish time.
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

void insert_sort(){
  int i, j, n;
  Activity key;
  n = actVector.size();
    for (i = 1 ; i < n; i++) { //start at 1 not 0
      // std::cout << "begining of for loop" << '\n';
      key = actVector[i]; //set key
      j = i - 1; // set key - 1
      /*moving elements of v that are greater than the key
      to one pos ahead of their current pos*/
      while (j >= 0 && actVector[j].timeStart > key.timeStart) {
        // std::cout << "begining of while loop" << '\n';
        actVector[j + 1] = actVector[j];
        j = j - 1;
      //end while loop
      }
      actVector[j + 1] = key;
  //end for loop
  }

  std::reverse(actVector.begin(), actVector.end());
  // std::cout <<'\n' <<"vector afterSort: \n";
  // for (size_t i = 0; i < actVector.size(); i++) {
  //   std::cout << actVector[i].index << " ";
  //   std::cout << actVector[i].timeStart << " ";
  //   std::cout << actVector[i].timeEnd << " " << '\n';
  // }
}

void print_output(int set){
  std::reverse(outVector.begin(), outVector.end());
  int outSize = outVector.size();
  std::cout << "\nSet " << set << std::endl;
  std::cout << "Number of Activities Selected =  " << outSize << std::endl;
  for (int i = 0; i < outSize; ++i){
    std::cout  << outVector[i] << " ";
  }
  std::cout << "\n";
}

// Greedy approach
void select_act(int num){
  // std::cout <<'\n' <<"vector select_act: \n";
  // for (size_t i = 0; i < actVector.size(); i++) {
  //   std::cout << actVector[i].index << " ";
  //   std::cout << actVector[i].timeStart << " ";
  //   std::cout << actVector[i].timeEnd << " " << '\n';
  // }
  int i = 0;
  outVector.clear();
  outVector.push_back(actVector[0].index);
  int temp = actVector[0].timeStart;
  for (int j = 1; j < num; j++ , i++){
    if (temp >= actVector[j].timeEnd){
      temp =  actVector[j].timeStart;
      outVector.push_back(actVector[j].index);
    }
  }
}

int main(){
  std::ifstream file("act.txt");
  if (file.is_open()){
    int numAct; // num  acitivities
    int set = 0;
    Activity temp;
    while (file >> numAct){
      actVector.clear();
      // std::cout <<"numAct: " << numAct << '\n';
      for (int i = 0; i < numAct; ++i){
        file >> temp.index;
        file >> temp.timeStart;
        file >> temp.timeEnd;
        // std::cout << temp.index << " ";
        // std::cout << temp.timeStart << " ";
        // std::cout << temp.timeEnd << " ";
        // std::cout << '\n';
        actVector.push_back(temp);
      }
      insert_sort();
      select_act(numAct);
      set++;
      print_output(set);
    }
    file.close();
    // std::cout << "\n ==closed file==" << '\n';
  } else {
    std::cout << "Unable to open file";
  }
  return 0;
}
