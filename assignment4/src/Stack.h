/*
 * Stack.h
 *
 *  Created on: Nov 12, 2019
 *      Author: tylerrodgers
 */

#ifndef STACK_H_
#define STACK_H_

#include<iostream>
#include<list>


#ifndef MY_STACK_H
#define MY_STACK_H

class Stack{
    //private members
    private:
        int arraysize;
        std::list<std::string*> bucket;//linked list to store the arrays
        int topElement;
    public:
        //constructor
        Stack(int size);
        void push(std::string );
        bool top(std::string &);
        bool pop(std::string &);
        void destroy();
};

#endif



#endif /* STACK_H_ */
