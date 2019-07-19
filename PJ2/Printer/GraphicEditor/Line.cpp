#include "stdafx.h"
#include "Line.h"
#include <iostream>
using namespace std;

void Line::draw() const {
	cout << "Line" << endl; //선을 그리는 함수
}
int Line::being() const {
	return 1; //현재 도형이 선임을 알림
}