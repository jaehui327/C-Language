#include "stdafx.h"
#include "LaserPrinter.h"
#include "Printer.h"
#include <iostream>
#include <string>
using namespace std;

LaserPrinter::LaserPrinter(string model, string manufacturer, int printedCount,int availableCount, int availableToner) :Printer(model, manufacturer, printedCount, availableCount) {
	this->availableToner = availableToner; //모델, 제조사, 총 인쇄 매수, 인쇄 잔량은 Printer 클래스의 생성자로 넘기고, 토너 잔량 설정
}
int& LaserPrinter::getavailableToner() {
	return availableToner; //토너 잔량 반환
}
void LaserPrinter::print(int& pages) {
	Printer::print(pages); //pages 만큼 프린트하는 함수
	availableToner--; //토너 잔량 -1
}
void LaserPrinter::show() const {
	Printer::show(); //모델, 제조사, 인쇄 잔량을 보여줌
	cout << "남은토너 " << availableToner << endl; //토너 잔량을 보여줌
}
void LaserPrinter::add(int& add) {
	availableToner += add; //토너를 보충
	cout << "토너를 " << add << "개 보충하였습니다" << endl;
}