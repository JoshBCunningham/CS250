//@Josh Cunningham
//Project 1
//CS-250-351
//09-26-2017
//project1_LinkedList.cpp


#include "project1_LinkedList.hpp"

Node::Node()
{
	m_ptrNext = nullptr;
	m_ptrPrev = nullptr;	
}

LinkedList::LinkedList()
{
	m_ptrFirst = nullptr;
	m_ptrLast = nullptr;    
}

LinkedList::~LinkedList()
{
	Clear();    
}

void LinkedList::Clear()
{
	while (!IsEmpty())
	{
		PopFront();
	}   
}

void LinkedList::PushFront( CustomerData newData )
{
	Node* newNode = new Node;;
	newNode->m_data = newData;
	
	if (IsEmpty())
	{
		m_ptrFirst = newNode;
		m_ptrLast = newNode;
	}
	else
	{		
		m_ptrFirst->m_ptrPrev = newNode; //old first pointers prev pointer now points to new node
		newNode->m_ptrNext = m_ptrFirst; // new node next pointer points to old first node	
		m_ptrFirst = newNode;			 //new node is now first node
	}    

	m_itemCount++;

}

void LinkedList::PushBack( CustomerData newData )
{

	Node* newNode = new Node;;
	newNode->m_data = newData;

	if (IsEmpty())
	{
		m_ptrFirst = newNode;
		m_ptrLast = newNode;
	}
	else
	{
		m_ptrLast->m_ptrNext = newNode; //old last pointer's next now points to new last pointer
		newNode->m_ptrPrev = m_ptrLast; // new node's prev pointer now points to old last node	
		m_ptrLast = newNode;			//new node is now last node
	}	

	m_itemCount++;

}

void LinkedList::PopFront() noexcept
{
	if (IsEmpty())
	{
		return;
	}
	else if (m_ptrFirst == m_ptrLast)
	{
		//last item in list
		delete m_ptrFirst;
		m_ptrFirst = nullptr;
		m_ptrLast = nullptr;
		m_itemCount--;
	}
	else
	{
		Node* ptrSecond = m_ptrFirst->m_ptrNext;
		ptrSecond->m_ptrPrev = nullptr;
		delete m_ptrFirst;
		m_ptrFirst = ptrSecond;
		m_itemCount--;
	}
}

void LinkedList::PopBack() noexcept
{
	if (IsEmpty())
	{
		return;
	}
	else if (m_ptrFirst == m_ptrLast)
	{
		//last item in list
		delete m_ptrFirst;
		m_ptrFirst = nullptr;
		m_ptrLast = nullptr;
		m_itemCount--;
	}
	else
	{
		Node* ptrSecondToLast = m_ptrLast->m_ptrPrev;
		ptrSecondToLast->m_ptrNext = nullptr;
		delete m_ptrLast;
		m_ptrLast = ptrSecondToLast;
		m_itemCount--;
	}
}

CustomerData LinkedList::GetFront() throw (out_of_range)
{
	if (IsEmpty())
	{
		throw out_of_range("Access error: The request is out of range");
	}

	return m_ptrFirst->m_data;
}

CustomerData LinkedList::GetBack() throw (out_of_range)
{
	if (IsEmpty())
	{
		throw out_of_range("Access error: The request is out of range");
	}
	return m_ptrLast->m_data; 
}

CustomerData& LinkedList::operator[]( const int index ) throw(out_of_range)
{

	int counter = 0;
	Node* ptrCurrent = m_ptrFirst;

	if (index < 0 || index >= m_itemCount)
	{
		throw out_of_range ("The index is out of range!");
	}

	while (counter != index)
	{
		// go to the next item
		ptrCurrent = ptrCurrent->m_ptrNext;
		counter++;
	} 
	return ptrCurrent->m_data;
}

bool LinkedList::IsEmpty()
{
	return m_itemCount == 0; 
}

int LinkedList::Size()
{
	return m_itemCount; 
}

//////////////////////////Extra Credit Functions////////////////////////////////////////

// I ran out of time to implement a test for these, but at the very least I had fun writing them!

void LinkedList::Insert(int index, CustomerData newData) throw (out_of_range)
{

	int counter = 0;
	Node* ptrCurrent = m_ptrFirst;
	Node* newNode = new Node;
	newNode->m_data = newData;


	if (index < 0 || index >= m_itemCount) // test for invalid index
	{
		throw out_of_range("The index is out of range!");
	}
	else if (IsEmpty()) // handling in case the linked list is empty
	{
		m_ptrFirst = newNode;
		m_ptrLast = newNode;
	}	

	while (counter != index)
	{
		ptrCurrent = ptrCurrent->m_ptrNext;
		counter++;
	}

	ptrCurrent->m_ptrPrev->m_ptrNext = newNode; // node before index now points to new node
	newNode->m_ptrPrev = ptrCurrent->m_ptrPrev; // new node now points to node before index
	ptrCurrent->m_ptrPrev = newNode;			// node currently at index now points back to new node
	newNode->m_ptrNext = ptrCurrent;			// new node now points forward to old current node
	ptrCurrent = newNode;						//new node is now at specified index

	m_itemCount++; //add 1 to item count
}

void LinkedList::Remove(int index) throw (out_of_range)
{
	int counter = 0;
	Node* ptrCurrent = m_ptrFirst;

	if (index < 0 || index >= m_itemCount) //test for invalid index
	{
		throw out_of_range("The index is out of range!");
	}
	else if (IsEmpty) //test to ensure linked list isn't empty
	{
		return;
	}
	
	while (counter != index)
	{
		ptrCurrent = ptrCurrent->m_ptrNext;
		counter++;
	}

	if (ptrCurrent == m_ptrFirst) //ensures proper deletion if index is first in list
	{
		Node* ptrSecond = m_ptrFirst->m_ptrNext;
		ptrSecond->m_ptrPrev = nullptr;
		delete m_ptrFirst;
		m_ptrFirst = ptrSecond;
		m_itemCount--;
	}
	else if (ptrCurrent == m_ptrLast) //ensures proper deletion if index is at end of list
	{
		Node* ptrSecondToLast = m_ptrLast->m_ptrPrev;
		ptrSecondToLast->m_ptrNext = nullptr;
		delete m_ptrLast;
		m_ptrLast = ptrSecondToLast;
		m_itemCount--;
	}
	else if (m_ptrFirst == ptrCurrent && m_ptrLast == ptrCurrent) //ensures proper deletion if index refrences only item in list
	{
		delete m_ptrFirst;
		m_ptrFirst = nullptr;
		m_ptrLast = nullptr;
		m_itemCount--;
	}
	else
	{
		Node* ptrNext = ptrCurrent->m_ptrNext;	//pointer for next item in list
		Node* ptrPrev = ptrCurrent->m_ptrPrev;	//pointer for previous item in list

		ptrNext->m_ptrPrev = ptrPrev;			//next pointers previous pointer now points to removed nodes previous node
		ptrPrev->m_ptrNext = ptrNext;			//previous pointers next pointer now points to removed nodes next node
		delete ptrCurrent;
	}
}