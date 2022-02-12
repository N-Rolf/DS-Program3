/********************************************************************
***  NAME       :Neil Rolf                                        ***
***  CLASS      :CSc 300                                          ***
***  ASSIGNMENT :Assignment 3                                     ***
***  DUE DATE   :02/11/2022                                       ***
***  INSTRUCTOR :  Kurtenbach                                     ***
*********************************************************************
***  DESCRIPTION :Queue ADT implemented with linked list          ***
********************************************************************/
#ifndef _QUEUE_H
#define _QUEUE_H
#include <string>

typedef std::string SElement;

class StaticQueue
{
    public:
        StaticQueue(int);
        StaticQueue(StaticQueue &);
        void enqueue(const SElement, int, SElement);
        void dequeue(SElement &, int &, SElement &);
        bool isEmpty() const;
        bool isFull() const;
        void view();
    private:
        const int Q_SIZE;
        struct PatientInfo
        {
            SElement name;
            int age;
            SElement problem;
        };
        typedef PatientInfo * QPointer;
        QPointer queue;
        int head, tail;
        int numItems;
};

#endif