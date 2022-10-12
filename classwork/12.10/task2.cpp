#include <iostream>
#include<cmath>
using namespace std;

int main()


{
    int m;
    cout << " Enter m= ";
    cin >> m;
    int k = 0;
    while  (pow(4, k) < m)
    {
        k = k + 1;
    }
     cout << "k= " << k - 1 << endl;
     cout << pow(4, k)<< endl;
     cout << " answer= " << k-1<< endl << pow(4, k-1);
    return 0;
}

