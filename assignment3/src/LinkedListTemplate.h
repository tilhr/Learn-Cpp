/*
 * LinkedListTemplate.h
 *
 *  Created on: Oct 4, 2019
 *      Author: tylerrodgers
 */

#ifndef LINKEDLISTTEMPLATE_H_
#define LINKEDLISTTEMPLATE_H_

#include <iostream>
#include <string>

using namespace std;

// define struct of template
template <typename T>
struct LLnode{
T data;
LLnode * next;
};

// declare class of template type
template <class T>
class LinkedList {
LLnode <T> *head;
public:
LinkedList<T>();
void push_front(T);
void push_back(T);
int size();
T retrieve_front();
T retrieve_back();
void display_nodes();
};

#endif /* LINKEDLISTTEMPLATE_H_ */
