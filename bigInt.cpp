#include <iostream>
#include <cstdlib>
#include <bitset>
#include <string>
#include "bigInt.h"
using namespace std;

bigInt::bigInt(long num) : number(num){

}

//see if you can reassign number to a bitset that's greater than 64 bits
void bigInt::setNum(long num){
  bitset<64> temp(num);
  number = temp;
}

void bigInt::twosComplement(bitset<64>& number){
  number.flip(); // flip all the bits in the bitset
  bigInt bi(1);
  *(this) = *(this) + bi;
  
}

long bigInt::bigIntToLong(){
  if(number[number.size() - 1] == 0){//check leftmost bit to see if positive number
    return number.to_ulong();
  }
  else {// its a negative number, thus perform two's complement and add negative sign on the end
    twosComplement(number);//change it to negative of original value
    long result_num = number.to_ulong();
    twosComplement(number);//change back to its original form
    return (-result_num);
  }
}

int bigInt::addBit(int bit1, int bit2, int& carry_in, int& carry_out){
  int result_bit;
  
  if(bit1 != 1 || bit2 != 1){
      result_bit = bit1 ^ bit2;
      if(carry_in == 1 && result_bit == 1){
        result_bit = 0;
        carry_in = 0;
        carry_out = 1;
      }
      else if(carry_in == 1 && result_bit == 0){
        result_bit = 1;
        carry_in = 0;
        carry_out = 0;
      }
      return result_bit;
  }
  else {
    if(carry_in == 1){
      result_bit = 1;
      carry_in = 0;
      carry_out = 1;
    }
    else {
      result_bit = 0;
      carry_in = 0;
      carry_out = 1;
    }
    
    return result_bit;
  }

}

bigInt bigInt::operator+(bigInt bInt){
  bitset<64> sum;
  int carry_in = 0;
  int carry_out = 0;
  
    for(int i = 0; i < 64; i++){
      sum[i] = addBit(number[i], bInt.number[i], carry_in, carry_out);
      carry_in = carry_out;
      carry_out = 0;
    }
    
  number = sum;
  bigInt newBigInt = *(this);
  return newBigInt;
}

bigInt bigInt::operator-(bigInt bInt){
  bInt.twosComplement(bInt.number);// changes bInt to it's two's complement form
  bigInt newBigInt = *(this) + bInt;
  return newBigInt;
}

bigInt bigInt::operator*(bigInt bInt){
  bigInt c;

  if(bInt.bigIntToLong() < 0){
    bInt.twosComplement(bInt.number); //make it the negative value of itself
    twosComplement(number);
  }
  

  while(bInt.bigIntToLong() != 0){
    if((bInt.bigIntToLong() & 1) == 1){// check if rightmost bit is 1
      c = c + *(this);//with *(this) representing a, the multiplicand
    }
    
    bInt.number = bInt.number >> 1;
    number = number << 1;
  }
  
  return c;
  
}
