#include "AccountHandler.h"
#define NAME_LEN 30

void AccountHandler::MakeAccount(void) {
	int id;
	char name[NAME_LEN];
	int money;

	cout << "[계좌개설]" << endl;

	cout << "계좌ID : ";
	cin >> id;
	cout << "이 름 : ";
	cin >> name;
	cout << "입금액 : ";
	cin >> money;

	accInfoList[accnum++] = new accInfo(id, name, money);

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