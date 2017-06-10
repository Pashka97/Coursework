#include "complex.h"
#include <iomanip>

//---------------Complex---------------------
//default constructor sets all values to 0
Complex::Complex(): m_real(0), m_imaginary(0)
{
}

//---------------Complex-----------------------------------
//Sets real value to parameter, and imaginary to 0
Complex::Complex(double real): m_real(real), m_imaginary(0)
{
}

//---------------Complex-----------------------------------
//Sets real value to parameter, and imaginary to param
Complex::Complex(double real, double img): m_real(real), m_imaginary(img)
{
}

//--------GetReal--------
double Complex::getReal()
{
	return m_real;
}

//---------GetImaginary-------
double Complex::getImaginary()
{
	return m_imaginary;
}

//---------Conjugate--------
//returns conjugate as a complex object
Complex Complex::conjugate() 
{
	Complex temp(m_real,-1*m_imaginary);
	return temp;
}

//---------------add---------------------
//returns the sum of this object and the param as a new complex object
Complex Complex::add(const Complex& other)
{
	Complex temp;
	temp.m_real = m_real + other.m_real;
	temp.m_imaginary = m_imaginary + other.m_imaginary;
	//double newReal = m_real + other.m_real;
	//double newImg = m_imaginary + other.m_imaginary;
	//Complex temp(newReal, newImg);

	return temp;
}

//---------------subtract---------------------
//returns the value of this object minus the param as a new complex object
Complex Complex::subtract(const Complex& other)
{
	double newReal = m_real - other.m_real;
	double newImg = m_imaginary - other.m_imaginary;
	Complex temp(newReal, newImg);

	return temp;
}

//---------------multiply---------------------
//returns the value of this object times the param as a new complex object
Complex Complex::multiply(const Complex& other)
{
	double newReal = (m_real * other.m_real) - (m_imaginary * other.m_imaginary);
	double newImg = (m_real*other.m_imaginary) + (m_imaginary * other.m_real);
	Complex temp(newReal, newImg);

	return temp;
}

//---------------divide---------------------
//returns the value of this object divided by the param as a new complex object
Complex Complex::divide(const Complex& other)
{
	if (other.m_real == 0) {
		Complex temp(m_real,m_imaginary);
		cout << "CANNOT DIVIDE BY 0" << endl;
		return temp;
	}
	Complex tmp(other);

	Complex numerator = this->multiply(tmp.conjugate());
	Complex denominator(other);
	denominator = denominator.multiply(tmp.conjugate());
		
	double numer = numerator.m_real / denominator.m_real;
	double denom = numerator.m_imaginary / denominator.m_real;

	Complex temp(numer, denom);
	return temp;
}

/*
//All of the following overloads as the same as the
//add, subtract, multiply, divide
//see documentation for those methods
*/
Complex Complex::operator+(const Complex & rhs)
{
	Complex temp;
	temp = this->add(rhs);
	return temp;
}

Complex Complex::operator-(const Complex & rhs)
{
	Complex temp;
	temp = this->subtract(rhs);
	return temp;
}

Complex Complex::operator*(const Complex & rhs)
{
	Complex temp;
	temp = this->multiply(rhs);
	return temp;
}

Complex Complex::operator/(const Complex & rhs)
{
	Complex temp;
	temp = this->divide(rhs);
	return temp;
}

Complex Complex::operator+=(const Complex & rhs)
{
	//Complex temp;
	//temp = this->add(rhs);
	this->m_real += rhs.m_real;
	this->m_imaginary += rhs.m_imaginary;
	return *this;
}

Complex Complex::operator-=(const Complex & rhs)
{
	//Complex temp;
	//temp = this->subtract(rhs);
	this->m_real -= rhs.m_real;
	this->m_imaginary -= rhs.m_imaginary;
	return *this;
}

Complex Complex::operator*=(const Complex & rhs)
{
	Complex temp;
	temp = this->multiply(rhs);
	this->m_real = temp.m_real;
	this->m_imaginary = temp.m_imaginary;
	return *this;
}

Complex Complex::operator/=(const Complex & rhs)
{
	Complex temp;
	temp = this->divide(rhs);
	this->m_real = temp.m_real;
	this->m_imaginary = temp.m_imaginary;
	return *this;
}

//-------------------comparison ==-----------------------
//returns a bool is two complex objects are equal
bool operator==(const Complex & lhs, const Complex & rhs)
{
	if (lhs.m_real == rhs.m_real && lhs.m_imaginary == rhs.m_imaginary) {
		return true;
	}
	return false;
}

//-------------------comparison !=-----------------------
//returns a bool is two complex objects are not equal
bool operator!=(const Complex & lhs, const Complex & rhs)
{
	if (lhs.m_real != rhs.m_real || lhs.m_imaginary != rhs.m_imaginary) {
		return true;
	}
	return false;
}

//-------------------- << -----------------------------
//displays the values of complex in a logical way to the screen
ostream & operator<<(ostream & os, const Complex & obj)
{
	if (obj.m_real == 0 && obj.m_imaginary == 0)
		os  << 0 << endl;
	else if (obj.m_real != 0 && obj.m_imaginary == 0)
		os  << obj.m_real << endl;
	else if (obj.m_real == 0 && obj.m_imaginary != 0) {
		if (obj.m_imaginary == 1)
			os  << "i" << endl;
		else if (obj.m_imaginary == -1)
			os  << "-i" << endl;
		else if (obj.m_imaginary > 0)
			os  << obj.m_imaginary << "i" << endl;
		else if (obj.m_imaginary < 0)
			os  << obj.m_imaginary << "i" << endl;
	}
	else if (obj.m_imaginary == 1)
		os  <<  obj.m_real << "+i" << endl;
	else if (obj.m_imaginary == -1)
		os  << obj.m_real << "-i" << endl;
	else if (obj.m_imaginary > 0)
		os  << obj.m_real << "+" << obj.m_imaginary << "i" << endl;
	else if (obj.m_imaginary < 0)
		os  << obj.m_real << "" << obj.m_imaginary << "i" << endl;

	return os;
}

//------------------- >> --------------------------
//ASSUMPTIONS: User inputs two valid double values
istream & operator >> (istream & is, Complex & obj)
{
	is >> obj.m_real >> obj.m_imaginary;
	return is;
}

/*
int main() {

	Complex c1, c2(1.2, 4.9), c3(2.2, 1.0), c4(-7.0, 9.6), c5(8.1, -4.3),
		c6(0.0, -7.1), c7(6.4), c8(0.0, 1.0), c9(0.0, 4.1), c10(0.0, -1.0), c11;

	cout << "type two doubles for c11: ";
	cin >> c11;

	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;
	cout << "c3 = " << c3 << endl;
	//cout << c10.getReal() << endl << c10.getImaginary() << endl;
	cout << "c4 = " << c4 << endl;
	cout << "c5 = " << c5 << endl;
	cout << "c6 = " << c6 << endl;
	cout << "c7 = " << c7 << endl;
	cout << "c8 = " << c8 << endl;
	cout << "c9 = " << c9 << endl;
	cout << "c10 = " << c10 << endl;
	cout << "c11 = " << c11 << endl;
	
	cout << "c1 + c2 + c3 = " << c1 + c2 + c3 << endl;
	
	cout << "c7 - c8 - c9= " << c7 - c8 - c9 << endl;
	cout << "c2 * 22 = " << c2 * 22 << endl;
	cout << "c2 * c3 = " << c2 * c3 << endl;
	cout << "c2 / c3 = " << c2 / c3 << endl;
	cout << "c2 / c1 = " << c2 / c1 << endl;
	cout << " c2 / c5 = " << c2 / c5 << endl;

	
	cout << "c4 == c4 is " << ((c4 == c4) ? "true" : "false") << endl;
	cout << "c4 != c4 is " << ((c4 != c4) ? "true" : "false") << endl;

	cout << "Conjugate of" << c5 << " is " << c5.conjugate() << endl;
	cout << "Real of" << c3 << " is " << c3.getReal() << endl;
	cout << "Imaginary of" << c4 << " is " << c4.getImaginary() << endl;

	cout << "(c5 += c2) += c3 is " << ((c5 += c2) += c3) << endl;
	cout << "(c5 -= c1) -= c2 is " << ((c5 -= c1) -= c2) << endl;
	cout << "(c5 *= 22) *= 13 is " << ((c5 *= 22) *= 13) << endl;
	cout << "(c5 *= c4) *= c4 is " << ((c5 *= c4) *= c4) << endl;
	cout << "(c3 /= 2) / c3 is " << ((c3 /= 2) / c3) << endl;
	cout << "c4 is " << c4 << endl;
	cout << "(c4 /= c1) / c1 is " << ((c4 /= c1) / c1) << endl;
	cout << "c4 is " << c4 << endl;
	
	
}
*/