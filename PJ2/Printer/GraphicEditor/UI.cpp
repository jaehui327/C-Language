#include "stdafx.h"
#include "UI.h"
#include "iostream"
using namespace std;

int& UI::selectMenu() {
	int select; //�޴� ���� ����
	cout << "����:1, ����:2, ��κ���:3, �������:4, ����:5 >> ";
	cin >> select; //�޴� ����
	return select; //���õ� �޴� ��ȯ
}
int& UI::createShape() {
	int select; //���� ���� ����
	cout << "��:1, ��:2, �簢��:3 >> ";
	cin >> select; //���� ����
	return select; //���õ� ���� ��ȯ
}
int& UI::deleteShape() {
	int index; //�����ϰ��� �ϴ� ������ �ε��� ����
	cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
	cin >> index; //�ε��� ����
	return index; //�ε��� ��ȯ
}
void UI::nothing() {
	cout << "�׷��� ������ �����ϴ�" << endl; //���� �׷��� ������ ������ �˸�
}
void UI::finish() {
	cout << "���α׷��� �����մϴ�" << endl; //�׷��ȿ����͸� �����Ѵٰ� �˸�
}
void UI::re() {
	cout << "�ٽ� �Է����ּ���.." << endl; //�߸��� �Է��� �˸�
}
void UI::statistic(int& l, int& c, int& r) { //���� �����ϴ� ������ ���� ���� �˸��� �Լ�
	cout << "Line : " << l << endl; //���� ����
	cout << "Circle : " << c << endl; //���� ����
	cout << "Rect : " << r << endl; //�簢���� ����
}