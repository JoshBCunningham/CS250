//Josh Cunningham
//08/29/2017
//lab1.part3.cpp

#include <iostream>  //required for cout
#include <string>    //required for strings
#include <queue>     // required for queues
using namespace std;

int main()
{
	
	float balance = 0.0;

	queue<float> transactions;

	transactions.push(100.00);
	transactions.push(-70.00);
	transactions.push(-5.00);
	transactions.push(50.00);

	while (!transactions.empty())
	{
		cout << "$" << transactions.front() << " pushed to account" << endl;
		
		balance += transactions.front();
		
		transactions.pop();

	}

	cout << "\nFinal balance: $" << balance << endl;

	return 0;

}