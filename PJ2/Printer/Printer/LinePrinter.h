#pragma once
#ifndef LINEPRINTER_H
#define LINEPRINTER_H
#include "Printer.h"
class LinePrinter : public Printer {
	int availableDrum; //드럼 잔량
public:
	LinePrinter(std::string model, std::string manufacturer, int printedCount, int availableCount, int availableDrum); //5개의 매개변수를 가지는 생성자
	int& getavailableDrum(); //드럼 잔량을 리턴하는 함수 
	virtual void print(int& pages); //pages 만큼 인쇄하는 함수
	virtual void show() const; //현재 프린터의 모델, 제조사, 종이 잔량, 드럼 잔량을 보여주는 함수
	virtual void add(int& add); //드럼을 보충해주는 함수
};
#endif // !LINEPRINTER_H