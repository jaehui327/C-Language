#include "stdafx.h"
#include "LinePrinter.h"
#include "Printer.h"
#include <iostream>
#include <string>
using namespace std;

LinePrinter::LinePrinter(string model, string manufacturer, int printedCount, int availableCount, int availableDrum) : Printer(model, manufacturer, printedCount, availableCount) {
	this->availableDrum = availableDrum; //��, ������, �� �μ� �ż�, �μ� �ܷ��� Printer Ŭ������ �����ڷ� �ѱ��, �巳 �ܷ� ����
}
int& LinePrinter::getavailableDrum() {
	return availableDrum; //�巳 �ܷ��� ��ȯ
}
void LinePrinter::print(int& pages) {
	Printer::print(pages); //pages ��ŭ ����Ʈ�ϴ� �Լ�
	availableDrum--; //�巳 �ܷ� -1
}
void LinePrinter::show() const {
	Printer::show(); //��, ������, �μ� �ܷ��� ������
	cout << "�����巳 " << availableDrum << endl; //�巳 �ܷ��� ������
}
void LinePrinter::add(int& add) {
	availableDrum += add; // �巳 ����
	cout << "�巳�� " << add << "�� �����Ͽ����ϴ�" << endl;
}