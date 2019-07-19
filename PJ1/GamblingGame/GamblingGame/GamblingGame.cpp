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
	cout << "첫번째 선수 이름>>";
	cin >> name;
	p[0].setPlayer(name);
	cout << "두번째 선수 이름>>";
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
			cout << p[i].getPlayer() << "님 승리!!" << endl;
				break;
		}
		else {
			cout << "아쉽군요!" << endl;
			i++;
		}
	}
}
int main()
{
	cout << "***** 갬블링 게임을 시작합니다. *****"<< endl;
	GamblingGame gb(2);
	gb.playgame();
	return 0;
}