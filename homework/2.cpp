#include <iostream>

#include <string>
#include<math.h>
using namespace std;
int main() 
{
  //Ввести два натуральних числа >обчислити їх середнє арифметичне > середнє геометричне значення
  float a;
   cout << " Enter number" << endl;
  cin >> a;
  float b;
  cout << " Enter number again " <<   endl;

  cin >> b;
  float m;
  m = ( a + b)/2;
  cout << " m=" << m << endl ;
  float g;
  g = sqrt( a * b) ;
  cout << " g=" << g << endl ;
  
  
  
  
   
  
  
    
    return 0;
}