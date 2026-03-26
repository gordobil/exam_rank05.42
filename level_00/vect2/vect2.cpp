
#include "vect2.hpp"

vect2::vect2(): x(0), y(0) {}

vect2::vect2(int newX, int newY): x(newX), y(newY) {}

vect2::vect2(const vect2 &copy): x(copy.getX()), y(copy.getY()) {}

vect2			&vect2::operator=(const vect2 &copy){
	x = copy.getX();
	y = copy.getY();
	return (*this);
}

vect2::~vect2(){}


// UTILS

int				vect2::getX(void)const{
	return (x); }
	
int				vect2::getY(void)const{
	return (y); }

std::ostream	&operator<<(std::ostream &out, const vect2 &copy){
	out << "{" << copy.getX() << ", " << copy.getY() << "}" << std::endl;
	return (out);
}

int				&vect2::operator[](int i){
	if (i == 0)
		return (x);
	return (y);
}

const int		&vect2::operator[](int i)const{
	if (i == 0)
		return (x);
	return (y);
}

// COMPARE

bool			operator==(vect2 a, vect2 b){
	if (a.getX() == b.getX() && a.getY() == b.getY())
		return (true);
	return (false);
}

bool			operator!=(vect2 a, vect2 b){
	if (a.getX() == b.getX() && a.getY() == b.getY())
		return (false);
	return (true);
}


// CALCULATE

vect2			operator+(vect2 a, vect2 b){
	return (vect2(a.getX() + b.getX(), a.getY() + b.getY()));
}

vect2			operator-(vect2 a, vect2 b){
	return (vect2(a.getX() - b.getX(), a.getY() - b.getY()));
}

vect2			operator-(vect2 a){
	return (vect2(a.getX() * -1 , a.getY() * -1));
}

vect2			operator*(vect2 a, vect2 b){
	return (vect2(a.getX() * b.getX(), a.getY() * b.getY()));
}

vect2			operator*(vect2 a, int b){
	return (vect2(a.getX() * b, a.getY() * b));
}

vect2			operator*(int a, vect2 b){
	return (vect2(a * b.getX(), a * b.getY()));
}


// ADD/SUBTRACT

vect2			&vect2::operator+=(vect2 b){
	*this = *this + b;
	return (*this);
}

vect2			&vect2::operator-=(vect2 b){
	*this = *this - b;
	return (*this);
}

vect2			&vect2::operator*=(vect2 b){
	*this = *this * b;
	return (*this);
}

vect2			&vect2::operator*=(int b){
	*this = *this * b;
	return (*this);
}

vect2			&vect2::operator++(void){
	*this = *this + vect2(1, 1);
	return (*this);
}

vect2			&vect2::operator++(int){
	vect2	ret = *this;
	ret = *this + vect2(1, 1);
	return (*this);
}

vect2			&vect2::operator--(void){
	*this = *this - vect2(1, 1);
	return (*this);
}

vect2			&vect2::operator--(int){
	vect2	ret = *this;
	ret = *this - vect2(1, 1);
	return (*this);
}
