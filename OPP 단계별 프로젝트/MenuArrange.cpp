#include "common.h"
#include "AccountManage.h"

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
void ShowMenu(void) {
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	return;
}

int SelectOption(void) {
	int select;
	cout << "���� : ";
	cin >> select;

	cout << endl;

	switch (select) {

	case MAKE:
		MakeAccount();
		break;
	case DEPOSIT:
		Deposit();
		break;
	case WITHDRAW:
		Withdraw();
		break;
	case INQUIRE:
		PrintAllAccountInfo();
		break;
	case EXIT:
		return 1;
	default:
		cout << "�߸� �����ϼ̽��ϴ�. �ٽ� �������ּ���.\n" << endl;
		break;

	}
	return 0;

}