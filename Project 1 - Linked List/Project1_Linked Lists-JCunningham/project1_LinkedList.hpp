#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

//@Josh Cunningham
//Project 1
//CS-250-351
//09-26-2017
//project1_LinkedList.hpp

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

#include "project1_CustomerData.hpp"

struct Node
{
    public:
    Node();

    Node* m_ptrNext;
    Node* m_ptrPrev;

    CustomerData m_data;
};

class LinkedList
{
    public:
    LinkedList();
    ~LinkedList();

    void PushFront( CustomerData newData );
    void PushBack( CustomerData newData );
	void Insert( int index, CustomerData newData) throw (out_of_range); ////Extra Credit Function
    void PopFront() noexcept;
    void PopBack() noexcept;
	void Remove(int index) throw (out_of_range);	////Extra Credit Function
    CustomerData GetFront() throw (out_of_range);
    CustomerData GetBack() throw (out_of_range);
    CustomerData& operator[]( const int index ) throw(out_of_range);
    void Clear();

    bool IsEmpty();
    int Size();

    private:
    Node* m_ptrFirst;
    Node* m_ptrLast;

    int m_itemCount;

    friend class Tester;
};

#endif
