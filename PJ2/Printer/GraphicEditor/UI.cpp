#include "stdafx.h"
#include "UI.h"
#include "iostream"
using namespace std;

int& UI::selectMenu() {
	int select; //메뉴 선택 변수
	cout << "삽입:1, 삭제:2, 모두보기:3, 통계정보:4, 종료:5 >> ";
	cin >> select; //메뉴 선택
	return select; //선택된 메뉴 반환
}
int& UI::createShape() {
	int select; //도형 선택 변수
	cout << "선:1, 원:2, 사각형:3 >> ";
	cin >> select; //도형 선택
	return select; //선택된 도형 반환
}
int& UI::deleteShape() {
	int index; //삭제하고자 하는 도형의 인덱스 변수
	cout << "삭제하고자 하는 도형의 인덱스 >> ";
	cin >> index; //인덱스 선택
	return index; //인덱스 반환
}
void UI::nothing() {
	cout << "그려진 도형이 없습니다" << endl; //현재 그려진 도형이 없음을 알림
}
void UI::finish() {
	cout << "프로그램을 종료합니다" << endl; //그래픽에디터를 종료한다고 알림
}
void UI::re() {
	cout << "다시 입력해주세요.." << endl; //잘못된 입력을 알림
}
void UI::statistic(int& l, int& c, int& r) { //현재 존재하는 각각의 도형 수를 알리는 함수
	cout << "Line : " << l << endl; //선의 개수
	cout << "Circle : " << c << endl; //원의 개수
	cout << "Rect : " << r << endl; //사각형의 개수
}