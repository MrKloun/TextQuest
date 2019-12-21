#include "Base.h"

int main()
{
	setlocale(LC_ALL, "RU"); // вчключение руссого языка
	system("color F0"); // смена цвета консоли

	Mon monster;
	Mon Goblin = { MonT::GOBLIN, 40, 30 };
	Mon Orc = { MonT::ORC, 100, 90 };
	Mon Skelet = { MonT::SKELETON, 50, 60 };
	Mon Ogr = { MonT::OGR, 110, 93 };
	Mon Slime = { MonT::SLIME, 20, 10 };

	Player P = { 50, 13, 10, 1 };

	int MonAt;
	int MonHP;

	int r;
	int xp(0);

	int dey;
	cout << "Your stats:\nHP: " << P.HP << "\tAttack: " << P.Attack << "\t Agility: " << P.Agility<< "\tlvl: " << P.lvl << endl;
	while (true) // создание события определенной вероятности
	{
		cout << endl;

		r = Rand(1, 100);

		if (r >= Ogr.prob && P.lvl >= 10)
			monster = Orc;
		else if (r >= Orc.prob && P.lvl >= 10)
			monster = Orc;
		else if (r >= Skelet.prob && P.lvl >= 5)
			monster = Skelet;
		else if (r >= Goblin.prob && P.lvl >= 2)
			monster = Goblin;
		else if (r >= Slime.prob)
			monster = Slime;
		else
		{
			cout << "\nThere are no monsters here!\n";
			cin.ignore();
			continue;
		}
		lin();
		MonAt = Attack(monster);
		MonHP = HP(monster);
		pMon(monster, MonHP, MonAt);
		lin();
		cout << "\nBattle(1) or Run(2)?\n";
		cin >> dey;
		//cin.ignore();

		if (dey == 2)
		{
			if (Rand(1, 100) <= monster.prob - P.Agility)
			{
				cout << "\nЕhe escape failed.\n";
				cout << "\nGame over\n\n";
				system("pause");
				return 0;
			}
		}
		else if (dey == 1)
		{
			P.HP = Battle(monster, P.Attack, P.HP, P.Agility, MonAt, MonHP);
			if (P.HP <= 0)
			{
				system("pause");
				return 0;
			}
			else
			{
				int Xp = Rand(monster.prob - 10, monster.prob + 10);
				if (Xp <= 0)
					Xp = 1;
				xp += Xp;
				cout << "\nxp + " << Xp << endl;
				if (xp >= 100)
				{
					Lin();
					P.lvl += xp / 100;
					cout << "\nLVL UP!\n";
					cout << "\nAttack + " << (xp / 100) * 5 << endl;
					P.Attack += 5;
					xp /= 100;
					cout << "Your lvl: " << P.lvl << endl;
				}
				Lin();
			}
		}
	}
	return 0;
}