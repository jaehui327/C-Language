#include "stdafx.h"
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"
#include "GraphicEditor.h"
#include "UI.h"
#include <iostream>
using namespace std;

int main() {
	GraphicEditor g; //그래픽에디터 객체 생성
	cout << "그래픽 에디터입니다" << endl;
	g.play(); //그래픽에디터 실행
}