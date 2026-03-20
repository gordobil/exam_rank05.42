
#include "bigint.hpp"

bigint::bigint(){
	num = intToStr(0); }

bigint::bigint(std::string newN){
	try{
		checkNum(newN);
		num = newN;
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl; }
}

bigint::bigint(unsigned int newN){
	num = intToStr(newN); }

bigint::bigint(const bigint &copy){
	num = copy.getNum(); }

bigint	&bigint::operator=(const bigint &copy){
	num = copy.getNum();
	return (*this); }

bigint::~bigint(){}


// COMPARE

int				compare(std::string a, std::string b){
	if (a.size() < b.size())
	return (-1);

	if(a.size() == b.size()){
		for (int i = 0; i < a.size(); i++){
			if (a[i] < b[i])
			return (-1);
			else if (a[i] > b[i])
				return (1);
		}
		return (0);
	}

	return (1);
}

bool			operator<(const bigint &a, const bigint &b){
	if (compare(a.getNum(), b.getNum()) < 0)
		return (true);
	return (false); }

bool			operator>(const bigint &a, const bigint &b){
		if (compare(a.getNum(), b.getNum()) > 0)
		return (true);
	return (false); }

bool			operator<=(const bigint &a, const bigint &b){
	if (compare(a.getNum(), b.getNum()) <= 0)
		return (true);
	return (false); }

bool			operator>=(const bigint &a, const bigint &b){
	if (compare(a.getNum(), b.getNum()) >= 0)
		return (true);
	return (false); }

bool			operator==(const bigint &a, const bigint &b){
	if (compare(a.getNum(), b.getNum()) == 0)
		return (true);
	return (false); }

bool			operator!=(const bigint &a, const bigint &b){
	if (compare(a.getNum(), b.getNum()) != 0)
		return (true);
	return (false); }


// DIGITSHIFT

bigint			operator<<(const bigint &a, unsigned int b){
	if (b <= 0 || a.getNum().size() <= 0 || a.getNum() == "0")
		return (a);
	
	return (bigint(a.getNum().append(b, '0')));
}

bigint			operator<<(const bigint &a, const bigint &b){
	return (bigint(a.getNum() << strToInt(b.getNum())));
}

bigint			operator>>(const bigint &a, unsigned int b){
	if (b <= 0 || a.getNum().size() <= 0 || a.getNum() == "0")
		return (a);
	else if (b >= a.getNum().size())
		return (bigint(0));

	return (bigint(a.getNum().erase(a.getNum().size() - b)));
}

bigint			operator>>(const bigint &a, const bigint &b){
	return (bigint(a.getNum() >> strToInt(b.getNum())));
}

bigint			&bigint::operator<<=(unsigned int b){
	*this = *this << b;
	return (*this); }

bigint			&bigint::operator<<=(const bigint &b){
	*this = *this << b;
	return (*this); }

bigint			&bigint::operator>>=(unsigned int b){
	*this = *this >> b;
	return (*this); }

bigint			&bigint::operator>>=(const bigint &b){
	*this = *this >> b;
	return (*this); }


// CALCULATE

bigint			operator+(const bigint &a, const bigint &b){
	std::string		c;
	std::string		aStr = a.getNum(), bStr = b.getNum();
	int				ai = aStr.size() - 1, bi = bStr.size() - 1;

	for (int rest = 0; ai >= 0 || bi >= 0 || rest > 0; ai--, bi--){
		int aDig = 0;
		if (ai >= 0)
			aDig = aStr[ai] - '0';
		
		int bDig = 0;
		if (bi >= 0)
			bDig = bStr[bi] - '0';
		
		int add = aDig + bDig + rest;
		rest = add / 10;
		c.insert(c.begin(), (add % 10) + '0');
	}
	return (bigint(c));
}

bigint			operator+(const bigint &a, unsigned int b){
	return (a + bigint(b));
}

bigint			operator+(unsigned int a, const bigint &b){
	return (bigint(a) + b);
}

bigint			&bigint::operator+=(const bigint &b){
	*this = *this + b;
	return (*this);
}

bigint			&bigint::operator+=(unsigned int b){
	*this = *this + bigint(b);
	return (*this);
}

bigint			&bigint::operator++(void){
	*this = *this + bigint(1);
	return (*this);
}

bigint			&bigint::operator++(int){
	bigint	*old = this;
	*this = *this + bigint(1);
	return (*old);
}


// UTILS

void			bigint::checkNum(std::string n){
	for (int i = 0; i < n.size(); i++){
		if (!isdigit(n[i]))
			throw std::runtime_error("Invalid argument.");
	}
}

std::string		bigint::getNum(void)const{
	return (num);
}

std::string		intToStr(unsigned int n){
	std::stringstream	strS;
	std::string			str;

	strS << n;
	strS >> str;

	return (str);
}

unsigned int	strToInt(std::string str){
	std::stringstream	strS(str);
	unsigned int		n;

	strS >> n;
	
	return (n);
}
		
std::ostream	&operator<<(std::ostream &out, const bigint &copy){
	out << copy.getNum();
	return (out);
}
		
