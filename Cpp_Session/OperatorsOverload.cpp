#include "OperatorsOverload.h"
#include <iostream>

/*
	Перегрузкой операторов называют переопределение логики действий при вызове некого оператора.
	Например при вызове + можно определить вычитание ( что делать не стотит, нужно сохранять логику работы оператора )
	Более хорошим примером будет переопределение операторов для сложение нескольких полей между двумя объектами и созданием нового объекта
	как итог работы оператора +.
*/

using namespace std;

// Пример перегрузки оператора +, для сложения двух полей разных объектов между собой и создания из этих данных нового объекта.
struct Complex
{
public:
	Complex(double n1, double n2);
	Complex operator +(Complex& otherComplex); // Complex + Complex&
	Complex operator +(int val); // Complex + int
	Complex operator +(double val); // Complex + double
	void operator +=(Complex other);

	bool operator ==(Complex& oth);


	// Данная операция невозможна, так как это будет уже глобальная функция, требуется добавить friend
	//Complex operator +(int a, Complex c);

	// Глобавльные функции должны быть friend, важно, чтобы один из аргументов был объектом данного класса, либо ссылкой на него.
	friend Complex operator +(int v, Complex c);
	// Важно понимать, что переопределение выше реализует лишь работ INT + COMPLEX, но не реализует работу COMPLEX + INT
	// Для решения этой ненасти просто реализуем и его функционал, переставив аргументы местами.
	//friend Complex operator +(Complex c, int v);
	// Определение и реализация данной перегрузки закомментировано для того, чтобы не возникало конфликта при использовании оператора
	// Ведь если мы вызовем AnyComplex + AnyInt, то как локальная, так и глобальная перегрузки будут подходить для выбора
	// Что создаст неоднозначность для компилятора и компиляция будет невозможна.

	// Пример переопределения оператора =, не будет наследоваться в дочерние классы
	Complex& operator=(const Complex&);
	// Перегрузим префиксный/постфиксный инкремент, аналогично это можно сдлеать и с декрементом.
	// Префиксная версия ++n
	Complex& operator++();
	// Постфиксная версия n++
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
// Переопределяем оператор + между двумя объектом Complex и Double
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
// Переопределяем оператор + между двумя объектом Complex и Int
Complex Complex::operator+(int val)
{
	std::cout << "Вызван член класса оператор + между int и Complex" << std::endl;
	return Complex(this->num1 + val, this->num2 + val);
}

// Переопределяем оператор + между двумя объектами Complex
Complex Complex::operator+(Complex& otherComplex)
{
	double n2 = this->num2 + otherComplex.num2;
	return Complex(this->num1 + otherComplex.num1, n2);
}

// Переопределяем глобальный оператор +, по сути у него функционал оператора + для сложения с Int
Complex operator+(int v, Complex c)
{
	std::cout << "Вызван глоабльный оператор + между int и Complex" << std::endl;
	return Complex(c.num1 + v, c.num2 + v);
}

// Данный оператор хоть и идентичен по функционалу оператору выше, но порядок аргументов, а при использовании оператора - порядок операндов
// очень важен.
// 7 + c и c + 7 это два разных переопределения.
//Complex operator+(Complex c, int v)
//{
//	return Complex(c.num1 + v, c.num2 + v);
//}

// Переопределим оператор =
Complex& Complex::operator=(const Complex& c)
{
	this->num1 = c.num1;
	this->num2 = c.num2;

	return *this;
}

// Префиксная форма, прибавляем и сразу возвращаем
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
	// Создадим два объекта Complex, сложим их и посмотрим на результат.
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

	std::cout << "Запишем(=) в объект Complex другой объект, до присваивания:" << std::endl;
	c6.Display();
	std::cout << "После присваивания:" << std::endl;
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
		cout << "РаВНО" << endl;
	}
}


// С унарными операторами в локальных функциях не должно быть аргументов, в глобальных должен быть лишь 1.
// С бинарными операторами в локальных фукциях должен быть 1 аргумент, в глобальных 2.
// При перегрузке операторов невозможно использование значений аргументов по умолчанию (int any_parameter = 2 - невозможно!)
// Все перегруженные операторы, кроме = наследуются дочерними классами.

/*
Оператор						Рекомендуемая форма

Все унарные операторы				Член класса
= () [] -> ->*						Обязательно член класса
+= -= /= *= ^= &= |= %= >>= <<=		Член класса
Остальные бинарные операторы		Не член класса

Почему так? Во-первых, на некоторые операторы изначально наложено ограничение. Вообще, если семантически нет разницы как определять оператор,
то лучше его оформить в виде функции класса, чтобы подчеркнуть связь, плюс помимо этого функция будет подставляемой (inline). К тому же, иногда
может возникнуть потребность в том, чтобы представить левосторонний операнд объектом другого класса. Наверное, самый яркий
пример — переопределение << и >> для потоков ввода/вывода.
*/