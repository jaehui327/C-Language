#pragma once
#ifndef LINE_H
#define LINE_H
#include "Shape.h"
class Line : public Shape {
protected:
	virtual void draw() const; //선을 그리는 함수
public:
	virtual int being() const; //현재 도형이 선임을 알리는 함수
};

#endif // !LINE_H