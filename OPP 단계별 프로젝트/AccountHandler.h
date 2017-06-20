#ifndef __ACCHANDLER_H__
#define __ACCHANDLER_H__
#include "common.h"
#include "AccountManage.h"
#include <cstring>

#define MAX_ACC_NUM 100
using namespace std;

class AccountHandler {
private:
	accInfo* accInfoList[MAX_ACC_NUM];
	int accnum;
public:
	AccountHandler() : accnum(0) {}
	void MakeAccount(void);
	void Deposit(void);
	void Withdraw(void);
	void PrintAllAccountInfo(void);
};
#endif