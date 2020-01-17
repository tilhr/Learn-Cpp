//============================================================================
// Name        : rodgersA7.cpp
// Author      : Tyler Rodgers
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<cstring>
#include<string>
#include<fstream>


using namespace std;

// employee class
class Employee{
   private:
       int ssn;// ssn number
       string lname;// last name
       string fname;// First name
       Employee *next;// next employee
   public:
       // constructor
       Employee(){
           ssn=0;
           lname="";
           fname="";
           next=NULL;
       }

       // constructor with arguments
       Employee(int a,string b,string c){
           ssn=a;
           lname=b;
           fname=c;
           next=NULL;
       }

       // setter methods
       void setssn(int a){ssn=a;}
       void setlname(string a){lname=a;}
       void setfname(string a){fname=a;}
       void setNext(Employee *a){next=a;}

       // getter methods
       int getssn(){return(ssn);}
       string getlname(){return(lname);}
       string getfname(){return(fname);}
       Employee* getNext(){return(next);}


       // tostring employee
       void tostring(){
           cout<<" employee "<<ssn<<" name "<<fname <<" "<<lname;
       }

};


// hash list of employee
class HashList{
   private:
       Employee **_root_;// _root_
       int _s;// hash table size

       // hash function
       int hash(int a){
           return(a%_s);
       }
   public:

       // constructor with one argument
       HashList(int s){
           _root_ = new Employee*[s];
           _s=s;

           for(int i=0;i<s;i++){
               _root_[i]=NULL;
           }
       }


       // add employee in list
       void add(int a,string b,string c){

           // employee object
           Employee *ar=new Employee(a,b,c);

           // indext using hash function
           int i=hash(a);

           // add in _root_ element ih corresponding index
           if(_root_[i]==NULL){
               _root_[i]=ar;
           }
           else{
               Employee *current=_root_[i];

               // after collision add in last
               while(current!=NULL){
                   if(current->getNext()==NULL){
                       current->setNext(ar);
                       break;
                   }
                   else{
                       current=current->getNext();
                   }
               }
           }
       }

       // display all employee
       void display(){
           int n=0;

           for(int i=0;i<_s;i++){
               cout<<"\nhash table entry "<<(i+1);

               Employee *current=_root_[i];

               // if no data exist in this corresponding index
               if(current==NULL){
                   cout<<"no entry from this entry";
               }
               else{
                   // if no collision data exist in this corresponding index
                   if(current->getNext()==NULL){
                       current->tostring();
                       n++;
                       cout<<" there is no chain from this entry";
                   }
                   else{

                       // all collisions data
                       current->tostring();
                       n++;
                       current=current->getNext();

                       while(current!=NULL){
                           cout<<"\nchain - ";
                           current->tostring();
                           n++;
                           current=current->getNext();
                       }
                   }
               }
           }

           cout<<"\nend of list. There are a total of "<<n<<" employees.";
       }


       // find ssn number and corresponding name
       void find(int a){
           int i=hash(a);

           Employee *current=_root_[i];
           while(current!=NULL){

               // if ssn number found in list
               if(current->getssn()==a){
                   cout<<"that is "<<current->getfname()<<" "<<current->getlname();
                   return;
               }
               else{
                   current=current->getNext();
               }
           }

           // no data found
           cout<<"No name found.";

       }
};

// split string

string getValue(string aString,int s,int e){
   string ret="";



   for(int i=s;i<=e;i++){
       if(i<aString.length()){

           // if space found , break


           // "ABCD "
           // as "ABCD"

           if(aString.at(i)==' '){
               break;
           }
           else{
               ret+=aString.at(i);
           }
       }
   }
   return(ret);
}


// string to int value

int ssnValue(string aString){

   int ret=0;
   ret+=(aString.at(0)-'0')*100000000;
   ret+=(aString.at(1)-'0')*10000000;
   ret+=(aString.at(2)-'0')*1000000;
   ret+=(aString.at(3)-'0')*100000;
   ret+=(aString.at(4)-'0')*10000;
   ret+=(aString.at(5)-'0')*1000;
   ret+=(aString.at(6)-'0')*100;
   ret+=(aString.at(7)-'0')*10;
   ret+=(aString.at(8)-'0');


   return(ret);
}

// main function

int main(){
   HashList list(20);

   ifstream input;

   // enter file name

   cout<<"Enter file name : ";
   char inputFile[20];
   cin>> inputFile;
   string line;


   input.open( inputFile);


   // read file line by line

   while(getline(input, line)){
       int ssn=ssnValue(line);
       string ln=getValue(line,9,18);
       string fn=getValue(line,19,33);
       list.add(ssn,ln,fn);
   }

   // display all employee

   list.display();

   // search name , by ssn number

   cout<<"\n\nFind Person";
   while(true){
       int ssn;
       cout<<"\nenter employee ssn ";
       cin>>ssn;
       if(ssn==0){
           break;
       }
       list.find(ssn);
   }

   cout<<"\nThank you and have a nice day";
   return(0);
}
