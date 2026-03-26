
#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
	private:
		int			x;
		int			y;
	
	public:
		vect2();
		vect2(int newX, int newY);
		vect2(const vect2 &copy);
		vect2		&operator=(const vect2 &copy);
		~vect2();

		// UTILS
		int			getX(void)const;
		int			getY(void)const;
		int			&operator[](int i);
		const int	&operator[](int i)const;

		// ADD/SUBTRACT/MULTIPLY
		vect2		&operator+=(vect2 b);
		vect2		&operator-=(vect2 b);
		vect2		&operator*=(vect2 b);
		vect2		&operator*=(int b);
		vect2		&operator++(void);
		vect2		&operator++(int);
		vect2		&operator--(void);
		vect2		&operator--(int);
};

// UTILS
std::ostream		&operator<<(std::ostream &out, const vect2 &copy);

// COMPARE
bool				operator==(vect2 a, vect2 b);
bool				operator!=(vect2 a, vect2 b);

// CALCULATE
vect2				operator+(vect2 a, vect2 b);
vect2				operator-(vect2 a, vect2 b);
vect2				operator-(vect2 a);
vect2				operator*(vect2 a, vect2 b);
vect2				operator*(vect2 a, int b);
vect2				operator*(int a, vect2 b);

#endif
