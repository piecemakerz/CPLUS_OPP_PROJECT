#ifndef __NORMALACC_H__
#define __NORMALACC_H__

#include "common.h"
#include "AccInfo.h"
using namespace std;

class NormalAccount : public accInfo {
private:
	int interest;
public:
	NormalAccount(int accNum, char * name, int money, int interest)
		:accInfo(accNum, name, money), interest(interest)
	{}
	void SetMoney(int money) {
		int inter_money = money* (1 + ((double)interest / 100));
		accInfo::SetMoney(inter_money);
	}
	int GetInterest(void) {
		return interest;
	}
};

#endif