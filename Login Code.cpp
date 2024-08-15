#include <iostream>

using namespace std;

string correctUsername, correctPassword, enteredUsername, enteredPassword;

int tries = 3;

int main()
{
  cout << "What would you like your username to be?\n";
  cin >> correctUsername;
  cout << "What would you like your password to be?\n";
  cin >> correctPassword;
  while(tries){
    cout << "What is your username?\n";
    cin >> enteredUsername;
    if (correctUsername == enteredUsername){
      cout << "What is your password?\n";
      cin >> enteredPassword;
      if (correctPassword == enteredPassword){
      cout << "You have logged in!\n";
        break;
        }else{
       cout << "INCORRECT\n";
       tries--;
       cout << "You have " << tries << " try(s) remaining." << endl << endl;
        }
    }else{
       cout << "INCORRECT\n";
       tries--;
       cout << "You have " << tries << " try(s) remaining." << endl << endl;
    }
  }
}