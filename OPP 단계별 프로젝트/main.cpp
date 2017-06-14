#include "common.h"
#include "MenuArrange.h"
#include "AccountManage.h"

int main(void) {
	while (1) {
		ShowMenu();

		if (SelectOption())
			break;

	}
	cout << "프로그램을 종료합니다.\n" << endl;
	return 0;
}