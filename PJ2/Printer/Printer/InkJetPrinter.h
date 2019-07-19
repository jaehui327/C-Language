#pragma once
#ifndef INKJETPRINTER_H
#define INKJETPRINTER_H
#include "Printer.h"
class InkJetPrinter : public Printer {
	int availableInk; //잉크 잔량
public:
	InkJetPrinter(std::string model, std::string manufacturer, int printedCount, int availableCount, int availableInk); //5개의 매개변수를 가지는 생성자
	int& getavailableInk(); //잉크 잔량을 리턴하는 함수
	virtual void print(int& pages); //pages 만큼 인쇄하는 함수
	virtual void show() const; //현재 프린터의 모델, 제조사, 종이 잔량, 잉크 잔량을 보여주는 함수
	virtual void add(int& add); //잉크를 보충해주는 함수
};
#endif // !INKJETPRINTER_H