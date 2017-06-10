

// --------------------------complex.h----------------------------------------
// Pavel Samsonov CSS 342
// 1 April 2017
// 8 April 2017 - Added comments
// ---------------------------------------------------------------------------
// Purpose - A representation of complex numbers. Provides the ability to 
//			 perform basic operations with them: +, -, *, /
// --------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions.
// Far from perfect, not sure how robust it was supposed to be being only 
// program 1. Will work with intended input however is probably easy to break.
// ---------------------------------------------------------------------------


#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;

class Complex
{
public:
	Complex();
	Complex(double real);
	Complex(double real, double img);
	double getReal();
	double getImaginary();
	Complex conjugate();
	Complex add(const Complex&);
	Complex subtract(const Complex&);
	Complex multiply(const Complex&);
	Complex divide(const Complex&);
	Complex operator +(const Complex& rhs);
	Complex operator -(const Complex& rhs);
	Complex operator /(const Complex& rhs);
	Complex operator *(const Complex& rhs);
	Complex operator+=(const Complex & rhs);
	Complex operator-=(const Complex & rhs);
	Complex operator/=(const Complex & rhs);
	Complex operator*=(const Complex & rhs);
	friend bool operator ==(const Complex& lhs, const Complex& rhs);
	friend bool operator !=(const Complex& lhs, const Complex& rhs);
	friend ostream& operator<<(ostream& os, const Complex& obj);
	friend istream& operator >> (istream& is, Complex& obj);
private:
	double m_real;
	double m_imaginary;
};
#endif

