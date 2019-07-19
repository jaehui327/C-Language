#include "stdafx.h"
#include "InkJetPrinter.h"
#include "Printer.h"
#include <iostream>
#include <string>
using namespace std;

InkJetPrinter::InkJetPrinter(string model, string manufacturer,int printedCount, int availableCount, int availableInk) : Printer(model, manufacturer, printedCount, availableCount) {
	this->availableInk = availableInk; //모델, 제조사, 총 인쇄 매수, 인쇄 잔량은 Printer 클래스의 생성자로 넘기고, 잉크 잔량 설정
}
int& InkJetPrinter::getavailableInk() {
	return availableInk; //잉크 잔량 반환
}
void InkJetPrinter::print(int& pages) {
	Printer::print(pages); //pages 만큼 프린트하는 함수
	availableInk -= pages; //잉크 잔량 - pages
}
void InkJetPrinter::show() const {
	Printer::show(); //모델, 제조사, 인쇄 잔량을 보여줌
	cout << "남은 잉크 " << availableInk << endl; //잉크 잔량을 보여줌
}
void InkJetPrinter::add(int& add) {
	availableInk += add; //잉크 잔량 보충
	cout << "잉크를 " << add << "개 보충하였습니다" << endl;
}