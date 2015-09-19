#include <iostream>
#include <cstdlib>
#include <string>
#include "bigInt.h"
using namespace std;

ostream& operator << (ostream& os, bigInt& bgInt){
  os << bgInt.bigIntToLong() << endl;
}

istream& operator >> (istream& is, bigInt& bgInt){
  long num;//a temp number to hold the input value
  is >> num;
  bgInt.setNum(num);//actually sets this input to the object bitset for it to store
}

void displayMenu(int& choice){
  cout << "Pick the number of the operation you want to do:" << endl;
  cout << "1. Addition" << endl;
  cout << "2. Subtraction" << endl;
  cout << "3. Multiplication" << endl;
  cout << "4. Division" << endl;
  cout << "5. Exit Program" << endl;
  cin >> choice;
  return;
}

void receiveInput(bigInt& number1, bigInt& number2){
  cout << "Please enter in an integer value: ";
  cin >> number1;
  cout << "Please enter in another integer value: ";
  cin >> number2;
}


int main(){
  
  int choice = 0;
  bigInt number1;
  bigInt number2;
  
  while(choice != 5){
    displayMenu(choice);
    switch(choice){
      case 1:
       {
        receiveInput(number1, number2);
        cout << "\nThe addition of these two numbers is: ";
        bigInt sum = number1 + number2;
        cout << sum << endl;
        break;
       }
      case 2:
      {
        receiveInput(number1, number2);
        cout <<"\nThe  difference of these two numbers is: ";
        bigInt difference = number1 - number2;
        cout << difference << endl;
      }
        break;
      case 3:
      {
        receiveInput(number1, number2);
        cout <<"\nThe  product of these two numbers is: ";
        bigInt product = number1 * number2;
        cout << product << endl;  
        
      }
    
        break;
      case 4:
    
        break;
      case 5:
      
        break;
      default:
        cout << "That's not a valid choice, please choose again!" << endl;
        break;
    }
    
  }
  

  return 0;
}
