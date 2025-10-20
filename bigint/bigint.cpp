
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
	std::string	newStr;

	std::stringstream strS;
	strS << n;
	newStr = strS.str();

	return (newStr);
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
bigint	&bigint::operator+=(int rm){}
bigint	&bigint::operator++(void){}
bigint	&bigint::operator++(int){}
bigint	&bigint::operator<<=(int add){}
bigint	&bigint::operator>>=(int rm){}

// NEW BIGINT
bigint	operator<<(const bigint &var, int add){
	if (add <= 0 || var.getStr() == "0")
		return (var);
	
	return (bigint(var.getStr().append(add, '0')));
}

bigint	operator>>(const bigint &var, int rm){
	if (rm <= 0 || var.getStr() == "0")
		return (var);
	if (rm >= var.getStr().size())
		return (bigint(0));
	
	return (bigint(var.getStr().erase(var.getStr().size() - rm)));
}

bigint	operator+(const bigint &var){}

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
