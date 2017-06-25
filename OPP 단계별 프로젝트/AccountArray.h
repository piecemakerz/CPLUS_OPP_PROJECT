#ifndef __ACCARRAY_H__
#define __ACCARRAY_H__

#include "Account.h"
typedef Account * ACCOUNT_PTR;

class AccountArray {
private:
	ACCOUNT_PTR * arr;
	int arrlen;

	AccountArray(const AccountArray& arr) { }
	AccountArray& operator=(const AccountArray& arr) { }

public:
	AccountArray(int len=100) : arrlen(len) {
		arr = new ACCOUNT_PTR[len];
	}
	~AccountArray() {
		delete[]arr;
	}
	ACCOUNT_PTR& operator[] (int idx);
	ACCOUNT_PTR operator[] (int idx) const;
	int GetArrLen() const;
};
#endif