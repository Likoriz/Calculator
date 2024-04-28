#include "BigInteger.h"
#include "Float.h"

using namespace std;

BigInteger::BigInteger(string name):Variable(name)
{
	setDataType(dataType::BIGINT);
	cout<<"введите BigInt:";
	string str;
	cin>>str;
	if(str.length()==0) {
		// из пустой строки создается ноль
		this->_is_negative=false;
	}
	else {
		if(str[0]=='-') {
			str=str.substr(1);
			this->_is_negative=true;
		}
		else {
			this->_is_negative=false;
		}
		for(unsigned long long i=str.length(); i>0; i-=9) {
			if(i<9)
				this->_digits.push_back(atoi(str.substr(0, i).c_str()));
			else
				this->_digits.push_back(atoi(str.substr(i-9, 9).c_str()));
		}
		this->remove_leading_zeros();
	}
}

void BigInteger::remove_leading_zeros() {
	while(this->_digits.size()>1&&this->_digits.back()==0) {
		this->_digits.pop_back();
	}
	if(this->_digits.size()==1&&this->_digits[0]==0) this->_is_negative=false;
}

BigInteger::BigInteger(string name, string bi) : Variable(name, 0)
{
	setDataType(dataType::BIGINT);
	val = bi;
}

Variable* BigInteger::operator+(Variable* arg)
{
	//if(this->_is_negative) {
	//	if((BigInteger*)arg->_is_negative) return -(-*this+(-right));
	//	else return right-(-left);
	//}
	//else if(right._is_negative) return left-(-right);
	//int carry=0; // флаг переноса из предыдущего разряда
	//for(size_t i=0; i<std::max(left._digits.size(), right._digits.size())||carry!=0; ++i) {
	//	if(i==left._digits.size()) left._digits.push_back(0);
	//	left._digits[i]+=carry+(i<right._digits.size()?right._digits[i]:0);
	//	carry=left._digits[i]>=big_integer::BASE;
	//	if(carry!=0) left._digits[i]-=big_integer::BASE;
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