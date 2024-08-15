  #include <iostream>

using namespace std;

float num1, num2, answer;

char operation;

bool run = 1;

string continueCalculations;

int main()
{
  cout << "Hello user! Welcome to Shrey's 4 Function Calculator.\n";
  while(run){
  cout << "Please enter the first number you would like to calculate.\n";
  cin >> num1;
  cout << "Please enter the second number you would like to calculate.\n";
  cin >> num2;
  cout << "Please enter your operation.\n a) addition\n b) subtraction\n c) multiplication \n d) division\n\n";
  cin >> operation;
  switch(operation){
    case 'a':
      cout << num1 + num2 << endl;
      break;
    case 'b':
      cout << num1 - num2 << endl;
      break;
    case 'c':
      cout << num1 * num2 << endl;
      break;
    case 'd':
      if (num2 == 0){
      cout << "UNDEFINED" << endl;
      break;
      }else{
      cout << num1 / num2 << endl;
      break;
      }
    default: cout << "I do not recognize this character." << endl;
    }
    cout << "Would you like to continue using this calculator? ( y/n )\n";
    cin >> continueCalculations;
    if (continueCalculations == "y"){
      run = 1;
    }else if (continueCalculations == "n"){
      run = 0;
      break;
    }else{
    cout << "Please select y or n.\n";
    }
  }
}
  