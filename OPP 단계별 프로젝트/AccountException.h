#ifndef _ACCOUNT_EXCEPTION_H__
#define _ACCOUNT_EXCEPTION_H__

#include "BankingCommonDecl.h"

class AccountException {
public:
	virtual void ShowExceptionReason() = 0;
};

class LessthanzeroException : public AccountException {
private:
	int reqDep;
public:
	LessthanzeroException(int money) : reqDep(money) {}
	void ShowExceptionReason() {
		cout << "[예외 메시지: " << reqDep << "는 입출금불가]" << endl;
	}
};

class WithdrawException : public AccountException{
private:
	int balance;
public:
	WithdrawException(int money) : balance(money) {}
	void ShowExceptionReason() {
		cout << "[예외 메시지: " << balance << ", 잔액부족]" << endl;
	}
};

#endif