#include "Triangle.h"

int main()
{
	Triangle N(3, 4, 5);

	double A = 0.0;
	double B = 0.0;
	double C = 0.0;
	double S = N.Square();
	cout << "Square = " << S << endl;

	N.Angle(A, B, C);
	cout << "Angle A = " << A << endl;
	cout << "Angle B = " << B << endl;
	cout << "Angle C = " << C << endl << endl;

	cout << "Size of class = " << sizeof(N) << endl << endl;

	cout << "Triangle: " << Triangle::getCounter() << endl;
	cout << "Triangle::Triad: " << Triangle::Triad::getCounter() << endl << endl;

	Triangle::Triad K(-15, 34, 1.8);
	cout << "S = " << K.Sum() << endl << endl;

	cout << "Triangle::Triad + 1: " << Triangle::Triad::getCounter() << endl;
	{
		Triangle s(3, 5, 7);
		cout << "Triangle local: " << Triangle::getCounter() << endl;
		cout << "Triangle::Triad local: " << Triangle::Triad::getCounter() << endl;
		Triangle::Triad m;
		cout << "Triangle::Triad local + 1: " << Triangle::Triad::getCounter() << endl;
	}

	cout << "Triangle : " << Triangle::getCounter() << endl;
	cout << "Triangle::Triad: " << Triangle::Triad::getCounter() << endl << endl;

	cout << "++K: " << ++K << endl;
	cout << "--K: " << --K << endl;
	cout << "K++: " << K++ << endl;
	cout << "K--: " << K-- << endl << endl;
}