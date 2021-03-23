#pragma once
#pragma pack(1)
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Triangle
{
public:
	class Triad
	{
	private:
		double a, b, c;
		static int counter;

	public:
		double GetA() const { return a; }
		double GetB() const { return b; }
		double GetC() const { return c; }

		void SetA(double value) { a = value; }
		void SetB(double value) { b = value; }
		void SetC(double value) { c = value; }

		Triad();
		Triad(const double a, const double b, const double c);
		Triad(const Triad& s);
		~Triad(void);

		Triad& operator = (const Triad& s);
		operator string () const;

		friend ostream& operator << (ostream& out, const Triad& s);
		friend istream& operator >> (istream& in, Triad& s);

		Triad& operator ++ ();
		Triad& operator -- ();
		Triad operator ++ (int);
		Triad operator -- (int);

		double Sum();

		static int getCounter();
	};
	double GetA() const { return triad.GetA(); }
	double GetB() const { return triad.GetB(); }
	double GetC() const { return triad.GetC(); }

	void SetA(double value);
	void SetB(double value);
	void SetC(double value);

	Triangle(const double a, const double b, const double c);
	Triangle(const Triangle& s);
	~Triangle(void);

	Triangle& operator = (const Triangle& s);
	operator string () const;

	friend ostream& operator << (ostream& out, const Triangle& s);
	friend istream& operator >> (istream& in, Triangle& s);

	Triangle& operator ++ ();
	Triangle& operator -- ();
	Triangle operator ++ (int);
	Triangle operator -- (int);

	double Square() const;
	void Angle(double& A, double& B, double& C) const;

	static int getCounter();
private:
	Triad triad;
	static int counter;
};

