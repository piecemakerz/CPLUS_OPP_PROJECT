#include "common.h"
#include "MenuArrange.h"
#include "AccountManage.h"

int main(void) {
	while (1) {
		ShowMenu();

		if (SelectOption())
			break;

	}
	cout << "���α׷��� �����մϴ�.\n" << endl;
	return 0;
}