 #include "common.h"
#include "AccountHandler.h"

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

int SelectOption(AccountHandler &manager) {
	int select;
	cout << "���� : ";
	cin >> select;

	cout << endl;

	switch (select) {

	case MAKE:
		manager.MakeAccount();
		break;
	case DEPOSIT:
		manager.Deposit();
		break;
	case WITHDRAW:
		manager.Withdraw();
		break;
	case INQUIRE:
		manager.PrintAllAccountInfo();
		break;
	case EXIT:
		return 1;
	default:
		cout << "�߸� �����ϼ̽��ϴ�. �ٽ� �������ּ���.\n" << endl;
		break;

	}
	return 0;

}