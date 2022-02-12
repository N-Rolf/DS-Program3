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

/********************************************************************
***  FUNCTION Queue                                               ***
*********************************************************************
***  DESCRIPTION   : This is the constructor for the queue        ***
***  INPUT ARGS    : size of queue value                          ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/

StaticQueue::StaticQueue(int size) : Q_SIZE{size}
{
    queue = new PatientInfo[size];
    head = -1;
    tail = -1;
    numItems = 0;
}

/********************************************************************
***  FUNCTION Queue(StaticQueue & old)                            ***
*********************************************************************
***  DESCRIPTION   : This is the copy constructor for the queue   ***
***  INPUT ARGS    : pointer to Queue object                      ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/

StaticQueue::StaticQueue(StaticQueue &old) : head(old.head), tail(old.tail), Q_SIZE(old.Q_SIZE), numItems(old.numItems)
{
    //cout << "Copying " << numItems << " items." << endl;

    queue = new PatientInfo[old.Q_SIZE];

    for (int count = 0; count < numItems; count++)
    {
        //cout << "Copying: " << old.queue[count].name << endl;
        queue[count].name = old.queue[count].name;
        //cout << "Copying: " << old.queue[count].age << endl;
        queue[count].age = old.queue[count].age;
        //cout << "Copying: " << old.queue[count].problem << endl;
        queue[count].problem = old.queue[count].problem;
    }
}

/********************************************************************
***  FUNCTION enqueue                                             ***
*********************************************************************
***  DESCRIPTION   : This function adds a new Element to the Queue,
***                : whose members are passed in from the driver  ***
***  INPUT ARGS    : SElement, int, SElement                      ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/
void StaticQueue::enqueue(const SElement name, int age, SElement problem)
{
    if (isFull())
    {
        cout << "Queue is full. Cannot add." << endl;
        return;
    }
    else
    {
        tail = (tail+1) % Q_SIZE;
        queue[tail].name = name;
        queue[tail].age = age;
        queue[tail].problem = problem;
        //cout << "Enqueueing " << queue[tail].name << " at " << tail << " position." << endl;
        numItems++;
    }

}

/********************************************************************
***  FUNCTION dequeue                                             ***
*********************************************************************
***  DESCRIPTION   : This function removes a struct element from the
***                : front of the queue, tests if queue is empty  ***
***  INPUT ARGS    : pointers to catch variables                  ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/
void StaticQueue::dequeue(SElement & catchName, int & catchAge, SElement & catchProblem)
{
    if (isEmpty())
    {
        cout << "Queue is empty. Cannot delete." << endl;
    }
    else
    {
        head = (head+1) % Q_SIZE;
        catchName = queue[head].name;
        catchAge = queue[head].age;
        catchProblem = queue[head].problem;
        numItems--;
        //cout << "Dequeueing " << queue[head].name << " at " << head << " position." << endl;
    }
}

/********************************************************************
***  FUNCTION isFull                                              ***
*********************************************************************
***  DESCRIPTION   : Tests for a full queue                       ***
***  INPUT ARGS    : none                                         ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : boolean value                                ***
********************************************************************/
bool StaticQueue::isFull() const
{
    bool isFull = true;

    if (numItems < Q_SIZE)
        isFull = false;

    return isFull;
}

/********************************************************************
***  FUNCTION isEmpty                                             ***
*********************************************************************
***  DESCRIPTION   : Tests for an empty queue                     ***
***  INPUT ARGS    : none                                         ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : boolean value                                ***
********************************************************************/
bool StaticQueue::isEmpty() const
{

    bool isEmpty = true;

    if (numItems)
        isEmpty = false;

    return isEmpty;
}

/********************************************************************
***  FUNCTION view                                                ***
*********************************************************************
***  DESCRIPTION   : Displays the queue from front to rear        ***
***  INPUT ARGS    : none                                         ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/

void StaticQueue::view()
{
    int i = 0;
    cout << "Number of items: " << numItems << endl;
    if (numItems == 0)
        {
            cout << "Zero elements in Queue. Cannot view." << endl;
            return;
        }
    
    i = head+1;
    
    do
    {
        cout << "->" << queue[i].name << ", " << queue[i].age << ", " << queue[i].problem << endl;
        if (i == Q_SIZE-1)
        {
            i = 0;
        }
        else
        {
            i++;
        }
    } while (i != tail+1);
}