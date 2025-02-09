#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Nation {
	string nation; //나라 이름
	string capital; //수도 이름
public:
	void setNC(string& nation, string& capital) { this->nation = nation; this->capital = capital; } //나라와 수도를 설정하는 함수
	void setCapital(string& capital) { this->capital = capital; } //수도를 설정하는 함수
	const string getNation() { return nation; } //나라의 이름을 가져오는 함수
	const string getCapital() { return capital; } //수도의 이름을 가져오는 함수
};

class NationManager {
	vector<Nation> vec; //나라와 수도 이름을 짝지어 저장하는 벡터
public:
	void input(); //1. 정보 입력
	void changeCapital(); //2. 정보 수정
	void quiz(); //3. 퀴즈
	void play(); //나라의 수도 맞추기 게임을 진행하는 함수
};
void NationManager::input() { //1. 정보 입력
	string nameN = "", nameC = ""; //각각 나라 이름, 수도 이름
	Nation na; //Nation 클래스 객체 생성
	int x;
	while ((x = getchar()) != '\n'&&x != EOF); //입력 버퍼를 지움
	while (true) {
	inp: // 나라 이름을 다시 입력해야하는 경우 돌아오는 곳
		cout << "나라 이름을 입력하세요 (종료시 no 입력) >> ";
		getline(cin, nameN); //getline으로 나라 이름을 받아옴
		fflush(stdin); //입력 버퍼 지우기
		if (nameN == "no") { //"no"가 입력됐을 경우 
			if (vec.size() < 10) { //10개 미만으로 입력 된 경우
				cout << "10개 이상 입력해주세요. 현재 입력된 개수는 " << vec.size() << "개 입니다. " << endl;
				goto inp; // 다시 나라 이름 입력하는 곳으로 돌아감
			}
			cout << "현재 입력된 개수는 " << vec.size() << "개 입니다. 정보 입력을 종료합니다. " << endl;
			return; //입력된 개수를 알려주고 정보 입력 함수를 종료시킴
		}
		else {
			for (int i = 0; i < vec.size(); i++) { //벡터를 탐색해서
				if (nameN == vec[i].getNation()) {
					cout << "이미 입력된 나라입니다. 다시 입력해주세요.." << endl;
					goto inp; //이미 입력된 나라 이름이면 다시 나라 이름을 입력하는 곳으로 돌아감
				}
			}
			cout << "수도를 입력하세요 >> ";
			getline(cin, nameC);//getline으로 수도를 입력 받음
			na.setNC(nameN, nameC); //클래스 Nation에서 나라이름과 수도이름을 설정해줌
			vec.push_back(na); //벡터에 넣음
		}
	}
}
void NationManager::changeCapital() { //2. 정보 수정
	if (vec.size() == 0) { //아무것도 입력되지 않았을 때
		cout << "수정할 정보가 없습니다. 정보 수정을 종료합니다." << endl;
		return; //종료
	}
	string nameN = ""; //나라이름
	string nameC = ""; //수도이름
	int x;
	while ((x = getchar()) != '\n'&&x != EOF); //입력 버퍼 지우기
ch: //나라 이름이 목록에 없을 경우 돌아오는 곳
	cout << "수정할 나라 이름을 입력하세요 >> ";
	getline(cin, nameN); //나라 이름을 입력 받음
	for (auto& v : vec) { //벡터를 탐색
		if (v.getNation() == nameN) { //나라 이름이 목록에 있다면
			cout << "수정할 수도 이름 >> ";
			getline(cin, nameC); //수정할 수도 이름을 입력 받아서
			v.setCapital(nameC); //수도를 다시 설정해줌
			cout << "수정 완료. 나라 : " << v.getNation() << ", 수도 : " << v.getCapital() << endl; //수정 완료 후, 수정된 나라와 수도 이름을 보여줌
			return;
		}
	}
	cout << "해당 나라가 목록에 없습니다. 다시 입력해주세요 .. " << endl;
	goto ch; //입력한 나라 이름이 목록에 없을 경우 다시 입력

}
void NationManager::quiz() { //3. 퀴즈
	if (vec.size() == 0) { //입력된 정보가 없을 경우 퀴즈를 할 수 없음
		cout << "정보가 없어서 퀴즈를 할 수 없습니다. " << endl;
		return; //종료
	}
	string nameC; //입력받을 수도의 이름
	double quizN = 0.0, correctN = 0.0, correctRate = 0.0; //각각 퀴즈 수, 정답 수, 정답률을 저장하는 변수. 정답률을 계산하기 위해 전부 double형으로 선언해줌
	int x;
	while ((x = getchar()) != '\n'&&x != EOF); //입력버퍼 삭제
	while (true) {
		srand(time(NULL)); //난수 생성
		int x = rand() % vec.size(); //입력된 나라에서만 문제를 출제하도록 설정
		cout << vec[x].getNation() << "의 수도는? (종료시 q 입력)>> ";
		getline(cin, nameC);
		if (nameC == "q") { //"q"가 입력되면
			cout << "퀴즈를 종료합니다. " << endl;
			break; //퀴즈를 종료
		}
		else if (nameC == vec[x].getCapital()) { //정답일 경우
			cout << "정답입니다 !" << endl;
			correctN++; //정답 개수 +1
			quizN++; //퀴즈 개수 +1
		}
		else { //오답일 경우
			cout << "틀렸습니다.. " << endl;
			quizN++; //퀴즈의 개수만 +1
		}
	}
	correctRate = (correctN / quizN * 100); //정답률 계산
	cout << "총 " << quizN << "문제 중 " << correctN << "개를 맞추었습니다. " << endl; //총 문제수와 정답수 출력 후
	cout << "정답률은 " << correctRate << "% 입니다." << endl; //정답률을 알려주고 마침
}
void NationManager::play() { //나라의 수도 맞추기 게임을 진행하는 함수
	cout << "나라의 수도 맞추기 게임입니다." << endl;
	int menuSelect = 0; //메뉴 선택 변수
	while (true) {
	ms: //메뉴 선택이 잘못됐을 경우 돌아오는 곳
		cout << "1. 정보 입력, 2. 정보 수정, 3. 퀴즈, 4. 종료 >> ";
		cin >> menuSelect;
		switch (menuSelect) {
		case 1: input(); break; //1이 입력되면 정보 입력
		case 2: changeCapital(); break; //2가 입력되면 정보 수정
		case 3: quiz(); break; //3이 입력되면 퀴즈
		case 4: cout << "나라의 수도 맞추기 게임을 종료합니다." << endl; return; break; //4가 입력되면 종료
		default: // 그 이외의 숫자가 입력되면
			cout << "다시 입력해주세요.. " << endl;
			goto ms; //다시 입력
			break;
		}
	}
}

int main()
{
	NationManager n1; //클래스 NationManager 객체 생성
	n1.play(); //게임 진행

	return 0;
}

