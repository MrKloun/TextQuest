#include "Base.h"

string name()
{
	int a = Rand(1, 7);
	if (a == 1)
		return "Jon";
	else if (a == 2)
		return "Rex";
	else if (a == 3)
		return "Kolin";
	else if (a == 4)
		return "Max";
	else if (a == 5)
		return "Kirill";
	else if (a == 6)
		return "Liker";
	else if (a == 7)
		return "Ron";
	else 
		return "Keyt";
}

string getMonT(Mon mon)
{
	if (mon.type == MonT::GOBLIN)
		return "Goblin";
	else if (mon.type == MonT::SKELETON)
		return "Skelet";
	else if (mon.type == MonT::ORC)
		return "Orc";
	else if (mon.type == MonT::OGR)
		return "Ogr";
	else if (mon.type == MonT::SLIME)
		return "Slime";
	return "Unknow";
}

void pMon(Mon mon, int HP, int Attack)
{
	cout << "\n" << getMonT(mon) << " " << name() << "\n HP:\t " << HP << "\n Attack: " << Attack << endl;
}

int Attack(Mon mon)
{
	int R = Rand(mon.prob - 9, mon.prob + 9);
	if (R < 0)
		R = 0;
	return R;
}

int HP(Mon mon)
{
	return Rand(mon.healt - 9, mon.healt + 9);
}

int Rand(int min, int max)
{
	random_device rd;
	mt19937 mersenne(rd());
	return ((mersenne() % (max - min + 1)) + min);
}
int Battle(Mon mon, int SwAt, int PHP, int Ag, int MonAt, int MonHP)
{
	int dey;
	int dmg;
	int Mdmg;
	int dodge;
	while (true)
	{
		if (MonHP <= 0)
		{
			cout << "\nVictory!\n";
			Lin();
			return PHP;
		}
		if (PHP <= 0)
		{
			cout << "\nDefeat.\nGame over\n\n";
			Lin();
			return PHP;
		}

		cout << "\nAttack(1) îr dodge(2)?\n";
		
		cin >> dey;
		lin();
		
		if (dey == 1)
		{
			dmg = Rand(SwAt - 10, SwAt + 10);
			if (dmg >= SwAt + 7)
			{
				cout << "\nCritical hit " << SwAt * 2 << " DMG!\n";
				dmg = SwAt * 2;
			}
			else
				cout << "\nYou hits on " << dmg << " DMG!\n";
			lin();
			MonHP -= dmg;

			Mdmg = Rand(MonAt - 10, MonAt + 10);
			cout << "\nMonster hits on " << Mdmg << " DMG!\n";
			Lin();
			PHP -= Mdmg;
		}

		else if (dey == 2)
		{
			dodge = Rand(1, 100);
			if (dodge > MonAt - Ag)
			{
				cout << "\nBeautiful dodge!\nHP + " << dodge - MonAt + Ag << "\n";
				PHP += dodge - MonAt + Ag;
			}
			else if (dodge == MonAt - Ag)
				cout << "\nGood dodge!\n";
			else
			{
				cout << "\nfailed dodge\nHP - " << MonAt - Ag - dodge << "\n";
				PHP -= MonAt - Ag - dodge;
			}
			Lin();
		}
		if (PHP > 100)
			PHP = 100;
		cout << "\nYou:\tHP " << PHP << "\n\tAttack " << SwAt << "\n\nMonster:\tHP " << MonHP << "\n\t\tAttack " << MonAt << endl;
		Lin();
	}
}

void lin()
{
	for (int i = 0; i < 80; i++)
		cout << "_";
}

void Lin()
{
	for (int i = 0; i < 80; i++)
		cout << "=";
}
