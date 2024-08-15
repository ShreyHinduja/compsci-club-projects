#include <iostream>
#include <algorithm>

using namespace std;

int dataSet[]{1,3,3,2,2,4};

//   THE DATASET WHEN SORTED IS (1,2,2,3,3,4)   //

int mode;

int counter = 1;

int maximum = 0;

int arraySize = sizeof(dataSet)/sizeof(dataSet[0]);

int i = 0;

int main(){
  sort(dataSet, dataSet + arraySize);
  for (i = 0; i <= arraySize; i++){
    if (dataSet[i] == dataSet[i + 1]){
      counter++;
      if (counter > maximum){
        maximum = counter;
        mode = dataSet[i];
      }
    }else{
      counter = 1;
    }
  }
  if (mode == 0){
    cout << "\nThere is no mode.\n";
  }else{
    cout << "\nThe mode is: " << mode << endl;
  }
}