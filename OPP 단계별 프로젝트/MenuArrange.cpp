 #include "common.h"
#include "AccountHandler.h"

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
void ShowMenu(void) {
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	return;
}

int SelectOption(AccountHandler &manager) {
	int select;
	cout << "선택 : ";
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
		cout << "잘못 선택하셨습니다. 다시 선택해주세요.\n" << endl;
		break;

	}
	return 0;

}