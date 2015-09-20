#include <bitset>
#include <iostream>
using namespace std;

class bigInt{

  public:
    bigInt(long num = 0);
    void setNum(long num);
    long bigIntToValue();
    void twosComplement(bitset<64>& number);
    bigInt operator+(bigInt& bInt);
    bigInt operator-(bigInt& bInt);
    bigInt operator*(bigInt& bInt);
    double divideBigIntToDouble(bigInt& bInt);
    bigInt divideBigInt(bigInt& bInt);

  private:
    bitset<64> number;
    int addBit(int bit1, int bit2, int& carry_in, int& carry_out);
};
