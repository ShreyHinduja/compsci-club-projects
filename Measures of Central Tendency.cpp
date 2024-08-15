#include <iostream>
#include <algorithm>

using namespace std;

//------------------------integers--------------------------//
int dataSet[]{5, 1, 2, 4, 4, 4, 3, 3, 6, 8, 7};
int medianElementVar, rangeLowestValue, rangeHighestValue;;
int arraySize = sizeof(dataSet)/sizeof(dataSet[0]);
int i = 0;
int j = 0;
int modeofSet;
int counter = 1;
int maximum = 0;
//--------------------floats and doubles--------------------//
double range(int arraySize);
float rangeofSet, meanofSet, medianofSet, meanStoredNumbers, medianEvenNumber1, medianEvenNumber2;
//------------------------characters------------------------//
char chosenMCT;
//-------------------------booleans-------------------------//
bool run = 1;
//--------------------------strings-------------------------//
string continueCalculations;
//----------------------------------------------------------//

bool isItEven(int num){
  if (num%2 == 0){
    return true;
  }else{
    return false;
  }
}

int main()
{
  while(run){
  cout << "The data set used is: " << " {5, 1, 2, 4, 4, 4, 3, 3, 6, 8, 7} \n\n";
  cout << "Please select an MCT:\n a) mean\n b) median\n c) range\n d) mode\n\n";
  cin >> chosenMCT;
  switch(chosenMCT){
    //-----------------------------------------------------------//
    case 'a':
      sort(dataSet, dataSet + arraySize);
      cout << "\n";
      while (i < 9){
        meanStoredNumbers = dataSet[i] + meanStoredNumbers; i++;
      }
      meanofSet = meanStoredNumbers / arraySize;
      cout << "The mean of the data set is: " << meanofSet << endl << endl;
      break;
    //-----------------------------------------------------------//
    case 'b':
      sort(dataSet, dataSet + arraySize);
      if (isItEven(arraySize)){
        medianEvenNumber1 = dataSet[arraySize/2 - 1];
        medianEvenNumber2 = dataSet[arraySize/2];
        medianofSet = (medianEvenNumber1 + medianEvenNumber2)/2;
        cout << medianofSet << endl << endl;
      }else{
        medianElementVar = (arraySize/2);
        cout << "The median of the data set is: " << dataSet[medianElementVar] << endl;
      }
    break;
    //-----------------------------------------------------------//
    case 'c':
      sort(dataSet, dataSet + arraySize);
      rangeLowestValue = dataSet[0];
      rangeHighestValue = dataSet[arraySize];
      cout << "The range of the data set is: " << rangeHighestValue - rangeLowestValue;
      break;
    //-----------------------------------------------------------//
    case 'd':
    sort(dataSet, dataSet + arraySize);
    for (j = 0; j <= arraySize; j++){
    if (dataSet[j] == dataSet[j + 1]){
      counter++;
      if (counter > maximum){
        maximum = counter;
        modeofSet = dataSet[j];
      }
    }else{
      counter = 1;
    }
  }
  if (modeofSet == 0){
    cout << "\nThere is no mode.\n";
  }else{
    cout << "\nThe mode is: " << modeofSet << endl;
    }
    //-----------------------------------------------------------//
    default: cout << "Invalid option\n";
    break;
    //-----------------------------------------------------------//
  }
    cout << "Would you like to continue using this calculator? ( y/n )\n";
    cin >> continueCalculations;
    if (continueCalculations == "y"){
      run = 1;
    }else if (continueCalculations == "n"){
      run = 0;
    }else{
      cout << "Please select y or n.\n";
    }
  }
}
    //-----------------------------------------------------------//
