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
	cout << "���α׷��� �����մϴ�.\n" << endl;
	return 0;
}