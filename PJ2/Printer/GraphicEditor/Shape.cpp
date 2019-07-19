#include "stdafx.h"
#include "Shape.h"
#include <iostream>
using namespace std;
Shape::Shape() {
	next = NULL; //���� ����
}

void Shape::paint() const { //������ �׸��� �Լ�
	draw(); //protected�� draw()�Լ��� ȣ����
}
Shape* Shape::add(Shape *p) {
	this->next = p; //���� ���� �ڿ� p ������ ����
	return p; //p�� ����
}
Shape* Shape::getNext() {
	return next; //���� ������ ��ȯ
}

void Shape::setNext(Shape* p) {
	this->next = p->next; //���� ������ �����ϴ� �Լ�
}