//@Josh Cunningham	
//Lab 9: Polymorphism 
//CS-250-351
//09/30/2017
//lab9_Character.hpp

#ifndef _CHARACTER
#define _CHARACTER

#include <string>
using namespace std;

enum TurnChoice { ATTACK = 0, HEAL = 1 };

class ICharacter
{
public:
	void Setup(  const string&,  int, int );

	int GetHP();
	void SubtractDamage(int);
	string GetName();

	virtual TurnChoice GetChoice() = 0;

	int GetAttack();
	int GetHealing();

protected:
	int m_hp;
	int m_atk;
	int m_mag;
	string m_name;
};

class NPC : public ICharacter
{
public:
	virtual TurnChoice GetChoice();
};

class Player : public ICharacter
{
public:
	virtual TurnChoice GetChoice();
};

#endif
