#include "MembersVisible_PrivateProtectedEtc.h"
#include <iostream>

class Example
{
protected: // ��� �������� ������ � ������� �����������
	int v;

private: // ������ ��� �������� ������
	int b;
	int c;
	int* any_size; // ������ ���������� ������ � ������������ Example(int a, int b);

public:
	int a;

	Example() { a = 0; b = 0; c = 0; v = 0; } // ����������� �� ���������
	Example(int a, int b, int _c) // ������ �����������
	{
		this->a = a;
		this->b = b;
		c = _c;
		v = 0;
	}
	Example(int a, int b) // ���������� ������������
	{
		this->a = a;
		this->b = b;
		c = 0;
		v = 0;

		any_size = (int*)malloc(5 * sizeof(int));
	}
	void print() // ����� ������, ���������� � �������
	{
		std::cout << "Example object print [a: " << a << " b: " << b << " v: " << v << "]" << std::endl;
	}
	void print(const char* text) // ������������� ����� print, ���������� � �������
	{
		std::cout << "Example object print, text: " << text << std::endl;
	}
	// static void print() {} - ���������� ���������� ����������� � ������������� ����� � ������ � ����� � ��� �� ������.
	static void staticPrint() // ����������� ����� ������, ���������� � ������, �� ����� ���� ������ � �������
	{
		std::cout << "static print()" << std::endl;
		// a = 5; - ������ ��� ���� �������� ������, ������� �� ����� ����������� ������� ����������� �������
	}
	// ����� public ������ ��� protected �����
	void setProtectedMember(int _v)
	{
		if (_v > 0)
			v = _v;
	}

	~Example()
	{
		std::cout << "destructor called" << std::endl;
		free(any_size);
	}
};

class BaseClass
{
private:
	void PrivateFunc();
protected:
	void ProtectedFunc();
public:
	void PublicFunc();

};

class DerivedClass1 : private BaseClass
{

	void Some()
	{
		PublicFunc();
		ProtectedFunc();
		// PrivateFunc();
	}

};




void MembersVisible_PrivateProtectedEtc::Init()
	{
		Example* ex_ptr = new Example(1, 2, 3);
		ex_ptr->a = 5;
		ex_ptr->print();
		delete ex_ptr;

		Example ex{ 0,5 };
		Example ex2{ 15,14 };

		const char* text = "hello world";

		ex.print();
		ex.print(text); // ������ ����� ����� ������� static, �.�. �� �� ��������� ������� ������� ������

		ex2.print();
		ex2.print(text); // ������ ����� ����� ������� static, �.�. �� �� ��������� ������� ������� ������

		Example::staticPrint();

		ex.setProtectedMember(7); // � ������� ex v = 7
		ex2.setProtectedMember(17); // � ������� ex2 v = 17
		ex2.setProtectedMember(-17); // � ������� ex2 v = 17 - �������� �� ����������, ������ ��� � ������ ������� ����� ��������, �� ��������������� ��������
		ex.print();
		ex.print();
	}
