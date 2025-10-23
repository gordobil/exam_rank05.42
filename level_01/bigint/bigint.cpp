
#include "bigint.hpp"

bigint::bigint(){
	str = intToStr(0);
}

bigint::bigint(unsigned int n){
	str = intToStr(n);
}

bigint::bigint(std::string n){
	try{
		checkStr(n);
		str = n;
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;}
}

bigint::bigint(const bigint &copy){
	str = copy.str;
}

bigint	&bigint::operator=(const bigint &copy){
	str = copy.str;
	return (*this);
}

bigint::~bigint(){}

// UTILS
void	bigint::checkStr(std::string n){
	for (int i = 0; i < n.size(); i++){
		if (!isdigit(n[i]))
			throw std::runtime_error("Invalid argument.");
	}
}

std::string	bigint::getStr(void)const{
	return (str);
}

std::string	intToStr(int n){
	std::stringstream	strS;
	std::string			newStr;

	strS << n;
	newStr = strS.str();

	return (newStr);
}

unsigned int	strToInt(std::string str){
	std::stringstream	strS(str);
	unsigned int		n;

	strS >> n;

	return (n);
}

int	compare(std::string a, std::string b){
	if (a == b)
		return (0);

	if (a.size() > b.size())
		return (1);
	else if (a.size() < b.size())
		return (-1);

	if (a > b)
		return (1);
	else if (a < b)
		return (-1);

	return (-2);
}

std::ostream	&operator<<(std::ostream &out, const bigint &bigint){
	out << bigint.getStr();
	return (out);
}

// ALTER
bigint	&bigint::operator+=(const bigint &var){
	*this = *this + var;
	return (*this);
}
bigint	&bigint::operator++(void){
	*this = *this + bigint(1);
	return (*this);
}

bigint	&bigint::operator++(int){
	bigint *ret = this;
	*this = *this + bigint(1);
	return (*ret);
}

bigint	&bigint::operator<<=(int add){
	*this = *this << add;
	return (*this);
}

bigint	&bigint::operator<<=(const bigint &add){
	*this = *this << strToInt(add.getStr());
	return (*this);
}

bigint	&bigint::operator>>=(int rm){
	*this = *this >> rm;
	return (*this);
}

bigint	&bigint::operator>>=(const bigint &rm){
	*this = *this >> strToInt(rm.getStr());
	return (*this);
}

// NEW BIGINT
bigint	operator<<(const bigint &var, int add){
	if (add <= 0 || var.getStr() == "0")
		return (var);
	
	return (bigint(var.getStr().append(add, '0')));
}

bigint	operator<<(const bigint &var, const bigint &add){
	bigint	ret = var << strToInt(add.getStr());
	return (ret);
}

bigint	operator>>(const bigint &var, int rm){
	if (rm <= 0 || var.getStr() == "0")
		return (var);
	if (rm >= var.getStr().size())
		return (bigint(0));
	
	return (bigint(var.getStr().erase(var.getStr().size() - rm)));
}

bigint	operator>>(const bigint &var, const bigint &rm){
	bigint	ret = var << strToInt(rm.getStr());
	return (ret);
}

bigint	operator+(const bigint &a, const bigint &b){
	std::string	aStr = a.getStr();
	std::string	bStr = b.getStr();
	std::string	ret;
	int			ai = aStr.size() - 1;
	int			bi = bStr.size() - 1;

	for (int rest = 0; ai >= 0 || bi >= 0 || rest > 0; ai--, bi--){
		int		aDig = 0;
		if (ai >= 0)
			aDig = aStr[ai] - '0';

		int		bDig = 0;
		if (bi >= 0)
			bDig = bStr[bi] - '0';

		int		add = aDig + bDig + rest;
		int		retDig = add % 10;
		rest = add / 10;

		ret.push_back(static_cast<char>(retDig + '0'));
	}
	std::reverse(ret.begin(), ret.end());
	return (bigint(ret));
}

// COMPARE
bool	operator==(const bigint &a, const bigint &b){
	if (compare(a.getStr(), b.getStr()) == 0)
		return (true);
	return (false);
}

bool	operator!=(const bigint &a, const bigint &b){
	if (compare(a.getStr(), b.getStr()) != 0)
		return (true);
	return (false);
}

bool	operator>(const bigint &a, const bigint &b){
	if (compare(a.getStr(), b.getStr()) == 1)
		return (true);
	return (false);
}

bool	operator>=(const bigint &a, const bigint &b){
	if (compare(a.getStr(), b.getStr()) >= 0)
		return (true);
	return (false);
}

bool	operator<(const bigint &a, const bigint &b){
	if (compare(a.getStr(), b.getStr()) == -1)
		return (true);
	return (false);
}

bool	operator<=(const bigint &a, const bigint &b){
	if (compare(a.getStr(), b.getStr()) <= 0)
		return (true);
	return (false);
}
