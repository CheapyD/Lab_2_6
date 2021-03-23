#include "Triangle.h"

////////////////////////////////////////////////////////////
// class Triad

int Triangle::Triad::counter = 0;

Triangle::Triad::Triad()
	: a(0), b(0), c(0)
{
	Triangle::Triad::counter++;
}

Triangle::Triad::Triad(const double A, const double B, const double C)
	: a(A), b(B), c(C)
{
	Triangle::Triad::counter++;
}

Triangle::Triad::Triad(const Triad& v)
	: a(v.a), b(v.b), c(v.c)
{
	Triangle::Triad::counter++;
}

Triangle::Triad::~Triad(void)
{
	Triangle::Triad::counter--;
}

Triangle::Triad& Triangle::Triad::operator = (const Triad& n)
{
	a = n.a;
	b = n.b;
	c = n.c;
	return *this;
}

Triangle::Triad::operator string () const
{
	stringstream ss;
	ss << endl;
	ss << "a = " << a << endl;
	ss << "b = " << b << endl;
	ss << "c = " << c << endl;
	return ss.str();
}

ostream& operator <<(ostream& out, const Triangle::Triad& s)
{
	return out << string(s);
}

istream& operator >>(istream& in, Triangle::Triad& s)
{
	double a, b, c;
	cout << endl;
	cout << "a = "; in >> a;
	cout << "b = "; in >> b;
	cout << "c = "; in >> c;
	s.SetA(a);
	s.SetB(b);
	s.SetC(c);

	return in;
}

Triangle::Triad& Triangle::Triad::operator --()
{
	--a;
	return *this;
}

Triangle::Triad& Triangle::Triad::operator ++()
{
	++a;
	return *this;
}

Triangle::Triad Triangle::Triad::operator --(int)
{
	Triad a(*this);
	c--;
	return a;
}

Triangle::Triad Triangle::Triad::operator ++(int)
{
	Triad a(*this);
	c++;
	return a;
}

double Triangle::Triad::Sum()
{
	return a + b + c;
}

int Triangle::Triad::getCounter()
{
	return Triangle::Triad::counter;
}

////////////////////////////////////////////////////////////
// class Triangle

int Triangle::counter = 0;

void Triangle::SetA(double value)
{
	if (value > 0)
		triad.SetA(value);
	else
		triad.SetA(0);
}

void Triangle::SetB(double value)
{
	if (value > 0)
		triad.SetB(value);
	else
		triad.SetB(0);
}

void Triangle::SetC(double value)
{
	if (value > 0)
		triad.SetC(value);
	else
		triad.SetC(0);
}

Triangle::Triangle(const double A, const double B, const double C)
{
	if (A + B > C && B + C > A && A + C > B)
	{
		SetA(A);
		SetB(B);
		SetC(C);
	}
	else
	{
		SetA(0);
		SetB(0);
		SetC(0);
	}
	Triangle::counter++;
}

Triangle::Triangle(const Triangle& v)
{
	triad = v.triad;
	Triangle::counter++;
}

Triangle::~Triangle(void)
{
	Triangle::counter--;
}

Triangle& Triangle::operator = (const Triangle& n)
{
	triad = n.triad;
	return *this;
}

Triangle::operator string () const
{
	stringstream ss;
	ss << "triad: " << triad << endl;
	return ss.str();
}

ostream& operator <<(ostream& out, const Triangle& s)
{
	out << string(s);
	return out;
}

istream& operator >>(istream& in, Triangle& s)
{
	cout << endl;
	cout << "triad: " << endl;
	in >> s.triad;
	return in;
}

Triangle& Triangle::operator ++()
{
	++triad;
	return *this;
}

Triangle& Triangle::operator --()
{
	--triad;
	return *this;
}

Triangle Triangle::operator ++(int)
{
	Triangle s(*this);
	triad++;
	return s;
}

Triangle Triangle::operator --(int)
{
	Triangle s(*this);
	triad--;
	return s;
}

double Triangle::Square() const
{
	double a = triad.GetA();
	double b = triad.GetB();
	double c = triad.GetC();
	double p = (a + b + c) / 2;
	double S = sqrt(p * (p - a) * (p - b) * (p - c));
	return S;
}

void Triangle::Angle(double& A, double& B, double& C) const
{
	const double PI = atan(1) * 4;
	double a = triad.GetA();
	double b = triad.GetB();
	double c = triad.GetC();

	double S = Square();

	double sinA = (S * 2) / (a * b);
	double x1 = asin(sinA);
	A = (x1 * 180) / PI;

	double sinB = (sinA * b) / c;
	double x2 = asin(sinB);
	B = (x2 * 180) / PI;

	C = 180 - (A + B);
}

int Triangle::getCounter()
{
	return Triangle::counter;
}
