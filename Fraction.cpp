#include "Fraction.h"

Fraction::Fraction(int num, int den) {
	numerator = num / gcd(num, den);
	denominator = den / gcd(num, den);

	if (denominator < 0) {
		numerator *= -1;
		denominator *= -1;
	}
}

Fraction::Fraction(const Fraction& o) {
	numerator = o.numerator / gcd(o.numerator, o.denominator);
	denominator = o.denominator / gcd(o.numerator, o.denominator);

	if (denominator < 0) {
		numerator *= -1;
		denominator *= -1;
	}
}

const int Fraction::gcd(const int a, const int b) {
	return b == 0 ? a : gcd(b, a % b);
}

float Fraction::toFloat() const {
	return (float)numerator / (float)denominator;
}

double Fraction::toDouble() const {
	return (double)numerator / (double)denominator;
}

Fraction pow(Fraction& _Xx, double _Yx) {
	if (_Yx > 0)
		return Fraction((const int)pow(_Xx.numerator, _Yx), (const int)pow(_Xx.denominator, _Yx));
	else
		return Fraction((const int)pow(_Xx.denominator, _Yx * -1), (const int)pow(_Xx.numerator, _Yx * -1));
}

double pow(double _Xx, Fraction& _Yx) {
	return pow(pow(_Xx, 1 / (double)_Yx.denominator), (double)_Yx.numerator);
}

double pow(Fraction& _Xx, Fraction& _Yx) {
	return pow(_Xx.numerator, _Yx) / pow(_Xx.denominator, _Yx);
}

std::istream& operator >> (std::istream& input, Fraction& o) {
	std::string stream;
	int num, den;

	std::size_t pos = 0;
	std::string token;

	std::stringstream sn;
	std::stringstream sd;

	input >> stream;

	pos = stream.find("/");
	token = stream.substr(0, pos);
	sn << token; sn >> num;
	stream.erase(0, pos + 1);
	sd << stream; sd >> den;

	if (pos > stream.length())
		den = 1;

	if (den < 0) {
		num *= -1;
		den *= -1;
	}

	int GCD = o.gcd(num, den);

	o.numerator = num / GCD;
	o.denominator = den / GCD;

	return input;
}

std::ostream& operator << (std::ostream& output, const Fraction& o) {
	output << o.numerator;
	if (o.denominator != 1)
		output << "/" << o.denominator;
	return output;
}

Fraction Fraction::operator + (const Fraction& o) {
	return Fraction(numerator * o.denominator + denominator * o.numerator, denominator * o.denominator);
}

Fraction Fraction::operator - (const Fraction& o) {
	return Fraction(numerator * o.denominator - denominator * o.numerator, denominator * o.denominator);
}

Fraction Fraction::operator * (const Fraction& o) {
	return Fraction(numerator * o.numerator, denominator * o.denominator);
}

Fraction Fraction::operator / (const Fraction& o) {
	return Fraction(numerator * o.denominator, denominator * o.numerator);
}

Fraction& Fraction::operator += (const Fraction& o) {
	*this = *this + o;
	return *this;
}

Fraction& Fraction::operator -= (const Fraction& o) {
	*this = *this - o;
	return *this;
}

Fraction& Fraction::operator *= (const Fraction& o) {
	*this = *this * o;
	return *this;
}

Fraction& Fraction::operator /= (const Fraction& o) {
	*this = *this / o;
	return *this;
}

Fraction& Fraction::operator ++ () {
	*this = *this + 1;
	return *this;
}

Fraction Fraction::operator ++ (int) {
	Fraction f = *this;
	*this = *this + 1;
	return f;
}

Fraction& Fraction::operator -- () {
	*this = *this - 1;
	return *this;
}

Fraction Fraction::operator -- (int) {
	Fraction f = *this;
	*this = *this - 1;
	return f;
}

bool Fraction::operator == (const Fraction& o) const {
	return (numerator == o.numerator) && (denominator == o.denominator);
}

bool Fraction::operator != (const Fraction& o) const {
	return !(*this == o);
}

bool Fraction::operator < (const Fraction& o) const {
	return (numerator * o.denominator < denominator* o.numerator);
}

bool Fraction::operator > (const Fraction& o) const {
	return o < *this;
}

bool Fraction::operator <= (const Fraction& o) const {
	return !(o < *this);
}

bool Fraction::operator >= (const Fraction& o) const {
	return !(*this < o);
}

Fraction& Fraction::operator = (const Fraction& o) {
	numerator = o.numerator / gcd(o.numerator, o.denominator);
	denominator = o.denominator / gcd(o.numerator, o.denominator);

	if (denominator < 0) {
		numerator *= -1;
		denominator *= -1;
	}

	return *this;
}
