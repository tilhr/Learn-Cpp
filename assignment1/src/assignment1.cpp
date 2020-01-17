//============================================================================
// Name        : assignment1.cpp
// Author      : Tyler Rodgers
// Version     :
// Copyright   : my code. not yours.
// Description : Hello World in C++, Ansi-style
//============================================================================

// do comment if any problem arises

// code

#include <iostream>

using namespace std;

struct LLnode
{
    LLnode *fwdPtr;
    string theData;
};

// this function adds a node to the back of the list
void push_back(LLnode *&llh, string data)
{
    // if list is empty
    if (llh == NULL)
    {
        llh = new LLnode;
        llh->theData = data;
        llh->fwdPtr = NULL;
        return;
    }
    LLnode *temp = llh;
    // traverse to end
    while (temp->fwdPtr != nullptr)
    {
        temp = temp->fwdPtr;
    }
    // create node
    temp->fwdPtr = new LLnode;
    temp = temp->fwdPtr;
    // insert item
    temp->theData = data;
    temp->fwdPtr = NULL;
}
// this function adds a node to the front of the list
void push_front(LLnode *&llh, string data)
{
    LLnode *temp = llh;
    llh = new LLnode;
    llh->theData = data;
    llh->fwdPtr = temp;
}
// returns the number of nodes in the list
int list_length(LLnode *llh)
{
    int n = 0;
    while (llh != NULL)
    {
        llh = llh->fwdPtr;
        n++;
    }
    return n;
}
// retrieves the contents of the node at the front. Does not remove the node. If the list is empty, throws an exception.
string retrieve_front(LLnode *llh)
{
    try
    {
        if (llh == NULL)
        {
            throw "Empty";
        }
        return llh->theData;
    }
    catch (const std::exception &e)
    {
        throw e;
    }
}
// retrieves the contents of the node at the back. Does not remove the node. If the list is empty, throws an exception.
string retrieve_back(LLnode *llh)
{
    try
    {
        if (llh == NULL)
        {
            throw "Empty";
        }
        // traverse to back of list
        while (llh->fwdPtr != NULL)
        {
            llh = llh->fwdPtr;
        }
        return llh->theData;
    }
    catch (const std::exception &e)
    {
        throw e;
    }
}
// displays the data items in each node, producing a report that resembles the following:
void display_nodes(LLnode *llh)
{
    int i = 0;
    while (llh != NULL)
    {
        cout << "node " << i << " data -> " << llh->theData << endl;
        llh = llh->fwdPtr;
        i++;
    }
}



int main()

{

    LLnode *theLLHeader1 = nullptr;

    cout << "Main: number of nodes in empty list " << list_length(theLLHeader1) << endl;

    display_nodes(theLLHeader1);

    push_front(theLLHeader1, "aaaaa");

    push_back(theLLHeader1, "bbbbb");

    push_front(theLLHeader1, "before aaaaa");

    push_back(theLLHeader1, "after bbbbb");

    cout << "Main: number of nodes after 4 pushes - " << list_length(theLLHeader1) << endl;

    display_nodes(theLLHeader1);

    cout << "Main: retrieve front: " << retrieve_front(theLLHeader1) << endl;

    cout << "Main: retrieve back: " << retrieve_back(theLLHeader1) << endl;

    cout << endl;

    LLnode *theLLHeader2 = nullptr;

    push_front(theLLHeader2, "33333");

    push_front(theLLHeader2, "22222");

    push_front(theLLHeader2, "11111");

    push_back(theLLHeader2, "44444");

    push_back(theLLHeader2, "55555");

    push_back(theLLHeader2, "66666");

    display_nodes(theLLHeader2);

    return 0;

}
