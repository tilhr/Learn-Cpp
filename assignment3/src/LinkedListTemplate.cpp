/*
 * LinkedListTemplate.cpp
 *
 *  Created on: Oct 4, 2019
 *      Author: tylerrodgers
 */


#include "LinkedListTemplate.h"
template <class T>
LinkedList<T>::LinkedList() {
// initialize head node to null
this->head = nullptr;
}
template <class T>
void LinkedList<T>::push_front(T newData) {
LLnode<T> *newNode = new LLnode<T>;
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
template <class T>
void LinkedList<T>::push_back(T newData) {
if (!head)
{
head = new LLnode<T>;
head->data = newData;
head->next = nullptr;
}
else
{
LLnode<T> *current = head;
LLnode<T> *newNode = new LLnode<T>;
newNode->data = newData;
newNode->next = nullptr;
while (current->next)
{
current = current->next;
}
current->next = newNode;
}
}
template <class T>
int LinkedList<T>::size() {
int count = 0;
LLnode<T> *trav = new LLnode<T>;
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
template <class T>
T LinkedList<T>::retrieve_front() {
if (!head) throw string("Exception at retrieve back");
return (head->data);
}
template <class T>
T LinkedList<T>::retrieve_back() {
LLnode<T> *trav = new LLnode<T>;
trav = head;
if (!head) throw string("Exception at retrieve back");
while (trav->next)
{
trav = trav->next;
}
return trav->data;
}
template <class T>
void LinkedList<T>::display_nodes() {
LLnode<T> *trav = new LLnode<T>;
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
LinkedList<string> list;
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

LinkedList<int>list2;

list2.push_front(33333);
list2.push_front(22222);
list2.push_front(11111);
list2.push_back(44444);
list2.push_back(55555);
list2.push_back(66666);
cout<<"Length of list: "<<list2.size()<<endl;
list2.display_nodes();

return 0;
}

