#pragma once
#ifndef UI_H
#define UI_H
class UI {
public:
	static int& selectMenu(); //�޴� ����
	static int& createShape(); //������ ���� ����
	static int& deleteShape(); //������ ������ �ε����� �޾ƿ�
	static void nothing(); //�ƹ� ������ ������ �˸�
	static void finish(); //�׷��� �����͸� �����Ѵٰ� �˸�
	static void re(); //�ٽ� �Է��϶�� �˸�
	static void statistic(int& l, int& c, int& r); //���� �����ϴ� ������ ���� �˸�
};
#endif // !UI_H