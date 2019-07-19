#pragma once
#ifndef GRAPHICEDITOR_H
#define GRAPHICEDITOR_H
#include "Shape.h"
class GraphicEditor {
	Shape* p;
	Shape* pStart; //시작 도형
	Shape* pLast; //마지막 도형
public:
	void play(); //그래픽 편집기 실행 함수
};
#endif // !GRAPHICEDITOR_H