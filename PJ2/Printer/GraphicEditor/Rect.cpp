#include "stdafx.h"
#include "Rect.h"
#include <iostream>
using namespace std;

void Rect::draw() const {
	cout << "Rectangle" << endl; //�簢���� �׸��� �Լ�
}
int Rect::being() const {
	return 3; //���� ������ �簢������ �˸��� �Լ�
}