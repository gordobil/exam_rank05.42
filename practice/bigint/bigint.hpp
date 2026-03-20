
#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <sstream>

class bigint
{
	private:
		std::string	num;

	public:
		bigint();
		bigint(std::string newN);
		bigint(unsigned int newN);
		bigint(const bigint &copy);
		bigint		&operator=(const bigint &copy);
		~bigint();

		// DIGITSHIFT
		bigint		&operator<<=(unsigned int b);
		bigint		&operator<<=(const bigint &b);
		bigint		&operator>>=(unsigned int b);
		bigint		&operator>>=(const bigint &b);

		// CALCULATE
		bigint		&operator+=(const bigint &vb);
		bigint		&operator+=(unsigned int b);
		bigint		&operator++(void);
		bigint		&operator++(int);

		// UTILS
		void		checkNum(std::string n);
		std::string	getNum(void)const;
};

// COMPARE
int					compare(std::string a, std::string b);
bool				operator<(const bigint &a, const bigint &b);
bool				operator>(const bigint &a, const bigint &b);
bool				operator<=(const bigint &a, const bigint &b);
bool				operator>=(const bigint &a, const bigint &b);
bool				operator==(const bigint &a, const bigint &b);
bool				operator!=(const bigint &a, const bigint &b);

// DIGITSHIFT
bigint				operator<<(const bigint &a, unsigned int b);
bigint				operator<<(const bigint &a, const bigint &b);
bigint				operator>>(const bigint &a, unsigned int b);
bigint				operator>>(const bigint &a, const bigint &b);

// CALCULATE
bigint				operator+(const bigint &a, const bigint &b);
bigint				operator+(const bigint &a, unsigned int b);
bigint				operator+(unsigned int a, const bigint &b);

// UTILS
std::string			intToStr(unsigned int n);
unsigned int		strToInt(std::string str);
std::ostream		&operator<<(std::ostream &out, const bigint &copy);

#endif
