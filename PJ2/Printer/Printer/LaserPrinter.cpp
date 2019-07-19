#include "stdafx.h"
#include "LaserPrinter.h"
#include "Printer.h"
#include <iostream>
#include <string>
using namespace std;

LaserPrinter::LaserPrinter(string model, string manufacturer, int printedCount,int availableCount, int availableToner) :Printer(model, manufacturer, printedCount, availableCount) {
	this->availableToner = availableToner; //��, ������, �� �μ� �ż�, �μ� �ܷ��� Printer Ŭ������ �����ڷ� �ѱ��, ��� �ܷ� ����
}
int& LaserPrinter::getavailableToner() {
	return availableToner; //��� �ܷ� ��ȯ
}
void LaserPrinter::print(int& pages) {
	Printer::print(pages); //pages ��ŭ ����Ʈ�ϴ� �Լ�
	availableToner--; //��� �ܷ� -1
}
void LaserPrinter::show() const {
	Printer::show(); //��, ������, �μ� �ܷ��� ������
	cout << "������� " << availableToner << endl; //��� �ܷ��� ������
}
void LaserPrinter::add(int& add) {
	availableToner += add; //��ʸ� ����
	cout << "��ʸ� " << add << "�� �����Ͽ����ϴ�" << endl;
}