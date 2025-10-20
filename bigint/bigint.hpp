
#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <sstream>

class bigint
{
	private:
		std::string	str;
	
	public:
		bigint();
		bigint(unsigned int n);
		bigint(std::string n);
		bigint(const bigint &copy);
		bigint 		&operator=(const bigint &copy);
		~bigint();

		//UTILS
		void		checkStr(std::string n);
		std::string	getStr(void)const;

		//ALTER
		bigint		&operator<<=(int add);
		bigint		&operator>>=(int rm);
		bigint		&operator+=(int rm);
		bigint		&operator++(void);
		bigint		&operator++(int);
};

//NEW BIGINT
bigint				operator<<(const bigint &var, int add);
bigint				operator>>(const bigint &var, int rm);
bigint				operator+(const bigint &var);

//COMPARE
bool				operator==(const bigint &a, const bigint &b);
bool 				operator!=(const bigint &a, const bigint &b);
bool 				operator>(const bigint &a, const bigint &b);
bool 				operator>=(const bigint &a, const bigint &b);
bool 				operator<(const bigint &a, const bigint &b);
bool 				operator<=(const bigint &a, const bigint &b);

//UTILS
std::string			intToStr(int n);
int					compare(std::string a, std::string b);
std::ostream		&operator<<(std::ostream &out, const bigint &var);

#endif
