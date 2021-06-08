//Peter Schwabe
//Problem 2
//9/7/18

#include <iostream>
using namespace std;

int main()
{
double number,max,min,avg,sum;
int value; 
cout << "Enter a value" << endl;
cin >> value;

double list[value];
for (int i=0; i < value; i++)
{
cout << "Enter a number" << endl;
cin >> number;
list[i] = number;
}

max = list[0];
min = list[0];

for (int j=0; j < value; j++)
{

if(list[j] >= max)
{
max = list[j];
}

if(list[j] <= min)
{
min = list[j];
}

sum = sum + list[j];
}
avg = sum/value;

cout << "Minimum: " << min << endl;
cout << "Maximum: " << max << endl;
cout << "Average: " << avg << endl;

return 0;
}
