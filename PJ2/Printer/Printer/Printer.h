#pragma once
#ifndef PRINTER_H
#define PRINTER_H
#include <string>
class Printer {
	std::string model; //�������� �𵨸�
	std::string manufacturer; //�������� ������
	int printedCount; //�μ� �ż�
	int availableCount; //�μ� ���� �ܷ�
public:
	Printer(std::string model, std::string manufacturer, int printedCount, int availableCount); //4���� �Ű������� ������ ������
	int& getavailableCount(); //���� �ܷ��� �����ϴ� �Լ�
	virtual void print(int& pages); //pages �� ��ŭ ����Ʈ�ϴ� �Լ�
	virtual void show() const; //���� �������� �𵨸�, ������, �μ� ���� �ܷ��� �����ִ� �Լ�
	virtual void add(int& add); //�μ� ���̸� �������ִ� �Լ�
};
#endif // !PRINTER_H