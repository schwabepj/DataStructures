//Peter Schwabe
//Program 3
//9-8-18
#include <iostream>
using namespace std;

bool isPerfect(int n)
{
int div(0),sum(0);
bool ans(false);

for(int i = 1; i < n; i++)
{
div = n % i;
if (div == 0)
{
sum = sum + i;
}
}

if (n == sum)
{
ans = true;
}
return ans;
}


int main()
{
for(int j = 1;j <= 9999;j++)
{
//cout << j << endl;
//cout << isPerfect(j) << endl;

if(isPerfect(j) == true)
{
cout << j << endl;
}

} 
return 0;
}
