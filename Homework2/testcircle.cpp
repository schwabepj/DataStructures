#include "CircleList.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
CircleList<string> playlist;

if (playlist.empty())
 cout << "You successfully made an empty list" << endl;

playlist.Add("Staying Alive");
cout << playlist.front() << endl;
cout << playlist.back() << endl;

playlist.Add("Le Freak");
cout << playlist.front() << endl;
cout << playlist.back() << endl;

playlist.Add("Jive Talkin");
cout << playlist.front() << endl;
cout << playlist.back() << endl;

playlist.advance();
cout << playlist.front() << endl;
cout << playlist.back() << endl;

playlist.remove();
cout << playlist.front() << endl;
cout << playlist.back() << endl;

playlist.Add("Disco Inferno");
cout << playlist.front() << endl;
cout << playlist.back() << endl;

return 0;
}    
