#pragma once
#ifndef LINEPRINTER_H
#define LINEPRINTER_H
#include "Printer.h"
class LinePrinter : public Printer {
	int availableDrum; //�巳 �ܷ�
public:
	LinePrinter(std::string model, std::string manufacturer, int printedCount, int availableCount, int availableDrum); //5���� �Ű������� ������ ������
	int& getavailableDrum(); //�巳 �ܷ��� �����ϴ� �Լ� 
	virtual void print(int& pages); //pages ��ŭ �μ��ϴ� �Լ�
	virtual void show() const; //���� �������� ��, ������, ���� �ܷ�, �巳 �ܷ��� �����ִ� �Լ�
	virtual void add(int& add); //�巳�� �������ִ� �Լ�
};
#endif // !LINEPRINTER_H