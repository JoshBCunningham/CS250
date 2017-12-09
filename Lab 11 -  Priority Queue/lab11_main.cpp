//@Josh Cunningham	
//Lab 11: Priority Queue 
//CS-250-351
//10/24/2017
//lab11_main.cpp

#include "lab11_PriorityQueue.hpp"

#include <fstream>
#include <string>
using namespace std;

void LoadMessages( NaivePriorityQueue<string>& mq )
{
    ifstream input( "input_message.txt" );

    int priority;
    string line;
    while ( input >> priority )
    {
        input.ignore();
        getline( input, line );

        mq.Push( line, priority );
    }

    input.close();
}

int main()
{
    NaivePriorityQueue<string> messageQueue;
    LoadMessages( messageQueue );

    cout << endl;
    cout << messageQueue.Size() << " items in priority queue" << endl;

    cout << endl;
    messageQueue.Display();

    cout << endl;
    string highestPriority = messageQueue.GetHighestPriority();
    cout << "Highest priority: " << highestPriority << endl;
	

    return 0;
}
