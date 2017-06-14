#include "common.h"
#define MAX_ACC_NUM 100
#define NAME_LEN 20

typedef struct _accountInfo {
	int accNum;
	char name[NAME_LEN];
	int money;
}accInfo;

static accInfo accInfoList[MAX_ACC_NUM] = { 0 };
static int accnum = 0;

void MakeAccount(void) {
	cout << "[계좌개설]" << endl;

	cout << "계좌ID : ";
	cin >> accInfoList[accnum].accNum;
	cout << "이 름 : ";
	cin >> accInfoList[accnum].name;
	cout << "입금액 : ";
	cin >> accInfoList[accnum++].money;

	cout << "개설완료\n" << endl;
}

void Deposit(void) {
	int inputAccnum, inputmoney;

	cout << "[입금]" << endl;

	cout << "계좌ID : ";
	cin >> inputAccnum;

	for (int i = 0; i < accnum; i++) {
		if (inputAccnum == accInfoList[i].accNum) {
			cout << "입금액 : ";
			cin >> inputmoney;
			accInfoList[i].money += inputmoney;
			cout << "입금완료\n" << endl;
			return;
		}
	}

	cout << "해당하는 계좌ID가 존재하지 않습니다.\n" << endl;
}

void Withdraw(void) {
	int withdrawAccnum, withdrawmoney;
	cout << "[출금]" << endl;

	cout << "계좌ID : ";
	cin >> withdrawAccnum;

	for (int i = 0; i < accnum; i++) {
		if (withdrawAccnum == accInfoList[i].accNum) {
			cout << "현재 보유하고 계신 금액 : " << accInfoList[i].money << endl;
			cout << "출금액 : ";
			cin >> withdrawmoney;
			if (withdrawmoney > accInfoList[i].money) {
				cout << "출금액이 보유액보다 큽니다.\n" << endl;
				return;
			}
			accInfoList[i].money -= withdrawmoney;
			cout << "출금완료\n" << endl;
			return;
		}
	}

	cout << "해당하는 계좌ID가 존재하지 않습니다.\n" << endl;
}

void PrintAllAccountInfo(void) {
	for (int i = 0; i < accnum; i++) {
		cout << "계좌ID : " << accInfoList[i].accNum << endl;
		cout << "이름 : " << accInfoList[i].name << endl;
		cout << "잔액 : " << accInfoList[i].money << endl;
		cout << '\n' << endl;
	}
}