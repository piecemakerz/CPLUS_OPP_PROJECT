#ifndef _ACCMANAGE_H__
#define _ACCMANAGE_H__

#include <iostream>
#include <cstring>

class accInfo {
private:
	int accNum;
	char * name;
	int money;
public:
	accInfo(int accNum, char * name, int money) : accNum(accNum), money(money) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	~accInfo() {
		delete[]name;
	}
	int GetAccNum(void) {
		return accNum;
	}
	char* GetName(void) {
		return name;
	}
	int GetMoney(void) {
		return money;
	}
	void SetAccNum(int num) {
		accNum = num;
	}
	void SetName(char * name) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	void SetMoney(int money) {
		this->money = money;
	}
};

void MakeAccount(void);
void Deposit(void);
void Withdraw(void);
void PrintAllAccountInfo(void);
#endif