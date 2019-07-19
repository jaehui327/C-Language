#include "stdafx.h"
#include "Printer.h"
#include <iostream>
#include <string>
using namespace std;

Printer::Printer(string model, string manufacturer, int printedCount, int availableCount) {
	this->model = model; this->manufacturer = manufacturer; this->printedCount = printedCount; this->availableCount = availableCount; //��, ������, �μ� �ܷ� ����
}
int& Printer::getavailableCount() {
	return availableCount; //�μ� �ܷ��� ��ȯ�ϴ� �Լ�
}
void Printer::print(int& pages) {
	printedCount += pages; //�μ� �ż� + pages
	availableCount -= pages; //�μ� �ܷ� - pages
	cout << "����Ʈ�Ͽ����ϴ�." << endl;
}
void Printer::show() const {
	cout << model << " ," << manufacturer << " ," << "�� �μ� �ż� : " << printedCount << " ,���� ���� "  << availableCount << "�� ,"; //��, ������, �� �μ� �ż�, �μ� �ܷ��� ������
}
void Printer::add(int& add) {
	availableCount += add; //�μ� �ܷ� ����
	cout << "���̸� " << add << "�� �����Ͽ����ϴ�" << endl;
}