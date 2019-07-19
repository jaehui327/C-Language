#pragma once
#ifndef LASERPRINTER_H
#define LASERPRINTER_H
#include "Printer.h"
class LaserPrinter : public Printer {
	int availableToner; //��� �ܷ�
public:
	LaserPrinter(std::string model, std::string manufacturer, int printedCount, int availableCount, int availableToner); //5���� �Ű������� ������ ������
	int& getavailableToner(); //��� �ܷ��� ��ȯ�ϴ� �Լ�
	virtual void print(int& pages); //pages ��ŭ �μ��ϴ� �Լ�
	virtual void show() const; //���� �������� ��, ������, ���� �ܷ�, ��� �ܷ��� �����ִ� �Լ�
	virtual void add(int& add); //��ʸ� �������ִ� �Լ�
};
#endif // !LASERPRINTER_H