//@Josh Cunningham
//Project 1
//CS-250-351
//09-26-2017
//project1_program.hpp

#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <list>
#include <string>
#include <iostream>
using namespace std;

#include "project1_LinkedList.hpp"

class Program
{
    public:
    void Start();

    private:
    void LoadCustomers();
    void SaveCustomers();

    LinkedList m_customers; // updated
};

#endif
