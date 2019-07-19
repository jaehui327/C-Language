#include "stdafx.h"
#include "LinePrinter.h"
#include "Printer.h"
#include <iostream>
#include <string>
using namespace std;

LinePrinter::LinePrinter(string model, string manufacturer, int printedCount, int availableCount, int availableDrum) : Printer(model, manufacturer, printedCount, availableCount) {
	this->availableDrum = availableDrum; //모델, 제조사, 총 인쇄 매수, 인쇄 잔량은 Printer 클래스의 생성자로 넘기고, 드럼 잔량 설정
}
int& LinePrinter::getavailableDrum() {
	return availableDrum; //드럼 잔량을 반환
}
void LinePrinter::print(int& pages) {
	Printer::print(pages); //pages 만큼 프린트하는 함수
	availableDrum--; //드럼 잔량 -1
}
void LinePrinter::show() const {
	Printer::show(); //모델, 제조사, 인쇄 잔량을 보여줌
	cout << "남은드럼 " << availableDrum << endl; //드럼 잔량을 보여줌
}
void LinePrinter::add(int& add) {
	availableDrum += add; // 드럼 보충
	cout << "드럼을 " << add << "개 보충하였습니다" << endl;
}