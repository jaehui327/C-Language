#pragma once
#ifndef GRAPHICEDITOR_H
#define GRAPHICEDITOR_H
#include "Shape.h"
class GraphicEditor {
	Shape* p;
	Shape* pStart; //���� ����
	Shape* pLast; //������ ����
public:
	void play(); //�׷��� ������ ���� �Լ�
};
#endif // !GRAPHICEDITOR_H