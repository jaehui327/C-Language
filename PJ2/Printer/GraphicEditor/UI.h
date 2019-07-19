#pragma once
#ifndef UI_H
#define UI_H
class UI {
public:
	static int& selectMenu(); //메뉴 선택
	static int& createShape(); //생성할 도형 선택
	static int& deleteShape(); //삭제할 도형의 인덱스를 받아옴
	static void nothing(); //아무 도형도 없음을 알림
	static void finish(); //그래픽 에디터를 종료한다고 알림
	static void re(); //다시 입력하라고 알림
	static void statistic(int& l, int& c, int& r); //현재 존재하는 도형의 수를 알림
};
#endif // !UI_H