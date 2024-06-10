#include "BigInteger.h"
#include "Float.h"

using namespace std;



BigInteger::BigInteger(string name) :Variable(name)
{
	setDataType(dataType::BIGINT);
	cout << "введите BigInt: ";
	string str;
	cin >> str;
	turnStrToBi(name, str);
}
BigInteger::BigInteger(string name, string bi) : Variable(name, 0)
{
	setDataType(dataType::BIGINT);
	turnStrToBi(name, bi);
}

BigInteger::BigInteger(Float* arg) {
	if (arg->getVal() < 0)
	{
		this->isNegative=true;
		arg->setVal(-arg->getVal());
	}
	else
		this->isNegative=false;
	do
	{
		this->digits.push_back((int)arg->getVal() % BigInteger::BASE);
		arg->setVal((int)arg->getVal() / BigInteger::BASE);
	} while (arg->getVal() != 0);
}

BigInteger::BigInteger(int val) {
	if (val < 0)
	{
		this->isNegative=true;
		val=-val;
	}
	else
		this->isNegative=false;
	do
	{
		this->digits.push_back(val % BigInteger::BASE);
		val/=BigInteger::BASE;
	} while (val != 0);
}

BigInteger::BigInteger()
{
	isNegative=false;
}

BigInteger* BigInteger::operator +() {
	return this;
}

BigInteger* BigInteger::operator -() {
	isNegative=!isNegative;
	return this;
}

bool operator ==(BigInteger& left, BigInteger& right) {
	// числа разных знаков точно не равны
	if (left.getNegative() != right.getNegative()) return false;
	// поскольку у нас два представления нуля, нужно это особо обработать
	if (left.getDigits().empty()) {
		if (right.getDigits().empty() || (right.getDigits().size() == 1 && right.getDigits()[0] == 0)) return true;
		else return false;
	}

	if (right.getDigits().empty()) {
		if (left.getDigits().size() == 1 && left.getDigits()[0] == 0) return true;
		else return false;
	}
	// так как у нас нет ведущих нулей, то в числах должно быть одинаковое количество цифр (разрядов)
	if (left.getDigits().size() != right.getDigits().size()) return false;
	for (size_t i=0; i < left.getDigits().size(); ++i) if (left.getDigits()[i] != right.getDigits()[i]) return false;

	return true;
}

bool operator <(BigInteger& left, BigInteger& right) {
	if (left == right) return false;
	if (left.getNegative()) {
		if (right.getNegative()) return ((-right) < (-left));
		else return true;
	}
	else if (right.getNegative()) return false;
	else {
		if (left.getDigits().size() != right.getDigits().size()) {
			return left.getDigits().size() < right.getDigits().size();
		}
		else {
			for (long long i=left.getDigits().size() - 1; i >= 0; --i) {
				if (left.getDigits()[i] != right.getDigits()[i]) return left.getDigits()[i] < right.getDigits()[i];
			}
			return false;
		}
	}
}

bool operator !=(BigInteger& left, BigInteger& right) {
	return !(left == right);
}

bool operator <=(BigInteger& left, BigInteger& right) {
	return (left < right || left == right);
}

bool operator >(BigInteger& left, BigInteger& right) {
	return !(left <= right);
}

bool operator >=(BigInteger& left, BigInteger& right) {
	return !(left < right);
}

Variable* BigInteger::operator+(Float* arg)
{
	BigInteger* tmp=new BigInteger(arg);
	BigInteger* result=new BigInteger();
	*result=*(BigInteger*)(operator+(tmp));
	delete tmp;
	return result;
}

Variable* BigInteger::operator+(Variable* arg)
{
	BigInteger* result=new BigInteger();
	*result=*this;
	if (dynamic_cast<BigInteger*>(arg))
	{
		BigInteger* tmpArg=(BigInteger*)arg;
		if (isNegative) {
			if (tmpArg->isNegative)
			{
				result->operator-();
				tmpArg->operator-();
				*result=*(BigInteger*)(result->operator+(tmpArg));
				result->operator-();
			}
			else
				*result=*(BigInteger*)(*tmpArg - (-*result));
			return result;
		}
		else if (tmpArg->isNegative) return *result - (-*(BigInteger*)(tmpArg));
		int carry=0; // флаг переноса из предыдущего разряда
		for (size_t i=0; i < std::max(result->digits.size(), tmpArg->digits.size()) || carry != 0; i++) {
			if (i == result->digits.size())
				result->digits.push_back(0);
			result->digits[i]+=carry + (i < tmpArg->digits.size() ? tmpArg->digits[i] : 0);
			carry=result->digits[i] >= BigInteger::BASE;
			if (carry != 0) result->digits[i]-=BigInteger::BASE;
		}
		return result;
	}
	else
	{
		return result->operator+((Float*)arg);
	}
}




Variable* BigInteger::operator*(Variable* arg)
{
	BigInteger* result=new BigInteger();
	if (dynamic_cast<BigInteger*>(arg))
	{
		BigInteger* tmpArg=(BigInteger*)arg;
		result->digits.resize(this->digits.size() + tmpArg->digits.size());
		if (!this->isInverted)
		{
			for (size_t i=0; i < this->digits.size(); ++i) {
				int carry=0;
				for (size_t j=0; j < tmpArg->digits.size() || carry != 0; ++j) {
					long long cur=result->digits[i + j] +
						this->digits[i] * 1LL * (j < tmpArg->digits.size() ? tmpArg->digits[j] : 0) + carry;
					result->digits[i + j]=static_cast<int>(cur % BigInteger::BASE);
					carry=static_cast<int>(cur / BigInteger::BASE);
				}
			}
		}
		else
		{
			BigInteger tmpThis=*this;
			tmpThis.isInverted=false;
			*result=*((BigInteger*)(tmpArg->operator/(&tmpThis)));
		}
		result->isNegative=this->isNegative != tmpArg->isNegative;
		result->removeLeadingZeros();
		return result;
	}
	else
	{
		return result->operator*((Float*)arg);
	}
}

Variable* BigInteger::operator*(Float* arg)
{
	BigInteger* tmp=new BigInteger(arg);
	BigInteger* result=new BigInteger();
	*result=*(BigInteger*)(operator*(tmp));
	delete tmp;
	return result;
}

Variable* BigInteger::operator*(int arg)
{
	BigInteger* tmp=new BigInteger(arg);
	BigInteger* result=new BigInteger();
	*result=*(BigInteger*)(operator*(tmp));
	delete tmp;
	return result;
}



Variable* BigInteger::operator-(Variable* arg)
{
	BigInteger* result=new BigInteger();
	*result=*this;
	if (dynamic_cast<BigInteger*>(arg))
	{
		if (result->isNegative) return result->operator+(-*(BigInteger*)arg);
		else if (((BigInteger*)arg)->isNegative) return -*(-*(BigInteger*)result->operator+(arg));
		else if (*result < *(BigInteger*)arg) return -*(BigInteger*)(*(BigInteger*)arg - result);
		int carry=0;
		for (size_t i=0; i < ((BigInteger*)arg)->digits.size() || carry != 0; ++i) {
			result->digits[i]-=carry + (i < ((BigInteger*)arg)->digits.size() ? ((BigInteger*)arg)->digits[i] : 0);
			carry=result->digits[i] < 0;
			if (carry != 0) result->digits[i]+=BigInteger::BASE;
		}

		result->removeLeadingZeros();
		return result;
	}
	else
	{
		return result->operator-((Float*)arg);
	}
}

Variable* BigInteger::operator-(Float* arg)
{
	BigInteger* tmp=new BigInteger(arg);
	BigInteger* result=new BigInteger();
	*result=*(BigInteger*)(operator-(tmp));
	delete tmp;
	return result;
}

Variable* BigInteger::operator/(Variable* arg)
{
	BigInteger null(0);
	BigInteger* result=new BigInteger();
	if (dynamic_cast<BigInteger*>(arg))
	{
		BigInteger* tmpArg=(BigInteger*)arg;
		if (*tmpArg == null)
			throw Exceptions(COMPUTE::DIVISION_BY_ZERO);
		tmpArg->isNegative=false;
		BigInteger current;
		result->digits.resize(this->digits.size());
		signed long long i=static_cast<signed long long>(this->digits.size()) - 1;
		for (; i >= 0; i--) {
			current.shiftRight();
			current.digits[0]=this->digits[i];
			current.removeLeadingZeros();
			int x=0, l=0, r=current.digits[0];
			while (l < r) {
				int m=(l + r) / 2;
				BigInteger* t, copy;
				copy=*tmpArg;
				tmpArg=(BigInteger*)arg;
				t=(BigInteger*)(copy * (m));
				if (*t <= current) {
					x=m;
 					l=m;
				}
				else r=m - 1;
			}
			result->digits[i]=l;
			current=*(BigInteger*)(current - *tmpArg * x);
		}

		result->isNegative=this->isNegative != tmpArg->isNegative;
		result->removeLeadingZeros();
		return result;
	}
	else
	{
		return result->operator/((Float*)arg);
	}
}

Variable* BigInteger::operator/(Float* arg)
{
	BigInteger* tmp=new BigInteger(arg);
	BigInteger* result=new BigInteger();
	*result=*(BigInteger*)(operator/(tmp));
	delete tmp;
	return this;
}

bool BigInteger::odd() {
	if (this->digits.size() == 0) return false;
	return this->digits[0] & 1;
}

bool BigInteger::even() {
	return !this->odd();
}

Variable* BigInteger::toUpDegree(Variable* arg)
{
	BigInteger* result=new BigInteger(1);
	if (dynamic_cast<BigInteger*>(arg))
	{
		BigInteger tmpArg=*(BigInteger*)arg;
		while (tmpArg.digits[0] > 0) {
			result->operator*=(this);
			tmpArg.digits[0]-=1;
		}
		if (tmpArg.isNegative)
		{
			result->isInverted=true;
		}
		return result;
	}
	else
	{
		toUpDegree((Float*)arg);
	}
}

Variable* BigInteger::toUpDegree(Float* arg)
{
	BigInteger* tmp=new BigInteger(arg);
	BigInteger* result=new BigInteger();
	*result=*(BigInteger*)(toUpDegree(tmp));
	delete tmp;
	return result;
}

void BigInteger::removeLeadingZeros() {
	while (digits.size() > 1 && digits.back() == 0) {
		digits.pop_back();
	}
	if (digits.size() == 1 && digits[0] == 0) isNegative=false;
}

void BigInteger::shiftRight() {
	if (this->digits.size() == 0) {
		this->digits.push_back(0);
		return;
	}
	this->digits.push_back(this->digits[this->digits.size() - 1]);
	// здесь размер массива равен как минимум двум и перебор идет до предпоследнего разряда,
	// поэтому i имеет "верный" тип size_t
	for (long long i=this->digits.size() - 2; i > 0; i--) this->digits[i]=this->digits[i - 1];
	this->digits[0]=0;
}

BigInteger* BigInteger::operator /=(BigInteger* value) {
	*this=*(BigInteger*)(this->operator/((Variable*)(value)));
	return this;
}

BigInteger* BigInteger::operator *=(BigInteger* value) {
	*this=*(BigInteger*)this->operator*(value);
	return this;
}

void BigInteger::print(Variable* arg)
{
	if (arg)
	{
		BigInteger* tmp=(BigInteger*)arg;
		if (tmp->digits.empty())
			cout << 0;
		else {
			if (tmp->isNegative)
				cout << '-';
			long long len=(long long)(tmp->digits.size());
			for (long long i=len - 1; i >= 0; i--) {
				cout << tmp->digits[i];
			}
		}
	}
	else
	{
		if (digits.empty())
			cout << 0;
		else {
			if (isNegative)
				cout << '-';
			long long len=(long long)(digits.size());
			for (long long i=len - 1; i >= 0; i--) {
				cout << digits[i];
			}
		}
	}
}


void BigInteger::turnStrToBi(std::string name, std::string bi)
{
	if (bi.length() == 0) {
		isNegative=false;
	}
	else {
		if (bi[0] == '-') {
			bi=bi.substr(1);
			isNegative=true;
		}
		else {
			isNegative=false;
		}
		for (long long i=bi.length(); i > 0; i-=9) {
			if (i < 9)
				digits.push_back(atoi(bi.substr(0, i).c_str()));
			else
				digits.push_back(atoi(bi.substr(i - 9, 9).c_str()));
		}
		removeLeadingZeros();
	}
}

bool BigInteger::getNegative()
{
	return isNegative;
}

std::vector<int> BigInteger::getDigits()
{
	return digits;
}
