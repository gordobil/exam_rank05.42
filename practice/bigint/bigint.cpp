
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
	*this = copy; }

bigint	&bigint::operator=(const bigint &copy){
	*this = copy;
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
		
