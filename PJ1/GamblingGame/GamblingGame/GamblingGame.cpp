#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Player {
	string name;
public:
	string getPlayer();
	void setPlayer(string name);
};

string Player::getPlayer() {
	return name;
}
void Player::setPlayer(string name) {
	this->name = name;
}

class GamblingGame {
	Player *p;
	int number = 2;
public:
	GamblingGame(int n);
	~GamblingGame();
	void playgame();
};

GamblingGame::GamblingGame(int n) {
	p = new Player[n];
	int x;
	string name;
	cout << "ù��° ���� �̸�>>";
	cin >> name;
	p[0].setPlayer(name);
	cout << "�ι�° ���� �̸�>>";
	cin >> name;
	while ((x = getchar()) != '\n'&&x != EOF);
	p[1].setPlayer(name);
}
GamblingGame::~GamblingGame() {
	delete[] p;
}
void GamblingGame::playgame() {
	int a, b, c;
	int i = 0;
	string enter;
	int x;
	while (true)
	{
		i = i % number;
		cout << p[i].getPlayer() << ":<Enter>";
		while ((x = getchar()) != '\n'&&x != EOF);
		srand((unsigned)time(0));
		a = rand() % 3;
		b = rand() % 3;
		c = rand() % 3;
		cout << "                  " << a << "     " << b << "     " << c << "     ";
		if (a == b && a == c) {
			cout << p[i].getPlayer() << "�� �¸�!!" << endl;
				break;
		}
		else {
			cout << "�ƽ�����!" << endl;
			i++;
		}
	}
}
int main()
{
	cout << "***** ���� ������ �����մϴ�. *****"<< endl;
	GamblingGame gb(2);
	gb.playgame();
	return 0;
}