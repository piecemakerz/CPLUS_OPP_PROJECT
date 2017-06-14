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
	cout << "[���°���]" << endl;

	cout << "����ID : ";
	cin >> accInfoList[accnum].accNum;
	cout << "�� �� : ";
	cin >> accInfoList[accnum].name;
	cout << "�Աݾ� : ";
	cin >> accInfoList[accnum++].money;

	cout << "�����Ϸ�\n" << endl;
}

void Deposit(void) {
	int inputAccnum, inputmoney;

	cout << "[�Ա�]" << endl;

	cout << "����ID : ";
	cin >> inputAccnum;

	for (int i = 0; i < accnum; i++) {
		if (inputAccnum == accInfoList[i].accNum) {
			cout << "�Աݾ� : ";
			cin >> inputmoney;
			accInfoList[i].money += inputmoney;
			cout << "�ԱݿϷ�\n" << endl;
			return;
		}
	}

	cout << "�ش��ϴ� ����ID�� �������� �ʽ��ϴ�.\n" << endl;
}

void Withdraw(void) {
	int withdrawAccnum, withdrawmoney;
	cout << "[���]" << endl;

	cout << "����ID : ";
	cin >> withdrawAccnum;

	for (int i = 0; i < accnum; i++) {
		if (withdrawAccnum == accInfoList[i].accNum) {
			cout << "���� �����ϰ� ��� �ݾ� : " << accInfoList[i].money << endl;
			cout << "��ݾ� : ";
			cin >> withdrawmoney;
			if (withdrawmoney > accInfoList[i].money) {
				cout << "��ݾ��� �����׺��� Ů�ϴ�.\n" << endl;
				return;
			}
			accInfoList[i].money -= withdrawmoney;
			cout << "��ݿϷ�\n" << endl;
			return;
		}
	}

	cout << "�ش��ϴ� ����ID�� �������� �ʽ��ϴ�.\n" << endl;
}

void PrintAllAccountInfo(void) {
	for (int i = 0; i < accnum; i++) {
		cout << "����ID : " << accInfoList[i].accNum << endl;
		cout << "�̸� : " << accInfoList[i].name << endl;
		cout << "�ܾ� : " << accInfoList[i].money << endl;
		cout << '\n' << endl;
	}
}