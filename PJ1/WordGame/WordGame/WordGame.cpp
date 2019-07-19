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
		cout << "�������� �̸��� �Է��ϼ���. ��ĭ ����>>";
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
	string pre = "�ƹ���";
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
			cout << p[i].getPlayer() << "��(��) �����ϴ�." << endl;
			break;
		}
	}
}

int main()
{
	int n;
	cout << "���� �ձ� ������ �����մϴ�." << endl;
	cout << "���ӿ� �����ϴ� �ο��� ����Դϱ�? ";
	cin >> n;
	WordGame wg(n);
	cout << "�����ϴ� �ܾ�� �ƹ����Դϴ�." << endl;
	wg.playGame(n);
	return 0;
}

