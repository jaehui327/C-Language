#include "stdafx.h"
#include "Line.h"
#include <iostream>
using namespace std;

void Line::draw() const {
	cout << "Line" << endl; //���� �׸��� �Լ�
}
int Line::being() const {
	return 1; //���� ������ ������ �˸�
}