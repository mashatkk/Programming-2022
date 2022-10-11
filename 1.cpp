#include <iostream>

#include <string>
#include<math.h>
using namespace std;
int main() 
{
    //вести радіус кола > обчислити довжину кола > площу круга > об'єм кулі 
  float R;
  cout << "Enter the R" << endl;
  cin >> R;
  cout << "R=" << R << endl;
  float l;
  l = 2 * R * 3.14;
  cout << "L=" << l << endl;
  float s;
  s = R * R * 3.14;
  cout << "S=" << s << endl;
  float v;
  v = (4 * 3.14 *( R * R * R)) / 3;
   cout << "V=" << v << endl;
  
    return 0;
}