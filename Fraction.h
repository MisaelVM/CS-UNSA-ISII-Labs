#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cmath>
#include <sstream>

class Fraction {
private:
	int numerator;
	int denominator;

	const int gcd(const int a, const int b);

public:
	Fraction() = default;
	Fraction(const int num, const int den = 1);
	Fraction(const Fraction& o);

	float toFloat() const;
	double toDouble() const;

	friend Fraction pow(Fraction& _Xx, double _Yx);
	friend double pow(double _Xx, Fraction& _Yx);
	friend double pow(Fraction& _Xx, Fraction& _Yx);

	friend std::istream& operator >> (std::istream& input, Fraction& o);
	friend std::ostream& operator << (std::ostream& output, const Fraction& o);

	Fraction operator + (const Fraction& o);
	Fraction operator - (const Fraction& o);
	Fraction operator * (const Fraction& o);
	Fraction operator / (const Fraction& o);

	Fraction& operator += (const Fraction& o);
	Fraction& operator -= (const Fraction& o);
	Fraction& operator *= (const Fraction& o);
	Fraction& operator /= (const Fraction& o);

	Fraction& operator ++ ();
	Fraction operator ++ (int);
	Fraction& operator -- ();
	Fraction operator -- (int);

	bool operator == (const Fraction& o) const;
	bool operator != (const Fraction& o) const;
	bool operator < (const Fraction& o) const;
	bool operator > (const Fraction& o) const;
	bool operator <= (const Fraction& o) const;
	bool operator >= (const Fraction& o) const;

	Fraction& operator = (const Fraction& o);
};

#endif
