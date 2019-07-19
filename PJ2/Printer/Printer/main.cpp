#include "stdafx.h"
#include "Printer.h"
#include "InkJetPrinter.h"
#include "LaserPrinter.h"
#include "LinePrinter.h"
#include <iostream>
#include <string>
using namespace std;

void allshow(InkJetPrinter i, LaserPrinter l, LinePrinter li) { //모든 프린터의 정보를 보여주는 함수
	i.show(); //잉크젯프린터
	l.show(); //레이저프린터
	li.show(); //라인프린터
}

int main()
{
	InkJetPrinter* ink = new InkJetPrinter("Officejet V40", "HP", 0, 5, 10); //잉크젯프린터 동적 생성
	LaserPrinter* laser = new LaserPrinter("SCX-6x45", "삼성전자", 0, 3, 20); //레이저프린터 동적 생성
	LinePrinter* line = new LinePrinter("PT-D600", "Brother", 0, 9, 30); //라인프린터 동적 생성
	cout << "현재 작동중인 3 대의 프린터는 아래와 같다" << endl; //동적 생성한 프린터 보여주기
	cout << "잉크젯 : "; ink->show(); //잉크젯
	cout << "레이저 : "; laser->show(); //레이저
	cout << "라  인 : "; line->show(); //라인

	int select = 0, printer = 0, printpages = 0, adding = 0, addsth = 0; //각각 작업선택, 프린트선택, 인쇄할 페이지수, 보충할 개수, 보충할 물품을 나타내는 변수
	char keep = 'y'; //계속할 것인지 묻는 변수
	while (keep == 'y') { //계속한다고 대답한 경우에 반복
		cout << endl;
	selection: //작업선택을 하는 곳
		cout << "프린트(1), 보충(2) >> "; //작업선택
		cin >> select; 
		if (select == 1) { //프린트
			pr: //프린터와 인쇄 매수를 입력하는 곳
			cout << "프린터(1:잉크젯, 2:레이저, 3:라인)와 매수 입력>>"; //프린트선택
			cin >> printer >> printpages; //프린트와 인쇄 매수 입력
			if (printpages < 1) {
				cout << "다시 입력해주세요.. " << endl; //잘못된 인쇄 매수를 입력한 경우
				goto pr; //다시 인쇄 매수를 입력하는 곳으로 돌아감
			}
			switch (printer) { 
			case 1: //잉크젯 프린터
				if (printpages > ink->getavailableCount()) { //인쇄 잔량이 인쇄 매수보다 작으면
					cout << "용지가 부족하여 프린트할 수 없습니다" << endl; //프린트할 수 없음
				} else if (printpages > ink->getavailableInk()) { //잉크가 인쇄 매수보다 작으면 
					cout << "잉크가 부족하여 프린트할 수 없습니다" << endl; //프린트할 수 없음
				}
				else { //프린트 할 수 있는 경우
					ink->print(printpages); //잉크젯 프린터에서 printpages 만큼 프린트
				}
				allshow(*ink, *laser, *line);
				break;
			case 2: //레이저 프린터
				if (printpages > laser->getavailableCount()) { //인쇄 잔량이 인쇄 매수보다 작으면
					cout << "용지가 부족하여 프린트할 수 없습니다" << endl; //프린트할 수 없음
				} else if (laser->getavailableToner() < 1) { //토너가 없으면
					cout << "토너가 부족하여 프린트할 수 없습니다" << endl; //프린트할 수 없음
				}
				else { //프린트 할 수 있는 경우
					laser->print(printpages); //레이저 프린터에서 printpages 만큼 프린트
				}
				allshow(*ink, *laser, *line);
				break;
			case 3: //라인 프린터
				if (printpages > line->getavailableCount()) { //인쇄 잔량이 인쇄 매수보다 작으면
					cout << "용지가 부족하여 프린트할 수 없습니다" << endl; //프린트할 수 없음
				} else if (line->getavailableDrum() < 1) { //드럼이 없으면
					cout << "드럼이 부족하여 프린트할 수 없습니다" << endl; //프린트할 수 없음
				}
				else {
					line->print(printpages); //라인 프린터에서 printpages 만큼 프린트
				}
				allshow(*ink, *laser, *line);
				break;
			default:
				cout << "다시 입력해주세요.." << endl; //프린터를 잘못 선택한 경우
				goto pr; //다시 프린터를 선택하는 곳으로 돌아감
				break;
			}

		}
		else if (select == 2) { //보충
			ad1: // 보충할 물품과 보충할 갯수를 입력하는 곳
			cout << "보충할 물품(1:종이, 2:잉크, 3:토너, 4:드럼)과 보충할 갯수 입력>>";
			cin >> adding >> addsth; //보충할 물품과 보충할 개수 입력
			if (addsth < 1) {
				cout << "다시 입력해주세요.. " << endl; //보충할 개수가 잘못 입력된 경우
				goto ad1; //보충할 개수를 다시 입력하는 곳으로 돌아감
			}
			switch (adding) 
			{
			case 1: //종이 보충
				ad2: //프린터를 선택하는 곳
				cout << "종이를 보충할 프린터(1:잉크젯, 2:레이저, 3:라인) 입력>>"; 
				cin >> printer; 
				switch (printer)
				{
				case 1: //잉크젯 프린터
					ink->Printer::add(addsth); //잉크젯 프린터에 종이 보충
					allshow(*ink, *laser, *line);
					break;
				case 2: //레이저 프린터
					laser->Printer::add(addsth); //레이저 프린터에 종이 보충
					allshow(*ink, *laser, *line);
					break;
				case 3: //라인 프린터
					line->Printer::add(addsth); //라인 프린터에 종이 보충
					allshow(*ink, *laser, *line);
					break;
				default:
					cout << "다시 입력해주세요.." << endl; //프린터를 잘못 선택한 경우
					goto ad2; //다시 프린터를 선택하는 곳으로 돌아감
					break;
				}
				break;
			case 2: //잉크 보충
				ink->add(addsth); //잉크젯 프린터에 잉크 보충
				allshow(*ink, *laser, *line);
				break;
			case 3: //토너 보충
				laser->add(addsth); //레이저 프린터에 토너 보충
				allshow(*ink, *laser, *line);
				break;
			case 4: //드럼 보충
				line->add(addsth); //라인 프린터에 드럼 보충
				allshow(*ink, *laser, *line);
				break;
			default:
				cout << "다시 입력해주세요.." << endl; //보충할 물품과 보충할 갯수를 잘못 입력한 경우
				goto ad1; //다시 입력하기 위해 돌아감
				break;
			}
		}
		else { 
			cout << "다시 입력해주세요.." << endl; //작업 선택을 잘못한 경우
			goto selection; //작업 선택 하는 곳으로 돌아감
		}

		conti: //작업을 계속 할 것인지 선택하는 곳
		cout << "계속 하시겠습니까?(y/n)>>"; 
		cin >> keep; //keep이 'y'라면 while문을 빠져나오지 않고 계속 실행, 'n'이라면 while문을 벗어남
		if (keep != 'y' && keep != 'n') { //keep이 잘못 입력된 경우 
			cout << "다시 입력해주세요.." << endl;
			goto conti; //다시 작업을 계속 할 것인지 묻는 곳으로 돌아감
		}
	}

	delete ink; //잉크젯 프린터 반환
	delete laser; //레이터 프린터 반환
	delete line; //라인 프린터 반환
	return 0;
}