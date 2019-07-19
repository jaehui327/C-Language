#include "stdafx.h"
#include "InkJetPrinter.h"
#include "Printer.h"
#include <iostream>
#include <string>
using namespace std;

InkJetPrinter::InkJetPrinter(string model, string manufacturer,int printedCount, int availableCount, int availableInk) : Printer(model, manufacturer, printedCount, availableCount) {
	this->availableInk = availableInk; //��, ������, �� �μ� �ż�, �μ� �ܷ��� Printer Ŭ������ �����ڷ� �ѱ��, ��ũ �ܷ� ����
}
int& InkJetPrinter::getavailableInk() {
	return availableInk; //��ũ �ܷ� ��ȯ
}
void InkJetPrinter::print(int& pages) {
	Printer::print(pages); //pages ��ŭ ����Ʈ�ϴ� �Լ�
	availableInk -= pages; //��ũ �ܷ� - pages
}
void InkJetPrinter::show() const {
	Printer::show(); //��, ������, �μ� �ܷ��� ������
	cout << "���� ��ũ " << availableInk << endl; //��ũ �ܷ��� ������
}
void InkJetPrinter::add(int& add) {
	availableInk += add; //��ũ �ܷ� ����
	cout << "��ũ�� " << add << "�� �����Ͽ����ϴ�" << endl;
}