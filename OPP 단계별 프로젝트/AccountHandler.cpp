#include "AccountHandler.h"
#define NAME_LEN 30

void AccountHandler::MakeAccount(void) {
	int id;
	char name[NAME_LEN];
	int money;
	int choice;
	int interest;
	int credrating;

	cout << "[계좌개설]" << endl;
	cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
	cout << "선택: ";
	cin >> choice;

	if (choice != 1 && choice != 2) {
		cout << "잘못된 선택입니다." << endl;
		return;
	}

	switch (choice) {
	case 1:
		cout << "[보통예금계좌 개설]" << endl;
		cout << "계좌ID : ";
		cin >> id;
		cout << "이 름 : ";
		cin >> name;
		cout << "입금액 : ";
		cin >> money;
		cout << "이자율: ";
		cin >> interest;

		accInfoList[accnum++] = new NormalAccount(id, name, money, interest);
		break;

	case 2:
		cout << "[신용신뢰계좌 개설]" << endl;
		cout << "계좌ID : ";
		cin >> id;
		cout << "이 름 : ";
		cin >> name;
		cout << "입금액 : ";
		cin >> money;
		cout << "이자율: ";
		cin >> interest;
		cout << "신용등급(1toA, 2toB, 3toC): ";
		cin >> credrating;

		if (credrating != 1 && credrating != 2 && credrating != 3) {
			cout << "잘못된 신용등급입니다." << endl;
			return;
		}

		accInfoList[accnum++] = new HighCreditAccount(id, name, money, interest, credrating);
		break;
	}

	cout << "개설완료\n" << endl;
}

void AccountHandler::Deposit(void) {
	int inputAccnum, inputmoney;
	cout << "[입금]" << endl;

	cout << "계좌ID : ";
	cin >> inputAccnum;

	for (int i = 0; i < accnum; i++) {
		if (inputAccnum == accInfoList[i]->GetAccNum()) {
			int currentMoney = accInfoList[i]->GetMoney();
			cout << "입금액 : ";
			cin >> inputmoney;
			accInfoList[i]->SetMoney(currentMoney + inputmoney);
			cout << "입금완료\n" << endl;
			return;
		}
	}

	cout << "해당하는 계좌ID가 존재하지 않습니다.\n" << endl;
}

void AccountHandler::Withdraw(void) {
	int withdrawAccnum, withdrawmoney;
	cout << "[출금]" << endl;

	cout << "계좌ID : ";
	cin >> withdrawAccnum;

	for (int i = 0; i < accnum; i++) {
		if (withdrawAccnum == accInfoList[i]->GetAccNum()) {
			int currentMoney = accInfoList[i]->GetMoney();
			cout << "현재 보유하고 계신 금액 : " << currentMoney << endl;
			cout << "출금액 : ";
			cin >> withdrawmoney;
			if (withdrawmoney > currentMoney) {
				cout << "출금액이 보유액보다 큽니다.\n" << endl;
				return;
			}
			accInfoList[i]->SetMoney(currentMoney - withdrawmoney);
			cout << "출금완료\n" << endl;
			return;
		}
	}

	cout << "해당하는 계좌ID가 존재하지 않습니다.\n" << endl;
}

void AccountHandler::PrintAllAccountInfo(void) {
	for (int i = 0; i < accnum; i++) {
		cout << "계좌ID : " << accInfoList[i]->GetAccNum() << endl;
		cout << "이름 : " << accInfoList[i]->GetName() << endl;
		cout << "잔액 : " << accInfoList[i]->GetMoney() << endl;
		cout << '\n' << endl;
	}
}