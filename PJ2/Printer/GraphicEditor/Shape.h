#pragma once
#ifndef SHAPE_H
#define SHAPE_H
class Shape {
	Shape* next;
protected:
	virtual void draw() const = 0; //도형을 그리는 함수, 기본 클래스에서 순수 가상 함수로 구현됨
public:
	Shape();
	virtual ~Shape() { }
	void paint() const; //도형을 그리는 draw()를 호출하는 함수, draw()가 protected이기 때문에 public한 함수로 외부에서 사용 가능
	Shape* add(Shape* p); //현재 도형 뒤에 p 도형을 생성
	Shape* getNext(); //다음 도형을 가져오는 함수
	void setNext(Shape* p); //다음 도형을 설정하는 함수
	virtual int being() const = 0; //현재 도형이 무엇인지 알리는 함수, 기본 클래스에서 순수 가상 함수로 구현됨
};

#endif // !SHAPE_H