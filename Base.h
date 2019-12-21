#include <iostream>
#include <string>
#include <dos.h>
#include <random>

using namespace std;

struct Player
{
	int HP;
	int Attack;
	int Agility;
	int lvl;
};

struct Mon
{
	MonT type;
	int healt;
	int prob;
};

enum class MonT
{
	ORC,
	SKELETON,
	GOBLIN,
	OGR,
	SLIME
};

void pMon(Mon mon, int HP, int Attack);

string getMonT(Mon);

int Attack(Mon);

int Rand(int, int);

string name();

int HP(Mon mon);

int Battle(Mon mon, int SwAt, int PHP, int Ag, int MonAt, int MonHP);

void lin();

void Lin();

int XP(int a);
