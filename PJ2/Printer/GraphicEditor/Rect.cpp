#include "stdafx.h"
#include "Rect.h"
#include <iostream>
using namespace std;

void Rect::draw() const {
	cout << "Rectangle" << endl; //사각형을 그리는 함수
}
int Rect::being() const {
	return 3; //현재 도형이 사각형임을 알리는 함수
}