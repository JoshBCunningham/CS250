//Josh Cunningham
//08/29/2017
//lab1.part2.cpp

#include <iostream>		// required for cout
#include <list>			// required for list
#include <string>		// required for strings
using namespace std;

void AddCourses(list<string>& courses)
{
	courses.push_back("cs 250");
	courses.push_back("cs 200");
	courses.push_back("cs 210");
	courses.push_back("cs 235");
	courses.push_back("cs 134");
	courses.push_back("cs 211");

	cout << "Normal Order" << endl;
}

void SortList(list<string>& courses)
{
	courses.sort();
	cout << "Sorted Order" << endl;
}

void ReverseList(list<string>& courses)
{
	courses.reverse();
	cout << "Reverse Order" << endl;
}

void DisplayCourses(list<string>& courses)
{
	int counter = 0;

	for (list<string>::iterator it = courses.begin(); it != courses.end(); it++)
	{
		if (counter != 0) { cout << ". "; }
		cout << counter++ << ". " << (*it);
	}
	cout << endl;
}

int main()
{
	list<string> courses;

	AddCourses(courses);
	DisplayCourses(courses);
	SortList(courses);
	DisplayCourses(courses);
	ReverseList(courses);
	DisplayCourses(courses);

	return 0;
}
