#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
class Circle : public Shape {
protected:
	virtual void draw() const; //���� �׸��� �Լ�
public:
	virtual int being() const; //���� ������ ������ �˸��� �Լ�
};

#endif // !CIRCLE_H