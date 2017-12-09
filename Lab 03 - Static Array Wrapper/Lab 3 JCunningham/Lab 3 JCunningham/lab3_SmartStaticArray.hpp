// Josh Cunningham
// 09/05/2017
// Lab 3

#ifndef _SMART_STATIC_ARRAY_HPP
#define _SMART_STATIC_ARRAY_HPP

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

const int MAX_SIZE = 1000;

class SmartStaticArray
{
    public:
    SmartStaticArray();

    void Push( const string& newItem )throw (length_error);
    void Insert( int index, const string& newItem )throw(out_of_range, length_error);
    void Extend( const SmartStaticArray& other ) throw (length_error);
    void Pop();
    void Remove( int index ) throw(out_of_range);
	string Get(int index) const throw (out_of_range);

    int Size() const;
    bool IsFull() const;
    bool IsEmpty() const;

    string operator[]( int index );
    SmartStaticArray& operator=( const SmartStaticArray& other );
    bool operator==( const SmartStaticArray& other );
    bool operator!=( const SmartStaticArray& other );

    private:
    void ShiftRight( int index ) noexcept;
    void ShiftLeft( int index ) noexcept;

    string m_data[MAX_SIZE];
    int m_itemCount;
};

#endif
