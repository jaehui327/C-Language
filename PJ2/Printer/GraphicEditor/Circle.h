#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
class Circle : public Shape {
protected:
	virtual void draw() const; //원을 그리는 함수
public:
	virtual int being() const; //현재 도형이 원임을 알리는 함수
};

#endif // !CIRCLE_H