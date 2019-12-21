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

		cout << "\nAttack(1) dodge(2)?\n";
		
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
			if (Mdmg < 0)
				Mdmg = 1;
			cout << "\nMonster hits on " << Mdmg << " DMG!\n";
			Lin();
			PHP -= Mdmg;
		}

		else if (dey == 2)
		{
			dodge = Rand(1, 100);
			if (dodge > MonAt - Ag)			
			{
				int K = dodge - MonAt + Ag;
				TablStatus("Beautiful dodge", "HP + ", -1000, K);;
				PHP += K;
			}
			else if (dodge == MonAt - Ag)
				cout << "\nGood dodge!\n";
			else
			{
				int K = MonAt - Ag - dodge;
				TablStatus("Failed dodge", "HP - ", -1000 , K);
				PHP -= K;
			}
			Lin();
		}
		if (PHP > 100)
			PHP = 100;
		cout << "\nYou:";
		TablStatus("HP = ", "Attack = ", PHP, SwAt);
		cout << "\nMonster:";
		TablStatus("HP = ", "Attack = ", MonHP, MonAt);
	}
}

void lin()
{
	for (int i = 0; i < 80; i++)
		cout << "_";
}

void Lin()
{
	const int W = 100;
	const char HorizontalLine = (char)205; //"═"
	for (int k = 0; k < W; k++)	cout << HorizontalLine; //for
}

void TablStatus(string a, string b, int c, int d)
{
	const char VerticalLine = (char)186; //"║"
	const char HorizontalLine = (char)205; //"═"
	const char TopLeftCorner = (char)201; //"╔"
	const char TopRightCorner = (char)187; //"╗"
	const char BottomLeftCorner = (char)200; //"╚"
	const char BottomRightCorner = (char)188; //"╝"
	const char BottomJunction = (char)203; //"╦"
	const char TopJunction = (char)202; //"╩"
	const int W = 30;

	// ╔══╦══╗
	cout << "\n" << TopLeftCorner;
	for (int i = 0; i < W; i++)	cout << HorizontalLine; //for
	cout << BottomJunction;

	for (int i = 0; i < W; i++) cout << HorizontalLine; //for
	
	cout << TopRightCorner << endl;

	// ║ a ║ b ║
	if (c == -1000 && d == -1000)
	{
		cout << VerticalLine << setw(W) << left << a
			<< VerticalLine << setw(W) << left << b
			<< VerticalLine << endl;
	}
	else if (c == -1000 && d != -1000)
	{
		cout << VerticalLine << setw(W) << left << a
			<< VerticalLine << setw(W/2) << left << b << setw(W / 2) << d
			<< VerticalLine << endl;
	}
	else if (c != -1000 && d == -1000)
	{
		cout << VerticalLine << setw(W/2) << left << a << setw(W / 2) << c
			<< VerticalLine << setw(W) << left << b 
			<< VerticalLine << endl;
	}
	else 
	{
		cout << VerticalLine << setw(W/2) << left << a << setw(W / 2) << c
			<< VerticalLine << setw(W/2) << left << b << setw(W / 2) << d
			<< VerticalLine << endl;
	}

	// ╚══╩══╝
	cout << BottomLeftCorner;

	for (int k = 0; k < W; k++)	cout << HorizontalLine; //for
	cout << TopJunction;

	for (int k = 0; k < W; k++)	cout << HorizontalLine; //for
	cout << BottomRightCorner << endl;
}
