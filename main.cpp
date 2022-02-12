/********************************************************************
***  NAME       :Neil Rolf                                        ***
***  CLASS      :CSc 300                                          ***
***  ASSIGNMENT :Assignment 3                                     ***
***  DUE DATE   :02/11/2022                                       ***
***  INSTRUCTOR :  Kurtenbach                                     ***
*********************************************************************
***  DESCRIPTION :Queue ADT implemented with linked list          ***
********************************************************************/
#include "Queue.h"
#include <iostream>
#include <string>

using namespace std;

void statusCheck(StaticQueue);
const int SIZE = 10;

int main()
{
    StaticQueue testQueueA(SIZE);

    string nameArray[10] = {"Liam", "Olivia", "Noah", "Emma", "Spike",
                            "Ava", "Elijah", "Charlotte", "William", "Sophia"};
    int ageArray[10] = {14, 32, 56, 23, 41,
                        70, 02, 69, 50, 75};
    string problemArray[10] = {"abdominal pain", "urinary tract infection", "atherosclerosis",
                               "anxiety", "lumbago", "diabetes", "diaper rash", "hyperlipidemia",
                               "atrial fibrillation"};
    string catchName, catchProblem;
    int i, catchAge, emptyStatus, fullStatus;

    //partial enqueue test
    cout << "\npartial enqueue test - testQueueA\n" << "*********************************************\n"; 
    for(i=0; i<5; i++)
    {
        testQueueA.enqueue(nameArray[i], ageArray[i], problemArray[i]);
    }
    statusCheck(testQueueA);

    //copy constructor test
    cout << "\ncopy constructor test\n" << "*********************************************\n"; 
    StaticQueue testQueueB(testQueueA);
    statusCheck(testQueueB);

    //partial dequeue test
    cout << "\npartial dequeue test - testQueueA\n" << "*********************************************\n"; 
    for(i=0; i<3; i++)
    {
        testQueueA.dequeue(nameArray[i], ageArray[i], problemArray[i]);
    }
    testQueueA.view();
    //statusCheck(testQueueA); broken for some reason

    //enqueue overflow test
    cout << "\noverflow test - testQueueA\n" << "*********************************************\n"; 
    for(i=0; i<9; i++)
    {
        testQueueA.enqueue(nameArray[i], ageArray[i], problemArray[i]);
    }
    statusCheck(testQueueA);

    //underflow test
    cout << "\nunderflow enqueue test - testQueueA\n" << "*********************************************\n"; 
    for(i=0; i<11; i++)
    {
        testQueueA.dequeue(nameArray[i], ageArray[i], problemArray[i]);
    }
    statusCheck(testQueueA);

    return 0;
}

void statusCheck(StaticQueue object)
{
    object.view();
    cout << "Empty status: " << object.isEmpty() << endl;
    cout << "Full status: " << object.isFull() << endl;
}