#include "stdafx.h"
#include "Printer.h"
#include "InkJetPrinter.h"
#include "LaserPrinter.h"
#include "LinePrinter.h"
#include <iostream>
#include <string>
using namespace std;

void allshow(InkJetPrinter i, LaserPrinter l, LinePrinter li) { //��� �������� ������ �����ִ� �Լ�
	i.show(); //��ũ��������
	l.show(); //������������
	li.show(); //����������
}

int main()
{
	InkJetPrinter* ink = new InkJetPrinter("Officejet V40", "HP", 0, 5, 10); //��ũ�������� ���� ����
	LaserPrinter* laser = new LaserPrinter("SCX-6x45", "�Ｚ����", 0, 3, 20); //������������ ���� ����
	LinePrinter* line = new LinePrinter("PT-D600", "Brother", 0, 9, 30); //���������� ���� ����
	cout << "���� �۵����� 3 ���� �����ʹ� �Ʒ��� ����" << endl; //���� ������ ������ �����ֱ�
	cout << "��ũ�� : "; ink->show(); //��ũ��
	cout << "������ : "; laser->show(); //������
	cout << "��  �� : "; line->show(); //����

	int select = 0, printer = 0, printpages = 0, adding = 0, addsth = 0; //���� �۾�����, ����Ʈ����, �μ��� ��������, ������ ����, ������ ��ǰ�� ��Ÿ���� ����
	char keep = 'y'; //����� ������ ���� ����
	while (keep == 'y') { //����Ѵٰ� ����� ��쿡 �ݺ�
		cout << endl;
	selection: //�۾������� �ϴ� ��
		cout << "����Ʈ(1), ����(2) >> "; //�۾�����
		cin >> select; 
		if (select == 1) { //����Ʈ
			pr: //�����Ϳ� �μ� �ż��� �Է��ϴ� ��
			cout << "������(1:��ũ��, 2:������, 3:����)�� �ż� �Է�>>"; //����Ʈ����
			cin >> printer >> printpages; //����Ʈ�� �μ� �ż� �Է�
			if (printpages < 1) {
				cout << "�ٽ� �Է����ּ���.. " << endl; //�߸��� �μ� �ż��� �Է��� ���
				goto pr; //�ٽ� �μ� �ż��� �Է��ϴ� ������ ���ư�
			}
			switch (printer) { 
			case 1: //��ũ�� ������
				if (printpages > ink->getavailableCount()) { //�μ� �ܷ��� �μ� �ż����� ������
					cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�" << endl; //����Ʈ�� �� ����
				} else if (printpages > ink->getavailableInk()) { //��ũ�� �μ� �ż����� ������ 
					cout << "��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�" << endl; //����Ʈ�� �� ����
				}
				else { //����Ʈ �� �� �ִ� ���
					ink->print(printpages); //��ũ�� �����Ϳ��� printpages ��ŭ ����Ʈ
				}
				allshow(*ink, *laser, *line);
				break;
			case 2: //������ ������
				if (printpages > laser->getavailableCount()) { //�μ� �ܷ��� �μ� �ż����� ������
					cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�" << endl; //����Ʈ�� �� ����
				} else if (laser->getavailableToner() < 1) { //��ʰ� ������
					cout << "��ʰ� �����Ͽ� ����Ʈ�� �� �����ϴ�" << endl; //����Ʈ�� �� ����
				}
				else { //����Ʈ �� �� �ִ� ���
					laser->print(printpages); //������ �����Ϳ��� printpages ��ŭ ����Ʈ
				}
				allshow(*ink, *laser, *line);
				break;
			case 3: //���� ������
				if (printpages > line->getavailableCount()) { //�μ� �ܷ��� �μ� �ż����� ������
					cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�" << endl; //����Ʈ�� �� ����
				} else if (line->getavailableDrum() < 1) { //�巳�� ������
					cout << "�巳�� �����Ͽ� ����Ʈ�� �� �����ϴ�" << endl; //����Ʈ�� �� ����
				}
				else {
					line->print(printpages); //���� �����Ϳ��� printpages ��ŭ ����Ʈ
				}
				allshow(*ink, *laser, *line);
				break;
			default:
				cout << "�ٽ� �Է����ּ���.." << endl; //�����͸� �߸� ������ ���
				goto pr; //�ٽ� �����͸� �����ϴ� ������ ���ư�
				break;
			}

		}
		else if (select == 2) { //����
			ad1: // ������ ��ǰ�� ������ ������ �Է��ϴ� ��
			cout << "������ ��ǰ(1:����, 2:��ũ, 3:���, 4:�巳)�� ������ ���� �Է�>>";
			cin >> adding >> addsth; //������ ��ǰ�� ������ ���� �Է�
			if (addsth < 1) {
				cout << "�ٽ� �Է����ּ���.. " << endl; //������ ������ �߸� �Էµ� ���
				goto ad1; //������ ������ �ٽ� �Է��ϴ� ������ ���ư�
			}
			switch (adding) 
			{
			case 1: //���� ����
				ad2: //�����͸� �����ϴ� ��
				cout << "���̸� ������ ������(1:��ũ��, 2:������, 3:����) �Է�>>"; 
				cin >> printer; 
				switch (printer)
				{
				case 1: //��ũ�� ������
					ink->Printer::add(addsth); //��ũ�� �����Ϳ� ���� ����
					allshow(*ink, *laser, *line);
					break;
				case 2: //������ ������
					laser->Printer::add(addsth); //������ �����Ϳ� ���� ����
					allshow(*ink, *laser, *line);
					break;
				case 3: //���� ������
					line->Printer::add(addsth); //���� �����Ϳ� ���� ����
					allshow(*ink, *laser, *line);
					break;
				default:
					cout << "�ٽ� �Է����ּ���.." << endl; //�����͸� �߸� ������ ���
					goto ad2; //�ٽ� �����͸� �����ϴ� ������ ���ư�
					break;
				}
				break;
			case 2: //��ũ ����
				ink->add(addsth); //��ũ�� �����Ϳ� ��ũ ����
				allshow(*ink, *laser, *line);
				break;
			case 3: //��� ����
				laser->add(addsth); //������ �����Ϳ� ��� ����
				allshow(*ink, *laser, *line);
				break;
			case 4: //�巳 ����
				line->add(addsth); //���� �����Ϳ� �巳 ����
				allshow(*ink, *laser, *line);
				break;
			default:
				cout << "�ٽ� �Է����ּ���.." << endl; //������ ��ǰ�� ������ ������ �߸� �Է��� ���
				goto ad1; //�ٽ� �Է��ϱ� ���� ���ư�
				break;
			}
		}
		else { 
			cout << "�ٽ� �Է����ּ���.." << endl; //�۾� ������ �߸��� ���
			goto selection; //�۾� ���� �ϴ� ������ ���ư�
		}

		conti: //�۾��� ��� �� ������ �����ϴ� ��
		cout << "��� �Ͻðڽ��ϱ�?(y/n)>>"; 
		cin >> keep; //keep�� 'y'��� while���� ���������� �ʰ� ��� ����, 'n'�̶�� while���� ���
		if (keep != 'y' && keep != 'n') { //keep�� �߸� �Էµ� ��� 
			cout << "�ٽ� �Է����ּ���.." << endl;
			goto conti; //�ٽ� �۾��� ��� �� ������ ���� ������ ���ư�
		}
	}

	delete ink; //��ũ�� ������ ��ȯ
	delete laser; //������ ������ ��ȯ
	delete line; //���� ������ ��ȯ
	return 0;
}