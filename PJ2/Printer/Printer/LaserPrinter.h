#pragma once
#ifndef LASERPRINTER_H
#define LASERPRINTER_H
#include "Printer.h"
class LaserPrinter : public Printer {
	int availableToner; //토너 잔량
public:
	LaserPrinter(std::string model, std::string manufacturer, int printedCount, int availableCount, int availableToner); //5개의 매개변수를 가지는 생성자
	int& getavailableToner(); //토너 잔량을 반환하는 함수
	virtual void print(int& pages); //pages 만큼 인쇄하는 함수
	virtual void show() const; //현재 프린터의 모델, 제조사, 종이 잔량, 토너 잔량을 보여주는 함수
	virtual void add(int& add); //토너를 보충해주는 함수
};
#endif // !LASERPRINTER_H