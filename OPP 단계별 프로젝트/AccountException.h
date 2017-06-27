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
		cout << "[���� �޽���: " << reqDep << "�� ����ݺҰ�]" << endl;
	}
};

class WithdrawException : public AccountException{
private:
	int balance;
public:
	WithdrawException(int money) : balance(money) {}
	void ShowExceptionReason() {
		cout << "[���� �޽���: " << balance << ", �ܾ׺���]" << endl;
	}
};

#endif