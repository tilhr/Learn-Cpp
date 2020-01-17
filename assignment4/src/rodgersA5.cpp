//============================================================================
// Name        : rodgersA5.cpp
// Author      : Tyler Rodgers
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Stack.h"
//defining the class



using namespace std;

Stack::Stack(int size){
    //create an array of string of given size
    string *arr = new string[size];
    //set array size
    arraysize = size;
    //set top element 0
    topElement = 0;
    ////push this arr to the list
    bucket.push_front(arr);
    //all done here
}

void Stack::push(string item){
    ////set if array is full
    if(topElement == arraysize){
        //create a new arra
        string *newarr = new string[arraysize];
        //add element to the array
        newarr[0] = item;
        //set top element to 1
        topElement = 1;
        //add this array to linked list
        bucket.push_front(newarr);
    }
    else{
        //insert the item in front array
        bucket.front()[topElement] = item;
        //increase topElemenet
        topElement++;
    }
}

bool Stack::pop(string& target){
    //if bucket is empty return false
    if(bucket.empty()){
        return false;
    }
    /////check if topElement is 0
    if(topElement == 0){
        //now check if there this is only array
        if(bucket.size() == 1){
            return false;
        }
        //if not then delete the top array
        string *arr = bucket.front();
        bucket.pop_front();
        //free array
        delete [] arr;
        //set topElement
        topElement = arraysize - 1;
        //get element
        target = bucket.front()[topElement];
        return true;
    }
    else{
        // decrease topElement
        topElement--;
        //set element
        target = bucket.front()[topElement];
        return true;
    }
}

bool Stack::top(string& target){
    //if bucket is empty return false
    if(bucket.empty()){
        return false;
    }
    /////check if topElement is 0
    if(topElement == 0){
        //now check if there this is only array
        if(bucket.size() == 1){
            return false;
        }
        //if not then delete the top array
        string *arr = bucket.front();
        bucket.pop_front();
        //free array
        delete [] arr;
        //set topElement
        topElement = arraysize;
        //get element
        target = bucket.front()[topElement -1];
        return true;
    }
    else{
        //set element
        target = bucket.front()[topElement - 1];
        return true;
    }
}

void Stack::destroy(){
    //we get all the arrays and destroy them
    while(!bucket.empty()){
        //get the front array
        string* arr = bucket.front();
        //pop array
        bucket.pop_front();
        //deallocate array
        delete [] arr;
    }
    //set topElement to arraysize so that next push operation
    //allocates a array
    topElement = arraysize;
}

//the main function
int main() {
   Stack s(5);
   string st;
   bool b;
   s.push("aaaaa");
   s.push("bbbbb");
   s.push("ccccc");
   s.push("ddddd");
   s.push("eeeee");

   cout << "main: start of part 1" << endl;
   b = s.top(st);
   cout << "main: top of stack " << st << endl;
   b = s.pop(st);
   cout << "main: just popped this ->" << st << endl;
   b = s.top(st);
   cout << "main: new top of stack after pop " << st << endl;
   b = s.pop(st);
   cout << "main: just popped this ->" << st << endl;
   b = s.pop(st);
   cout << "main: just popped this ->" << st << endl;
   b = s.pop(st);
   cout << "main: just popped this ->" << st << endl;
   b = s.pop(st);
   cout << "main: just popped this ->" << st << " stack should now be empty" << endl;
   b = s.top(st);
   if (b)
   {
       cout << "main: stack non-empty when it should be empty" << endl;
       return 4;
   }
   else
   {
       cout << "main: stack empty when it's empty" << endl;
   }

   cout << endl << "main: start of part 2" << endl;
   s.push("aaaaa");   // 1st element 1st array
   s.push("bbbbb");
   s.push("ccccc");
   s.push("ddddd");
   s.push("eeeee");
   s.push("fffff");   // 1st element 2nd array
   s.push("ggggg");
   s.push("hhhhh");
   s.push("iiiii");
   s.push("jjjjj");
   s.push("kkkkk");   // 1st element 3rd array

   b = s.top(st);
   cout << "main: top of stack " << st << endl;
   cout << "main: before while loop " << st << endl;
   b = s.pop(st);
   while (b)
   {
       cout << "main: element of stack " << st << endl;
       b=s.pop(st);
   }

   cout <<"main: before destroy"<< endl;
   s.destroy();
   cout <<"main: after destroy"<< endl;
   s.push("zzzzz");
   b=s.top(st);
   cout << "main: new top of stack " << st << endl;
   s.destroy();

   return 0;
}
