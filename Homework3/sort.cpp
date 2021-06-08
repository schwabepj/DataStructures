//Peter Schwabe
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;

template <typename T>
void print(vector<T>& A){

for(int n = 0; n < A.size(); n++){
    cout << A[n] << " ";
}
cout << endl;
}

template <typename T>
vector<T> SelectionSort (vector<T>& A){

for(int i = 0; i< A.size();i++){
   int iMin = i;
   
   for(int j = i+1; j < A.size(); j++){
	if(A[j] < A[iMin]){
	   iMin = j;
	}
   }
   int temp = A[i];
   A[i] = A[iMin];
   A[iMin] = temp;
}
return A;
}

template <typename T>
vector<T> BubbleSort(vector<T>& A){

for(int k = 1; k < A.size(); k++){
   
   bool flag = false;
   
   for(int i = 0; i < (A.size() - k);i++){
      
      if(A[i] > A[i+1]){
          int temp = A[i];
          A[i] = A[i + 1];
          A[i + 1] = temp;
          flag = true;
      }
   }
   if(flag == false){
	break;
   }
}

return A;
}

template <typename T>
vector<T> InsertionSort(vector<T>& A){

for(int i = 1; i < A.size();i++){
   int value = A[i];
   int hole = i;
   while ( hole > 0 && A[hole - 1] > value){
	A[hole] = A[hole -1];
	hole = hole - 1;
   } 
   A[hole] = value;
}

return A;
}

template <typename T>
void Merge(vector<T>& L, vector<T>& R, vector<T>& A){

int i = 0, j = 0, k = 0;
int nL = L.size();
int nR = R.size();

while(i < nL && j < nR){
   if (L[i] < R[j]){
	A[k] = L[i];
	i++;
   }
   else{	
	A[k] = R[j];
	j++;
   }
   k++;
}

while ( i < nL ){
   A[k] = L[i];
   i++;
   k++;
}
while( j < nR ){
   A[k] = R[j];
   j++;
   k++;
}

}

template <typename T>
void MergeSort(vector<T>& A){

if(A.size() < 2){
 return;
}
int mid = A.size()/2;
vector<T> left;
vector<T> right;

for(int i = 0; i < mid;i++){
   left.push_back(A[i]);
}
for(int j = 0; j < A.size() - mid;j++){
   right.push_back(A[mid + j]);
}
MergeSort(left);
MergeSort(right);
Merge(left, right, A);
}


template <typename T>
int Partition(vector<T>& A,int start, int end){
int pivot = A[end];
int pIndex = start;
for(int i = start; i < (end - 1); i++){

     if(A[i] <= pivot){        
	int temp = A[i];
	A[i] = A[pIndex];
        A[pIndex] = temp;
	pIndex++;
   }
}
int temp = A[pIndex];
A[pIndex] = A[end];
A[end] = temp;
return pIndex;
}

template <typename T>
void QuickSort(vector<T>& A, int start, int end){

if(start <= end){
int pIndex = Partition(A, start, end);
QuickSort(A,start,pIndex - 1);
QuickSort(A,pIndex + 1,end);
}
}

int main(){

int x;
vector<int> V,W,Y;

ifstream myfile ("inputs.txt");
if(myfile.is_open()){
 while(myfile >> x){
	V.push_back(x);
}
myfile.close();
}

cout << "Selection Sort:" << endl;
Y = V;
print(Y);
auto start = std::chrono::high_resolution_clock::now();
W = SelectionSort(Y);
auto finish = std::chrono::high_resolution_clock::now();
cout << "Time of function: ";
std::cout << std::right << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << "ns\n";
print(W);
cout << endl;

cout << "Bubble Sort:" << endl;
Y = V;
print(Y);
auto start2 = std::chrono::high_resolution_clock::now();
W = BubbleSort(Y);
auto finish2 = std::chrono::high_resolution_clock::now();
cout << "Time of function: ";
std::cout << std::right << std::chrono::duration_cast<std::chrono::nanoseconds>(finish2-start2).count() << "ns\n";
print(W);
cout << endl;

cout << "Insertion Sort:" << endl;
Y = V;
print(Y);
auto start3 = std::chrono::high_resolution_clock::now();
W = InsertionSort(Y);
auto finish3 = std::chrono::high_resolution_clock::now();
cout << "Time of function: ";
std::cout << std::right << std::chrono::duration_cast<std::chrono::nanoseconds>(finish3-start3).count() << "ns\n";
print(W);
cout << endl;

cout << "Merge Sort:" << endl;
Y = V;
print(Y);
auto start4 = std::chrono::high_resolution_clock::now();
MergeSort(Y);
auto finish4 = std::chrono::high_resolution_clock::now();
cout << "Time of function: ";
std::cout << std::right << std::chrono::duration_cast<std::chrono::nanoseconds>(finish4-start4).count() << "ns\n";
print(Y);
cout << endl;


cout << "Quick Sort:" << endl;
Y = V;
print(Y);
auto start5 = std::chrono::high_resolution_clock::now();
QuickSort(Y,0,Y.size());
auto finish5 = std::chrono::high_resolution_clock::now();
cout << "Time of function: ";
std::cout << std::right << std::chrono::duration_cast<std::chrono::nanoseconds>(finish5-start5).count() << "ns\n";
print(Y);
cout << endl;

return 0;
}
