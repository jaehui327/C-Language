#pragma once
#ifndef RECT_H
#define RECT_H
#include "Shape.h"
class Rect : public Shape {
protected:
	virtual void draw() const; //사각형을 그리는 함수
public:
	virtual int being() const; //현재 도형이 사각형임을 알리는 함수
};

#endif // !RECT_H