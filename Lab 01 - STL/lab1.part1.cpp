//Josh Cunningham
//08/29/2017
//lab1.part1.cpp

#include <iostream>  // required for cout
#include <vector>	 // required for vector
#include <string>	 // required for strings
using namespace std;

void AddIngredients(vector<string>& ingredients)
{
	ingredients.push_back("lettuce");
	ingredients.push_back("tomato");
	ingredients.push_back("mayo");
	ingredients.push_back("bread");
}

void DisplayIngredients(const vector<string>& ingredients)
{
	for (unsigned int i = 0; i < ingredients.size() ; i++)
	{
		cout << i << ". " << ingredients[i] << endl;
	}
}

int main()
{
	vector<string> ingredients;

	AddIngredients( ingredients );

	DisplayIngredients( ingredients );
	
	return 0;
}