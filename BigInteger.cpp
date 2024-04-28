#include "BigInteger.h"
#include "Float.h"

using namespace std;

BigInteger::BigInteger(string name) :Variable(name)
{
	setDataType(dataType::BIGINT);
	cout << "введите BigInt:";
	string str;
	cin >> str;
	BigInteger(name, str);
}
BigInteger::BigInteger(string name, string bi) : Variable(name, 0)
{
	if (bi.length() == 0) {
		is_negative=false;
	}
	else {
		if (bi[0] == '-') {
			bi=bi.substr(1);
			is_negative=true;
		}
		else {
			is_negative=false;
		}
		for (unsigned long long i=bi.length(); i > 0; i-=9) {
			if (i < 9)
				digits.push_back(atoi(bi.substr(0, i).c_str()));
			else
				digits.push_back(atoi(bi.substr(i - 9, 9).c_str()));
		}
		remove_leading_zeros();
	}
}

void BigInteger::remove_leading_zeros() {
	while (digits.size() > 1 && digits.back() == 0) {
		digits.pop_back();
	}
	if (digits.size() == 1 && digits[0] == 0) is_negative=false;
}

Variable* BigInteger::operator+(Variable* arg)
{
	//BigInteger* tmpArg=(BigInteger*)arg;
	//if (is_negative) {
	//	if (this->is_negative) return -(-*this + (-*tmpArg));
	//	else return *tmpArg - (-*this);
	//}
	//else if (tmpArg->is_negative) return *this - (-*tmpArg);
	//int carry=0; // флаг переноса из предыдущего разряда
	//for (size_t i=0; i < std::max(this->digits.size(), tmpArg->digits.size()) || carry != 0; ++i) {
	//	if (i == this->digits.size()) this->digits.push_back(0);
	//	this->digits[i]+=carry + (i < tmpArg->digits.size() ? tmpArg->digits[i] : 0);
	//	carry=this->digits[i] >= BigInteger::BASE;
	//	if (carry != 0) this->digits[i]-=BigInteger::BASE;
	//}
	return this;
}

Variable* BigInteger::operator+(Float* arg)
{
	return this;
}

Variable* BigInteger::operator*(Variable* arg)
{
	return this;
}

Variable* BigInteger::operator*(Float* arg)
{
	return this;
}

Variable* BigInteger::operator-(Variable* arg)
{
	return this;
}

Variable* BigInteger::operator-(Float* arg)
{
	return this;
}

Variable* BigInteger::operator/(Variable* arg)
{
	return this;
}

Variable* BigInteger::operator/(Float* arg)
{
	return this;
}

Variable* BigInteger::toUpDegree(Variable* arg)
{
	return this;
}

Variable* BigInteger::toUpDegree(Float* arg)
{
	return this;
}

void BigInteger::print(Variable* arg)
{

}