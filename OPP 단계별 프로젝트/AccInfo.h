#ifndef _ACCINFO_H__
#define _ACCINFO_H__
#include "common.h"
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
	accInfo(const accInfo& ref) : accNum(ref.accNum), money(ref.accNum) {
		this->name = new char[strlen(ref.name) + 1];
		strcpy(this->name, ref.name);
	}
	int GetAccNum(void) const {
		return accNum;
	}
	char* GetName(void) const {
		return name;
	}
	int GetMoney(void) const {
		return money;
	}
	void SetAccNum(int num) {
		accNum = num;
	}
	void SetName(char * name) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	virtual void SetMoney(int money) {
		this->money = money;
	}
};
#endif