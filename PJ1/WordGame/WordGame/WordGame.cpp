#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Player {
	string name;
public:
	Player();
	string getPlayer();
	void setPlayer(string name);
};
Player::Player() {
	name = "";
}
string Player::getPlayer() {
	return name;
}
void Player::setPlayer(string name) {
	this->name = name;
}

class WordGame {
	Player *p;
	int number;
public:
	WordGame(int n);
	~WordGame();
	void playGame(int n);
};

WordGame::WordGame(int n) {
	p = new Player[n];
	string name;
	number = n;
	for (int i = 0; i < n; i++) {
		cout << "참가자의 이름을 입력하세요. 빈칸 없이>>";
		cin >> name;
		p[i].setPlayer(name);
	}
}

WordGame::~WordGame() {
	delete[] p;
}

void WordGame::playGame(int n) {
	int i = 0;
	int last, start;
	string pre = "아버지";
	string pos;
	while (true)
	{
		i = i % n;
		last = pre.size();
		cout << p[i].getPlayer() << ">>";
		cin >> pos;
		if (pre.at(last - 2) == pos.at(0) && pre.at(last - 1) == pos.at(1)) {
			pre = pos;
			i++;
		}
		else {
			cout << p[i].getPlayer() << "이(가) 졌습니다." << endl;
			break;
		}
	}
}

int main()
{
	int n;
	cout << "끝말 잇기 게임을 시작합니다." << endl;
	cout << "게임에 참가하는 인원은 몇명입니까? ";
	cin >> n;
	WordGame wg(n);
	cout << "시작하는 단어는 아버지입니다." << endl;
	wg.playGame(n);
	return 0;
}

