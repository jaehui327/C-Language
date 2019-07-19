#include "stdafx.h"
#include "Circle.h"
#include <iostream>
using namespace std;
void Circle::draw() const {
	cout << "Circle" << endl; //원을 그리는 함수
}

int Circle::being() const {
	return 2; //현재 도형이 원임을 알리는 함수
}