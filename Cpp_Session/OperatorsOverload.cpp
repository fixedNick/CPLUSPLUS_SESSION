#include "OperatorsOverload.h"
#include <iostream>

/*
	����������� ���������� �������� ��������������� ������ �������� ��� ������ ������ ���������.
	�������� ��� ������ + ����� ���������� ��������� ( ��� ������ �� ������, ����� ��������� ������ ������ ��������� )
	����� ������� �������� ����� ��������������� ���������� ��� �������� ���������� ����� ����� ����� ��������� � ��������� ������ �������
	��� ���� ������ ��������� +.
*/

using namespace std;

// ������ ���������� ��������� +, ��� �������� ���� ����� ������ �������� ����� ����� � �������� �� ���� ������ ������ �������.
struct Complex
{
public:
	Complex(double n1, double n2);
	Complex operator +(Complex& otherComplex); // Complex + Complex&
	Complex operator +(int val); // Complex + int
	Complex operator +(double val); // Complex + double
	void operator +=(Complex other);

	bool operator ==(Complex& oth);


	// ������ �������� ����������, ��� ��� ��� ����� ��� ���������� �������, ��������� �������� friend
	//Complex operator +(int a, Complex c);

	// ����������� ������� ������ ���� friend, �����, ����� ���� �� ���������� ��� �������� ������� ������, ���� ������� �� ����.
	friend Complex operator +(int v, Complex c);
	// ����� ��������, ��� ��������������� ���� ��������� ���� ����� INT + COMPLEX, �� �� ��������� ������ COMPLEX + INT
	// ��� ������� ���� ������� ������ ��������� � ��� ����������, ���������� ��������� �������.
	//friend Complex operator +(Complex c, int v);
	// ����������� � ���������� ������ ���������� ���������������� ��� ����, ����� �� ��������� ��������� ��� ������������� ���������
	// ���� ���� �� ������� AnyComplex + AnyInt, �� ��� ���������, ��� � ���������� ���������� ����� ��������� ��� ������
	// ��� ������� ��������������� ��� ����������� � ���������� ����� ����������.

	// ������ ��������������� ��������� =, �� ����� ������������� � �������� ������
	Complex& operator=(const Complex&);
	// ���������� ����������/����������� ���������, ���������� ��� ����� ������� � � �����������.
	// ���������� ������ ++n
	Complex& operator++();
	// ����������� ������ n++
	Complex& operator++(int);
	void Display();
private:
	double num1, num2;
};

Complex::Complex(double n1, double n2)
{
	num1 = n1;
	num2 = n2;
}
// �������������� �������� + ����� ����� �������� Complex � Double
Complex Complex::operator+(double val)
{
	return Complex(this->num1 + val, this->num2 + val);
}
void Complex::operator+=(Complex other)
{
	this->num1 = this->num1 + other.num1;
	this->num2 = this->num2 + other.num2;
}
bool Complex::operator==(Complex& oth)
{
	if (num1 == oth.num1 && num2 == oth.num2)
		return true;
	else return false;
}
// �������������� �������� + ����� ����� �������� Complex � Int
Complex Complex::operator+(int val)
{
	std::cout << "������ ���� ������ �������� + ����� int � Complex" << std::endl;
	return Complex(this->num1 + val, this->num2 + val);
}

// �������������� �������� + ����� ����� ��������� Complex
Complex Complex::operator+(Complex& otherComplex)
{
	double n2 = this->num2 + otherComplex.num2;
	return Complex(this->num1 + otherComplex.num1, n2);
}

// �������������� ���������� �������� +, �� ���� � ���� ���������� ��������� + ��� �������� � Int
Complex operator+(int v, Complex c)
{
	std::cout << "������ ���������� �������� + ����� int � Complex" << std::endl;
	return Complex(c.num1 + v, c.num2 + v);
}

// ������ �������� ���� � ��������� �� ����������� ��������� ����, �� ������� ����������, � ��� ������������� ��������� - ������� ���������
// ����� �����.
// 7 + c � c + 7 ��� ��� ������ ���������������.
//Complex operator+(Complex c, int v)
//{
//	return Complex(c.num1 + v, c.num2 + v);
//}

// ������������� �������� =
Complex& Complex::operator=(const Complex& c)
{
	this->num1 = c.num1;
	this->num2 = c.num2;

	return *this;
}

// ���������� �����, ���������� � ����� ����������
Complex& Complex::operator++()
{
	num1++;
	num2++;
	return *this;
}


Complex& Complex::operator++(int)
{
	Complex temp = Complex(num1, num2);
	num1++;
	num2++;
	return temp;
}

void Complex::Display() { std::cout << "N1 is [" << this->num1 << "] N2 is [" << this->num2 << "]" << std::endl; }

void OperatorsOverload::Init()
{
	// �������� ��� ������� Complex, ������ �� � ��������� �� ���������.
	std::cout << "[Complex + Complex] operation" << std::endl;
	std::cout << "First Complex: " << std::endl;
	Complex c1 = Complex(10, 10);
	c1.Display();

	std::cout << "Second Complex: " << std::endl;
	Complex c2 = Complex(25, 25);
	c2.Display();

	Complex c3 = c1.operator+(c2);
	std::cout << "Result of (First + Second) Complex: " << std::endl;
	c3.Display();

	std::cout << "[Complex(10,10) + int(15] operation" << std::endl;
	int i1 = 15;
	Complex c4 = c1.operator+(i1);
	c4.Display();
	std::cout << "[Complex(10,10) + 7] operation" << std::endl;
	Complex c5 = c1 + 7;
	c5.Display();

	std::cout << "[11 + Complex(10,10)] operation" << std::endl;
	Complex c6 = 11 + c1;

	std::cout << "�������(=) � ������ Complex ������ ������, �� ������������:" << std::endl;
	c6.Display();
	std::cout << "����� ������������:" << std::endl;
	c6 = c1;
	c6.Display();

	c6++;
	c6.Display();
	++c6;
	c6.Display();

	Complex c11 = Complex(1, 1);
	Complex c22 = Complex(2, 2);

	c11 += c22;
	c11.Display();
	// c11 = c11 + c22;
	Complex c00 = Complex(1, 1);
	if (++c00 == c22)
	{
		cout << "�����" << endl;
	}
}


// � �������� ����������� � ��������� �������� �� ������ ���� ����������, � ���������� ������ ���� ���� 1.
// � ��������� ����������� � ��������� ������� ������ ���� 1 ��������, � ���������� 2.
// ��� ���������� ���������� ���������� ������������� �������� ���������� �� ��������� (int any_parameter = 2 - ����������!)
// ��� ������������� ���������, ����� = ����������� ��������� ��������.

/*
��������						������������� �����

��� ������� ���������				���� ������
= () [] -> ->*						����������� ���� ������
+= -= /= *= ^= &= |= %= >>= <<=		���� ������
��������� �������� ���������		�� ���� ������

������ ���? ��-������, �� ��������� ��������� ���������� �������� �����������. ������, ���� ������������ ��� ������� ��� ���������� ��������,
�� ����� ��� �������� � ���� ������� ������, ����� ����������� �����, ���� ������ ����� ������� ����� ������������� (inline). � ���� ��, ������
����� ���������� ����������� � ���, ����� ����������� ������������� ������� �������� ������� ������. ��������, ����� �����
������ � ��������������� << � >> ��� ������� �����/������.
*/