//============================================================================
// Name        : rodgersA8.cpp
// Author      : Tyler Rodgers
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<fstream>

using namespace std;

void heapify(int arr[], int n, int i);
void buildHeap(int* arr, int a, int e);
void displayArray(int* list, int low, int high);
bool checkIfHeap(int list[], int i, int n);
void heapSort(int list, int low, int high);

void heapSort(int list[], int low, int high) {
   buildHeap(list, low, high);
}
void heapify(int list[], int n, int i){
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	// left child is larger than root
	if (l < n && list[l] > list[largest])
		largest = l;

	// right child is larger than largest so far
	if (r < n && list[r] > list[largest])
		largest = r;

	if (largest != i){
		//swaps values
       int temp = list[i];
       list[i] = list[largest];
       list[largest] = temp;

       heapify(list, n, largest);
	}
}

void buildArray(int* list, int size, string path){
   ifstream ifs(path.c_str());
   string line = "";
   int l = 0;
   while(ifs>>line){
           for(int i=0;i<size && l<line.size();i++){
               string s = line.substr(l,3);
               list[i] = atoi(s.c_str());
               l+=3;
           }
   }
}

void buildHeap(int list[], int a, int e){
	for (int i = e/2; i >= 0; i--) //Heap process
		heapify(list, e, i);

	for (int i = e; i >= 0; i--){
       // moves current root to end
       int temp = list[0];
       list[0] = list[i];
       list[i] = temp;
       //Heapify
       heapify(list, i, 0);
	}
}

void displayArray(int list[], int low, int high){
   for(int i=low;i<=high;i++){
       if((i+1)%10==0)cout<<endl;
       cout<<list[i]<<" ";
   }
}

bool checkIfHeap(int list[], int i, int n){
	if (i > (n - 2)/2)
		return true;
	//checking parent and child index
	if (list[i] >= list[2*i + 1] && list[i] >= list[2*i + 2] && checkIfHeap(list, 2*i + 1, n) && checkIfHeap(list, 2*i + 2, n))
		return true;
	return false;
}

int main(){
	int low, high;
	low = 0; // low array index
	high = 99; // high array index
	bool b;
	int list[100];
	string p ="c:/rodgersA8/a81data.txt";
	cout << "main: building first array (from a71data.txt)" << endl;
	buildArray (list, 100, p);
	cout << "main: displaying first array" << endl << endl;
	displayArray (list, low, high);
	cout << endl;
	b=checkIfHeap (list, low, high);
	if (b)
		cout << "main: the first array is already a heap" << endl << endl;
	else
		cout << "main: the first array is not a heap" << endl << endl;
	cout << "main: now building heap" << endl;
	buildHeap (list, low, high);
	cout << "main: now displaying first array after heaping" << endl << endl;
	displayArray (list, low, high);
	b=checkIfHeap (list, low, high);
	if (b)
		cout << endl << "main: after heaping, the first array is a heap" << endl << endl;
	else{
		cout << endl << "main: after heaping, the first array is not a heap" << endl;
	return 4;
}
	p ="c:/rodgersA8/a82data.txt";
	cout << "main: building second array (from a72data.txt)" << endl;
	buildArray (list, 100, p);
	cout << "main: displaying second array" << endl << endl;
	displayArray (list, low, high);
	heapSort (list, low, high);
	cout << endl << "main: displaying second array, which should now be sorted" << endl << endl;
	displayArray (list, low, high);
	return 0;
}
