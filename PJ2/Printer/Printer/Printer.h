#pragma once
#ifndef PRINTER_H
#define PRINTER_H
#include <string>
class Printer {
	std::string model; //프린터의 모델명
	std::string manufacturer; //프린터의 제조사
	int printedCount; //인쇄 매수
	int availableCount; //인쇄 종이 잔량
public:
	Printer(std::string model, std::string manufacturer, int printedCount, int availableCount); //4개의 매개변수를 가지는 생성자
	int& getavailableCount(); //종이 잔량을 리턴하는 함수
	virtual void print(int& pages); //pages 수 만큼 프린트하는 함수
	virtual void show() const; //현재 프린터의 모델명, 제조사, 인쇄 종이 잔량을 보여주는 함수
	virtual void add(int& add); //인쇄 종이를 보충해주는 함수
};
#endif // !PRINTER_H