//Peter Schwabe
//9-7-18
//Problem 1
#include <iostream>
using namespace std;

int main(){
double value;
int count(0);

cout << "Enter a value" << endl;
cin >> value;
while (value > 2)
{
value = value/2;
count++;
}
cout << count << endl;

return 0;
}
