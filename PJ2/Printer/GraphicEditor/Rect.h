#pragma once
#ifndef RECT_H
#define RECT_H
#include "Shape.h"
class Rect : public Shape {
protected:
	virtual void draw() const; //�簢���� �׸��� �Լ�
public:
	virtual int being() const; //���� ������ �簢������ �˸��� �Լ�
};

#endif // !RECT_H