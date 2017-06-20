#include "AccountHandler.h"
#define NAME_LEN 30

void AccountHandler::MakeAccount(void) {
	int id;
	char name[NAME_LEN];
	int money;

	cout << "[���°���]" << endl;

	cout << "����ID : ";
	cin >> id;
	cout << "�� �� : ";
	cin >> name;
	cout << "�Աݾ� : ";
	cin >> money;

	accInfoList[accnum++] = new accInfo(id, name, money);

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