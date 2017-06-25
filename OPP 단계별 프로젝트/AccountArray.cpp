#include <iostream>
#include "AccountArray.h"
using namespace std;

ACCOUNT_PTR& AccountArray::operator[] (int idx) {
	if (idx<0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}

	return arr[idx];
}
ACCOUNT_PTR AccountArray::operator[] (int idx) const {
	if (idx<0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}

	return arr[idx];
}
int AccountArray::GetArrLen() const {
	return arrlen;
}