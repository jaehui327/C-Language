#pragma once
#ifndef SHAPE_H
#define SHAPE_H
class Shape {
	Shape* next;
protected:
	virtual void draw() const = 0; //������ �׸��� �Լ�, �⺻ Ŭ�������� ���� ���� �Լ��� ������
public:
	Shape();
	virtual ~Shape() { }
	void paint() const; //������ �׸��� draw()�� ȣ���ϴ� �Լ�, draw()�� protected�̱� ������ public�� �Լ��� �ܺο��� ��� ����
	Shape* add(Shape* p); //���� ���� �ڿ� p ������ ����
	Shape* getNext(); //���� ������ �������� �Լ�
	void setNext(Shape* p); //���� ������ �����ϴ� �Լ�
	virtual int being() const = 0; //���� ������ �������� �˸��� �Լ�, �⺻ Ŭ�������� ���� ���� �Լ��� ������
};

#endif // !SHAPE_H