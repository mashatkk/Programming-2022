//Нехай k-ціле від 1 до 365. Присвоїти цілій змiннiй n значення 1, 2...,б чи 7 залежно від того, на який день тижня (понедiлок, вiвторок,... суботу чи неділю) припадає k-й день року, в якому 1 січня - понедiлок.
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() 
{
    map <int, string> s;
    s[1] = "Monday";
    s[2] = "Tuesday";
    s[3] = "Wendsday";
    s[4] = "Thursday";
    s[5] = "Friday";
    s[6] = "Saturday";
    s[7] = "Sunday";
    cout << "Enter number of day"<<endl;
    int b;
    cin >> b;
    while (b > 7) {
        b -=  7;
    }
    cout << s[b] << endl;
    return 0;
  }