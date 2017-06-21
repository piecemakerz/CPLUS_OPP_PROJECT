#include "common.h"
#include "MenuArrange.h"
#include "AccInfo.h"
#include "AccountHandler.h"

int main(void) {
	AccountHandler manager;
	while (1) {
		ShowMenu();

		if (SelectOption(manager))
			break;

	}
	cout << "프로그램을 종료합니다.\n" << endl;
	return 0;
}