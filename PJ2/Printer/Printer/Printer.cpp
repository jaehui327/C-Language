#include "stdafx.h"
#include "Printer.h"
#include <iostream>
#include <string>
using namespace std;

Printer::Printer(string model, string manufacturer, int printedCount, int availableCount) {
	this->model = model; this->manufacturer = manufacturer; this->printedCount = printedCount; this->availableCount = availableCount; //¸ğµ¨, Á¦Á¶»ç, ÀÎ¼â ÀÜ·® ¼³Á¤
}
int& Printer::getavailableCount() {
	return availableCount; //ÀÎ¼â ÀÜ·®À» ¹İÈ¯ÇÏ´Â ÇÔ¼ö
}
void Printer::print(int& pages) {
	printedCount += pages; //ÀÎ¼â ¸Å¼ö + pages
	availableCount -= pages; //ÀÎ¼â ÀÜ·® - pages
	cout << "ÇÁ¸°Æ®ÇÏ¿´½À´Ï´Ù." << endl;
}
void Printer::show() const {
	cout << model << " ," << manufacturer << " ," << "ÃÑ ÀÎ¼â ¸Å¼ö : " << printedCount << " ,³²Àº Á¾ÀÌ "  << availableCount << "Àå ,"; //¸ğµ¨, Á¦Á¶»ç, ÃÑ ÀÎ¼â ¸Å¼ö, ÀÎ¼â ÀÜ·®À» º¸¿©ÁÜ
}
void Printer::add(int& add) {
	availableCount += add; //ÀÎ¼â ÀÜ·® º¸Ãæ
	cout << "Á¾ÀÌ¸¦ " << add << "Àå º¸ÃæÇÏ¿´½À´Ï´Ù" << endl;
}