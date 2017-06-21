#ifndef __HIGHCREACC_H__
#define __HIGHCREACC_H__

#include "common.h"
#include "NormalAccount.h"
using namespace std;

enum { classA = 1, classB = 2, classC = 3 };


class HighCreditAccount : public NormalAccount{
private:
	int credrating;
public:
	HighCreditAccount(int accNum, char * name, int money, int interest, int creditrating)
		: NormalAccount(accNum, name, money, interest), credrating(creditrating)
	{}
	void SetMoney(int money) {
		int highcred_money;

		switch (credrating) {
		case classA:
			highcred_money = money* (1 + ((double)(GetInterest() + 7) / 100));
			break;
		case classB:
			highcred_money = money* (1 + ((double)(GetInterest() + 4) / 100));
			break;
		case classC:
			highcred_money = money* (1 + ((double)(GetInterest() + 2) / 100));
			break;
		}

		accInfo::SetMoney(highcred_money);
	}
};

#endif