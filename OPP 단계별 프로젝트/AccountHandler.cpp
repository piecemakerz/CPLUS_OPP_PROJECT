#include "AccountHandler.h"
#define NAME_LEN 30

void AccountHandler::MakeAccount(void) {
	int id;
	char name[NAME_LEN];
	int money;
	int choice;
	int interest;
	int credrating;

	cout << "[���°���]" << endl;
	cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
	cout << "����: ";
	cin >> choice;

	if (choice != 1 && choice != 2) {
		cout << "�߸��� �����Դϴ�." << endl;
		return;
	}

	switch (choice) {
	case 1:
		cout << "[���뿹�ݰ��� ����]" << endl;
		cout << "����ID : ";
		cin >> id;
		cout << "�� �� : ";
		cin >> name;
		cout << "�Աݾ� : ";
		cin >> money;
		cout << "������: ";
		cin >> interest;

		accInfoList[accnum++] = new NormalAccount(id, name, money, interest);
		break;

	case 2:
		cout << "[�ſ�ŷڰ��� ����]" << endl;
		cout << "����ID : ";
		cin >> id;
		cout << "�� �� : ";
		cin >> name;
		cout << "�Աݾ� : ";
		cin >> money;
		cout << "������: ";
		cin >> interest;
		cout << "�ſ���(1toA, 2toB, 3toC): ";
		cin >> credrating;

		if (credrating != 1 && credrating != 2 && credrating != 3) {
			cout << "�߸��� �ſ����Դϴ�." << endl;
			return;
		}

		accInfoList[accnum++] = new HighCreditAccount(id, name, money, interest, credrating);
		break;
	}

	cout << "�����Ϸ�\n" << endl;
}

void AccountHandler::Deposit(void) {
	int inputAccnum, inputmoney;
	cout << "[�Ա�]" << endl;

	cout << "����ID : ";
	cin >> inputAccnum;

	for (int i = 0; i < accnum; i++) {
		if (inputAccnum == accInfoList[i]->GetAccNum()) {
			int currentMoney = accInfoList[i]->GetMoney();
			cout << "�Աݾ� : ";
			cin >> inputmoney;
			accInfoList[i]->SetMoney(currentMoney + inputmoney);
			cout << "�ԱݿϷ�\n" << endl;
			return;
		}
	}

	cout << "�ش��ϴ� ����ID�� �������� �ʽ��ϴ�.\n" << endl;
}

void AccountHandler::Withdraw(void) {
	int withdrawAccnum, withdrawmoney;
	cout << "[���]" << endl;

	cout << "����ID : ";
	cin >> withdrawAccnum;

	for (int i = 0; i < accnum; i++) {
		if (withdrawAccnum == accInfoList[i]->GetAccNum()) {
			int currentMoney = accInfoList[i]->GetMoney();
			cout << "���� �����ϰ� ��� �ݾ� : " << currentMoney << endl;
			cout << "��ݾ� : ";
			cin >> withdrawmoney;
			if (withdrawmoney > currentMoney) {
				cout << "��ݾ��� �����׺��� Ů�ϴ�.\n" << endl;
				return;
			}
			accInfoList[i]->SetMoney(currentMoney - withdrawmoney);
			cout << "��ݿϷ�\n" << endl;
			return;
		}
	}

	cout << "�ش��ϴ� ����ID�� �������� �ʽ��ϴ�.\n" << endl;
}

void AccountHandler::PrintAllAccountInfo(void) {
	for (int i = 0; i < accnum; i++) {
		cout << "����ID : " << accInfoList[i]->GetAccNum() << endl;
		cout << "�̸� : " << accInfoList[i]->GetName() << endl;
		cout << "�ܾ� : " << accInfoList[i]->GetMoney() << endl;
		cout << '\n' << endl;
	}
}