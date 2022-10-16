// 19 (a)
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main()
{
   int i;
   cout << "Enter i " << endl;

   cin >> i;
   int n;

   cout << "Enter n " << endl;

   cin >> n;
   int s = 0;

   if (i > n) {
      cout << "I greater then N" << endl;
      return 1;
   }

   int count = 0;

   for (size_t j = 1; j <= n; j++)
   {
      if (j != i) {
         s += j;
         count += 1;
      }

   }
   cout << "Sum = " << s << endl;
   cout << "Num = " << count << endl;
   cout << "Avg = " << s / count << endl;

   return 0;
}