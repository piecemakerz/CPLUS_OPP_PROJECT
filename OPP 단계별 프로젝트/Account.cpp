#include "BankingCommonDecl.h"
#include "Account.h"
#include "AccountException.h"

Account::Account(int ID, int money, String name)
	:accID(ID), balance(money) {
	cusName = name;
}

int Account::GetAccID() const { return accID; }

void Account::Deposit(int money) throw (LessthanzeroException){
	if (money < 0)
		throw LessthanzeroException(money);
	balance += money;
}

int Account::Withdraw(int money) throw (LessthanzeroException, WithdrawException){
	if (money < 0)
		throw LessthanzeroException(money);
	
	if (balance < money)
		throw WithdrawException(money);

	balance -= money;
	return money;
}

void Account::ShowAccInfo() const {
	cout << "°èÁÂID: " << accID << endl;
	cout << "ÀÌ¸§: " << cusName << endl;
	cout << "ÀÜ¾×: " << balance << endl;
}
