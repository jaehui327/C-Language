#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Student {
	string studentID; //학번
	string name; //이름
	double korean = 0, english = 0, math = 0; //각각 국어, 영어, 수학 점수
public:
	const void setInN(string& studentID, string& name) { this->studentID = studentID; this->name = name; } //학생정보입력시 사용되는 세터
	const string getID() { return studentID; } //학번을 리턴하는 함수
	const string getName() { return name; } //이름을 리턴하는 함수
	const double getKorean() { return korean; } //국어 점수 리턴
	const double getEnglish() { return english; } //영어 점수 리턴
	const double getMath() { return math; } //수학 점수 리턴
	const double average() { //평균을 구하고 리턴하는 함수
		double aver = 0.00;
		aver = (korean + english + math) / 3;
		return aver;
	}
	friend istream& operator >> (istream& ins, Student& s); //연산자 재정의
	const void setScore(Student& s); //성적을 입력받는 함수
};

istream& operator >> (istream& ins, Student& s) { //Student 객체에서 >> 연산자를 사용했을 때
	cout << "국어 >> ";
	ins >> s.korean;
	cout << "영어 >> ";
	ins >> s.english;
	cout << "수학 >> ";
	ins >> s.math;
	return ins; //각각의 점수를 입력받고 리턴
}
const void Student::setScore(Student& s) { //점수 세팅
	cin >> s; 
}

class StudentManager : Student {
	vector<Student> v; //학생 정보를 저장하는 벡터
public:
	friend ostream& operator << (ostream& outs, vector<Student> v); //연산자 재정의
	const void inputSI(); //1.학생정보입력
	const void inputScore(); //2.성적입력
	const void searchScore(); //3.개인성적조회
	const void outputFile(); //4.성적파일출력
	const void play(); //전체적인 프로그램을 관리

};
ostream& operator << (ostream& outs, vector<Student> v) { //StudentManager 객체에서 << 연산자를 사용했을 때
	for (int i = 0; i < v.size(); i++) { //학번 프롬프트 출력
		outs << v[i].getID() << ";" << v[i].getName() << endl;
	}outs;
	return outs;
}
const void StudentManager::inputSI() { //1.학생정보입력
	string line, id, name; //라인, 학번, 이름
	Student s; //Student 객체
	int index; //학번과 이름을 가져올 때 ';'의 인덱스를 저장하는 변수
	ifstream fin;
	fin.open("std_info.txt"); //std_info.txt를 열어 입력
	if (!fin) { //해당 파일이 없을 경우
		cout << "std_info.txt를 열 수 없습니다." << endl;
		return;
	}
	cout << "학생 정보를 입력합니다. " << endl;
	while (true) {
		re: //중복된 학생이 있는 경우 돌아오는 곳
		getline(fin, line); // fin 파일에서 한 라인 읽기
		index = line.find(';'); //';'의 인덱스
		id = line.substr(0, index); //맨 앞부터 ';' 전까지가 학번
		name = line.substr(index + 1); //';'다음부터 이름
		for (int i = 0; i < v.size(); i++) { 
			if (id == v[i].getID()) { //중복된 학생이 있을 경우
				cout << "중복된 학생 " << id << "가 있습니다." << endl;
				if (fin.eof()) goto fi; //마지막 줄일때 while문 종료
				goto re; //다음줄부터 읽는 곳으로 돌아감
			}
		}
		s.setInN(id, name); //학번과 이름 설정
		v.push_back(s); //벡터에 넣기
		if (fin.eof()) break; //마지막 줄일 경우 while문 종료
	}
	fi:
	if (v.size() < 10) { //10명 이하
		cout << "총 입력된 학생 : " << v.size() << ", 최소 10명 이상의 학생을 입력해주세요." << endl;
		return;
	} else {
		cout << "총 입력된 학생 : " << v.size() << endl;
	}
	fin.close(); //입력 파일 닫기
}

const void StudentManager::inputScore() { //2.성적입력
	if (v.size() < 10) { //학생이 없거나 10명 이하일 때
		cout << "학생정보를 입력해주세요. " << endl;
		return;
	}
	string id; //학번
	char a; //이미 성적이 있는 학생일 경우, 수정할 것인지 대답
	int x;
	while ((x = getchar()) != '\n'&&x != EOF); //입력버퍼 삭제
	while (true) {
		cout << v; //학번 프롬프트 출력
		cout << "학생의 학번을 입력하세요 >> ";
		getline(cin, id);
		for (int i = 0; i < v.size(); i++) {
			if (v[i].getID() == id) { //입력된 학번이 있을 때
				if (v[i].getKorean() != 0) { //이미 성적이 입력된 학생일 경우
					answer:
					cout << "이미 입력한 학생입니다. 수정하려면 y, 종료하려면 n >>"; 
					cin >> a;
					if (a == 'y') { //수정할 경우
						Student::setScore(v[i]);
						return;
					}
					else if (a == 'n') { //종료
						return;
					}
					else { //'y'나 'n'이 아닌 문자가 입력된 경우
						cout << "다시 입력해주세요.. " << endl;
						goto answer;
					}
				}
				Student::setScore(v[i]); //성적 입력
				return;
			}
		}
		cout << "다시 입력해주세요.." << endl; //잘못된 학번이 입력되었을 때
	}
}
const void StudentManager::searchScore() { //3.개인성적조회
	if (v.size() < 10) { //학생이 없거나 10명 이하일 때
		cout << "학생정보를 입력해주세요. " << endl;
		return;
	}
	int x;
	while ((x = getchar()) != '\n'&&x != EOF); //입력버퍼 삭제
	search: //잘못된 학번일 경우 돌아오는 곳
	string id; //학번
	cout.setf(ios::left); //왼쪽 정렬
	cout << v; //학번 프롬프트 출력
	cout << "학번을 입력하세요 >> ";
	getline(cin, id);
	cout.setf(ios::fixed); //소수점 고정
	cout.precision(2); //소수점 두자리까지
	for (int i = 0; i < v.size(); i++) {
		if (v[i].getID() == id) { //해당되는 학번을 찾았을 경우 출력, 조절자 사용
			cout << setw(10) << "학번" << setw(10) << "이름" << setw(10) << "국어"
				<< setw(10) << "영어" << setw(10) << "수학" << setw(10) << "평균" << endl;
			cout << setw(10) << v[i].getID() << setw(10) << v[i].getName() << setw(10) << v[i].getKorean()
				<< setw(10) << v[i].getEnglish() << setw(10) << v[i].getMath() << setw(10) << v[i].average() << endl;
			return;
		}
	}
	cout << "다시 입력해주세요.." << endl;
	goto search; //잘못된 학번일 때 다시 입력
	
}
const void StudentManager::outputFile() { //4.성적파일출력
	if (v.size() < 10) { //학생이 없거나 10명 이하일 때
		cout << "학생정보를 입력해주세요." << endl;
		return;
	}
	ofstream fout;
	fout.open("std_score.txt"); //std_score.txt를 열어 출력
	if (!fout) {
		cout << "std_score.txt를 열 수 없습니다." << endl; //파일이 없을 때
		return;
	}
	cout.setf(ios::left); //출력 왼쪽 정렬
	cout.setf(ios::fixed); //소수점 고정
	cout.precision(2); //소수점 두자리까지
	cout << setw(10) << "학번" << setw(10) << "이름" << setw(10) << "국어"
		<< setw(10) << "영어" << setw(10) << "수학" << setw(10) << "평균" << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << setw(10) << v[i].getID() << setw(10) << v[i].getName() << setw(10) << v[i].getKorean()
			<< setw(10) << v[i].getEnglish() << setw(10) << v[i].getMath() << setw(10) << v[i].average() << endl;
	}
	cout << "모든 학생의 성적을 파일에 저장합니다. " << endl;
	fout.setf(ios::left); //파일 출력 왼쪽 정렬
	fout << setw(10) << "학번" << setw(10) << "이름" << setw(10) << "국어"
		<< setw(10) << "영어" << setw(10) << "수학";
	fout.setf(ios::fixed);
	fout.precision(2);
	fout << setw(10) << "평균" << endl;
	cout.unsetf(ios::fixed);
	for (int i = 0; i < v.size(); i++) {
		fout << setw(10) << v[i].getID() << setw(10) << v[i].getName() << setw(10) << v[i].getKorean()
			<< setw(10) << v[i].getEnglish() << setw(10) << v[i].getMath() << setw(10) << v[i].average() << endl;
	}
	fout.close(); //출력 파일 닫기
}
const void StudentManager::play() { 
	int select; //메뉴 선택
	while (true) {
		sel: //메뉴 잘못 선택됐을 경우
		cout << "1.학생정보입력 2.성적입력 3.개인성적조회 4.성적파일출력 5.종료 >> ";
		cin >> select;
		switch(select) {
		case 1: inputSI(); break; //1.학생정보입력
		case 2: inputScore(); break; //2.성적입력
		case 3: searchScore(); break; //3.개인성적조회
		case 4: outputFile(); break; //4.성적파일출력
		case 5: return; break; //5.종료
		default:
			cout << "다시 선택해주세요.. " << endl;
			goto sel; //다시 선택하는 곳으로 돌아감
			break;
		}
	}
}

int main()
{
	cout << "성적처리 프로그램입니다. " << endl;
	StudentManager m1; //StudentManger 객체 생성
	m1.play(); //프로그램 실행
    return 0;
}

