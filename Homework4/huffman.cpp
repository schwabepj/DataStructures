#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include "LinkedBinaryTree.h"
using namespace std;

//start of main function

int main(int argc, char* argv[]){

cout << "The name of the program is: " << argv[0] << endl;
LinkedBinaryTree A;

//stores the strings from the input file
vector<string> Z;
string z;

// used to store values from frequency.txt
string x;
int y;

//makes nodes from the information in frequency.txt
ifstream myfile ("frequency.txt");
if(myfile.is_open()){
 while(myfile >> x >> y){
        A.createNode(x,y);
}
myfile.close();
}


//stores the input.txt in Z
ifstream myfile2("input.txt");
if(myfile2.is_open()){
 while(myfile2 >> z){
        Z.push_back(z);
}
}
myfile2.close();

//creates a tree by combining the two lowest nodes and adding it to the list to sort
A.createTree();

//uses the function encode in LinkedBinaryTree.h when encode is entered to turn the input into a code
if(strcmp(argv[1],"encode") == 0){
	A.encode(Z);
}

//uses the decode function in LinkedBinaryTree.h when decode is entered to turn encoded.txt into readable words
if(strcmp(argv[1],"decode") == 0){
	A.decode();
}

return 0;
}

