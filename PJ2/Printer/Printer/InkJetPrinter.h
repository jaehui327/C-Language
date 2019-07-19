#pragma once
#ifndef INKJETPRINTER_H
#define INKJETPRINTER_H
#include "Printer.h"
class InkJetPrinter : public Printer {
	int availableInk; //��ũ �ܷ�
public:
	InkJetPrinter(std::string model, std::string manufacturer, int printedCount, int availableCount, int availableInk); //5���� �Ű������� ������ ������
	int& getavailableInk(); //��ũ �ܷ��� �����ϴ� �Լ�
	virtual void print(int& pages); //pages ��ŭ �μ��ϴ� �Լ�
	virtual void show() const; //���� �������� ��, ������, ���� �ܷ�, ��ũ �ܷ��� �����ִ� �Լ�
	virtual void add(int& add); //��ũ�� �������ִ� �Լ�
};
#endif // !INKJETPRINTER_H