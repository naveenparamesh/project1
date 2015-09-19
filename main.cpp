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


int main(){
  bigInt number1;
  bigInt number2;
  cout << "Please enter in an integer value: ";
  cin >> number1;
  cout << "Please enter in another integer value: ";
  cin >> number2;
  cout << "The addition of these two numbers is: ";
  bigInt sum = number1 + number2;
  cout << sum;





  return 0;
}
