/*
 * LinkedList.h
 *
 *  Created on: Oct 4, 2019
 *      Author: tylerrodgers
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include <string>

using namespace std;


// define struct of template
struct LLnode{
string data;
LLnode * next;
};

// declare class of template type
class LinkedList {
LLnode *head;
public:
LinkedList();
void push_front(string);
void push_back(string);
int size();
string retrieve_front();
string retrieve_back();
void display_nodes();
};

#endif /* LINKEDLIST_H_*/
