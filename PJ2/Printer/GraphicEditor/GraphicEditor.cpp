#include "stdafx.h"
#include "GraphicEditor.h"
#include "Shape.h"
#include "Line.h"
#include "Circle.h"
#include "Rect.h"
#include "UI.h"
#include <iostream>
using namespace std;

void GraphicEditor::play() {
	pStart = NULL; //첫 도형
	pLast = NULL; //마지막 도형
	int shapeNumber = 0; //도형의 총 개수
	int menu = 0, shape = 0, index = 0; //각각 메뉴선택, 도형선택, 삭제하고자 하는 인덱스를 나타내는 변수
	int l = 0, c = 0, r = 0; //선의 개수, 원의 개수, 사각형의 개수를 저장하는 변수
	int whatShape = 0; //도형의 모양을 저장하는 변수
	while (1) {
		int i = 0;
	select: //메뉴선택이 올바르지 않을 때 돌아오는 곳
		menu = UI::selectMenu(); //메뉴 선택
		switch (menu)
		{
		case 1: //삽입
		selectshape: //도형 선택이 올바르지 않을 때 돌아오는 곳
			shape = UI::createShape(); // 도형 선택
			if (pStart == NULL) { //첫 도형일 때
				switch (shape)
				{
				case 1:
					pStart = new Line(); //선 생성
					l++; //선 개수 +1
					break;
				case 2:
					pStart = new Circle(); //원 생성
					c++; //원 개수 +1
					break;
				case 3:
					pStart = new Rect(); // 사각형 생성
					r++; // 사각형 개수 +1
					break;
				default:
					UI::re(); //도형이 잘못 선택됨을 알림
					goto selectshape; //도형 선택 장소로 돌아감
					break;
				}
				pLast = pStart; //첫 도형이므로, pLast는 pStart와 같음
			}
			else {
				switch (shape) //맨 뒤에 도형을 이어붙임
				{
				case 1:
					pLast = pLast->add(new Line); //마지막 도형으로 선 생성
					l++; //선 개수 +1
					break;
				case 2:
					pLast = pLast->add(new Circle); //마지막 도형으로 원 생성
					c++; //원 개수 +1
					break;
				case 3:
					pLast = pLast->add(new Rect); //마지막 도형으로 사각형 생성
					r++; //사각형 개수 +1
					break;
				default:
					UI::re(); //도형이 잘못 선택됨을 알림
					goto selectshape; //도형 선택 장소로 돌아감
					break;
				}
			}
			shapeNumber++; //전체 도형의 개수 +1
			break;
		case 2: //삭제
			if (pLast == NULL) { //생성된 도형이 없을 경우
				UI::nothing(); //도형이 없다고 알림
				break;
			}
		in: //잘못된 인덱스를 입력했을 때 돌아오는 곳
			index = UI::deleteShape(); //삭제하고자 하는 도형의 인덱스 선택
			if (index == 0) { //맨 앞의 도형을 삭제하고자 할 때
				whatShape = pStart->being();
				switch (whatShape) { //삭제할 도형이 어떤 모양인지 탐색
				case 1: l--; break; //선 삭제, 선 개수 -1
				case 2: c--; break; //원 삭제, 원 개수 -1
				case 3: r--; break; //사각형 삭제, 사각형 개수 -1
				}
				pStart = pStart->getNext(); //시작 도형을 두번째 도형으로 설정
				shapeNumber--; //전체 도형의 개수 -1
			}
			else if (0 < index < shapeNumber) {
				p = NULL;
				Shape* del = pStart; //삭제하고자 하는 도형
				for (i = 0; i < index; i++) { //del을 삭제하고자 하는 도형, p를 그 이전 도형으로 설정하는 작업
					p = del;
					del = del->getNext();
				}
				whatShape = del->being();
				switch (whatShape) { //삭제할 도형이 어떤 모양인지 탐색
				case 1: l--; break; //선 삭제, 선 개수 -1
				case 2: c--; break; //원 삭제, 원 개수 -1
				case 3: r--; break; //사각형 삭제, 사각형 개수 -1
				}
				p->setNext(del); //p의 다음 도형을 삭제할 도형의 다음 도형으로 설정
				delete del; //del 삭제
				shapeNumber--; //전체 도형의 개수 -1

			}
			else {
				UI::re(); //인덱스가 잘못 입력되었다고 알림
				goto in; //다시 인덱스를 입력하는 곳으로 돌아감
			}
			break;
		case 3: //모두보기
			p = pStart; //p를 시작 도형으로 설정
			while (p != NULL) { //p가 NULL이 될 때까지 반복
				cout << i << ": "; //인덱스
				p->paint(); //도형 그리기
				p = p->getNext(); //p를 다음 도형으로 설정
				i++; //인덱스 증가
			}
			break;
		case 4://통계정보
			UI::statistic(l, c, r); //현재 존재하는 도형의 정보를 알림
			break;
		case 5://종료
			UI::finish(); //그래픽 편집기 종료를 알림
			return; //그래픽 편집기 종료
		default:
			UI::re(); //메뉴 선택이 잘못됨을 알림
			goto select; //메뉴 선택하는 곳으로 돌아감
			break;
		}
	}
}