#include <iostream>

using namespace std;

class Fraction
{	
public:
	Fraction(int = 0, int = 1);
	Fraction Add(const Fraction &) const;
	Fraction Sub(const Fraction &) const;
	Fraction Mult(const Fraction &) const;
	Fraction Div(const Fraction &) const;
	void Print() const;
	void Change(int, int);

private:
	int a, b;
	int Nod(int, int) const;
};

int main()
{
	Fraction R1(2, 4), R2(1, 4), R3;
	
	cout << "First fraction: ";
	R1.Print();
	cout << endl;
	cout << "Second fraction: ";
	R2.Print();
	cout << endl;
	cout << "Result of actions: " << endl << endl;
	R3 = R1.Add(R2);
	cout << "Addition result: ";
	R3.Print();
	cout << endl;
	R3 = R1.Sub(R2);
	cout << "Subtraction result: ";
	R3.Print();
	cout << endl;
	R3 = R1.Mult(R2);
	cout << "The result of the multiplication: ";
	R3.Print();
	cout << endl;
	R3 = R1.Div(R2);
	cout << "Division Result: ";
	R3.Print();
	cout << endl;

	system("pause");
	return 0;
}

Fraction::Fraction(int Numerator, int Denominator)
{
	a = Numerator;
	if (Denominator)
	{
		b = Denominator;
	}
	else
	{
		cout << "Can't divide by zero!" << endl;
	}
}

Fraction Fraction::Add(const Fraction &s) const
{
	int c;
	Fraction Sum;
	Sum.a = a * s.b + b * s.a;
	Sum.b = b * s.b;
	if (Sum.a > Sum.b)
	{
		c = Nod(Sum.b, Sum.a);
	}	
	else
	{
		c = Nod(Sum.b, Sum.a);
	}
	Sum.a = Sum.a / c;
	Sum.b = Sum.b / c;
	return Sum;
}

Fraction Fraction::Sub(const Fraction &s) const
{
	int c;
	Fraction Sum;
	Sum.a = a * s.b - b * s.a;
	Sum.b = b * s.b;
	if (Sum.a > Sum.b)
	{
		c = Nod(Sum.b, Sum.a);
	}
	else
	{
		c = Nod(Sum.b, Sum.a);
	}
	Sum.a = Sum.a / c;
	Sum.b = Sum.b / c;
	return Sum;
}

Fraction Fraction::Mult(const Fraction &s) const
{
	int c;
	Fraction Sum;
	Sum.a = a * s.a;
	Sum.b = b * s.b;
	if (Sum.a > Sum.b)
	{
		c = Nod(Sum.b, Sum.a);
	}
	else
	{
		c = Nod(Sum.b, Sum.a);
	}
	Sum.a = Sum.a / c;
	Sum.b = Sum.b / c;
	return Sum;
}

Fraction Fraction::Div(const Fraction &s) const
{
	int c;
	Fraction Sum;
	Sum.a = a * s.b;
	Sum.b = b * s.a;
	if (s.a == 0)
	{
		cout << "Can't divide by zero!" << endl;
	}

	if (Sum.a > Sum.b)
	{
		c = Nod(Sum.b, Sum.a);
	}
	else
	{
		c = Nod(Sum.b, Sum.a);
	}
	Sum.a = Sum.a / c;
	Sum.b = Sum.b / c;
	return Sum;
}
void Fraction::Print() const
{
	cout << a << "/" << b << endl;
}
void Fraction::Change(int d, int e)
{
	int f;
	a = d;
	if (e)
		b = e;
	else
	{
		cout << "Can't divide by zero!" << endl;
	}
	if (a > b)
	{
		f = Nod(a, b);
	}
	else
	{
		f = Nod(b, a);
	}
	a = a / f;
	b = b / f;
}

int Fraction::Nod(int c, int d) const
{
	if (d == 0)
	{
		return c;
	}
	if (c % d == 0)
	{
		return 1;
	}
	return Nod(d, c % d);
}
