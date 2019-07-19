#include "stdafx.h"
#include "Shape.h"
#include <iostream>
using namespace std;
Shape::Shape() {
	next = NULL; //다음 도형
}

void Shape::paint() const { //도형을 그리는 함수
	draw(); //protected한 draw()함수를 호출함
}
Shape* Shape::add(Shape *p) {
	this->next = p; //현재 도형 뒤에 p 도형을 생성
	return p; //p를 리턴
}
Shape* Shape::getNext() {
	return next; //다음 도형을 반환
}

void Shape::setNext(Shape* p) {
	this->next = p->next; //다음 도형을 설정하는 함수
}