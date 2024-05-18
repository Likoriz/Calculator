#include "BigInteger.h"
#include "Float.h"

using namespace std;

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
		remove_leading_zeros();
	}
}


BigInteger::BigInteger(string name) :Variable(name)
{
	setDataType(dataType::BIGINT);
	cout << "������� BigInt: ";
	string str;
	cin >> str;
	turnStrToBi(name, str);
}
BigInteger::BigInteger(string name, string bi) : Variable(name, 0)
{
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


BigInteger* BigInteger::operator +() {
	return this;
}

BigInteger* BigInteger::operator -() {
	isNegative=!isNegative;
	return this;
}

bool operator ==(BigInteger& left, BigInteger& right) {
	// ����� ������ ������ ����� �� �����
	if (left.getNegative() != right.getNegative()) return false;
	// ��������� � ��� ��� ������������� ����, ����� ��� ����� ����������
	if (left.getDigits().empty()) {
		if (right.getDigits().empty() || (right.getDigits().size() == 1 && right.getDigits()[0] == 0)) return true;
		else return false;
	}

	if (right.getDigits().empty()) {
		if (left.getDigits().size() == 1 && left.getDigits()[0] == 0) return true;
		else return false;
	}
	// ��� ��� � ��� ��� ������� �����, �� � ������ ������ ���� ���������� ���������� ���� (��������)
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
	this->operator+(tmp);
	delete tmp;
	return this;
}

Variable* BigInteger::operator+(Variable* arg)
{
	if (dynamic_cast<BigInteger*>(arg))
	{
		BigInteger* tmpArg=(BigInteger*)arg;
		if (isNegative) {
			if (this->isNegative) return ((BigInteger*)((this->operator-())->operator+((Variable*)(tmpArg->operator-()))))->operator-();
			else return *tmpArg - (-*this);
		}
		else if (tmpArg->isNegative) return *this - (-*(BigInteger*)(tmpArg));
		int carry=0; // ���� �������� �� ����������� �������
		for (size_t i=0; i < std::max(this->digits.size(), tmpArg->digits.size()) || carry != 0; i++) {
			if (i == this->digits.size())
				this->digits.push_back(0);
			this->digits[i]+=carry + (i < tmpArg->digits.size() ? tmpArg->digits[i] : 0);
			carry=this->digits[i] >= BigInteger::BASE;
			if (carry != 0) this->digits[i]-=BigInteger::BASE;
		}
		return this;
	}
	else
	{
		return this->operator+((Float*)arg);
	}
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
	if (dynamic_cast<BigInteger*>(arg))
	{
		if (this->isNegative) return this->operator+(-*(BigInteger*)arg);
		else if (this->isNegative) return -*(-*(BigInteger*)this->operator+(arg));
		else if (*this < *(BigInteger*)arg) return -*(BigInteger*)(*(BigInteger*)arg - this);
		int carry=0;
		for (size_t i=0; i < ((BigInteger*)arg)->digits.size() || carry != 0; ++i) {
			this->digits[i]-=carry + (i < ((BigInteger*)arg)->digits.size() ? ((BigInteger*)arg)->digits[i] : 0);
			carry=this->digits[i] < 0;
			if (carry != 0) this->digits[i]+=BigInteger::BASE;
		}

		this->remove_leading_zeros();
		return this;
	}
	else
	{
		return this->operator-((Float*)arg);
	}
}

Variable* BigInteger::operator-(Float* arg)
{
	BigInteger* tmp=new BigInteger(arg);
	this->operator-(tmp);
	delete tmp;
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

void BigInteger::remove_leading_zeros() {
	while (digits.size() > 1 && digits.back() == 0) {
		digits.pop_back();
	}
	if (digits.size() == 1 && digits[0] == 0) isNegative=false;
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

bool BigInteger::getNegative()
{
	return isNegative;
}

std::vector<int> BigInteger::getDigits()
{
	return digits;
}
