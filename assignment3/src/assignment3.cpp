//============================================================================
// Name        : rodgersA3.cpp
// Author      : Tyler Rodgers
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "LinkedList.h"

LinkedList ::LinkedList() {
// initialize head node to null
this->head = nullptr;
}

void LinkedList ::push_front(string newData) {
LLnode *newNode = new LLnode ;
if (!head)
{
newNode->data = newData;
newNode->next = nullptr;
head = newNode;
}
else
{
newNode->data = newData;
newNode->next = head;
head = newNode;
}
}

void LinkedList ::push_back(string newData) {
if (!head)
{
head = new LLnode ;
head->data = newData;
head->next = nullptr;
}
else
{
LLnode *current = head;
LLnode *newNode = new LLnode ;
newNode->data = newData;
newNode->next = nullptr;
while (current->next)
{
current = current->next;
}
current->next = newNode;
}
}

int LinkedList ::size() {
int count = 0;
LLnode *trav = new LLnode ;
trav = head;
if (!head)
{
return 0;
}
else
{
while (trav)
{
count++;
trav = trav->next;
}
return count;
}

}

string LinkedList ::retrieve_front() {
if (!head) throw string("Exception at retrieve back");
return (head->data);
}

string LinkedList ::retrieve_back() {
LLnode *trav = new LLnode ;
trav = head;
if (!head) throw string("Exception at retrieve back");
while (trav->next)
{
trav = trav->next;
}
return trav->data;
}

void LinkedList ::display_nodes() {
LLnode *trav = new LLnode ;
trav = head;
if (!head)
{
cout << "No nodes to display " << endl;
}
else
{
cout << "Displaying nodes: " << endl;
while (trav)
{
cout << trav->data << ", ";
trav = trav->next;
}
}
cout << endl;
}
int main() {
LinkedList list;
cout << "Main: number of nodes in empty list " << list.size()
<< endl;
list.display_nodes();
list.push_front("aaaaa");
list.push_back("bbbbb");
list.push_front("before aaaaa");
list.push_back("after bbbbb");
cout << "Main: number of nodes after 4 pushed: " << list.size()
<< endl;
cout<<"Length of list: "<<list.size()<<endl;
list.display_nodes();
cout << "Main: retrieve front: " << list.retrieve_front() << endl;
cout << "Main: retrieve back: " << list.retrieve_back() << endl;
cout << endl;

LinkedList list2;

// list2.push_front(33333);
// list2.push_front(22222);
// list2.push_front(11111);
// list2.push_back(44444);
// list2.push_back(55555);
// list2.push_back(66666);
// cout<<"Length of list: "<<list.size()<<endl;
// list2.display_nodes();

return 0;
}
