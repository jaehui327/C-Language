#include "stdafx.h"
#include "Circle.h"
#include <iostream>
using namespace std;
void Circle::draw() const {
	cout << "Circle" << endl; //���� �׸��� �Լ�
}

int Circle::being() const {
	return 2; //���� ������ ������ �˸��� �Լ�
}