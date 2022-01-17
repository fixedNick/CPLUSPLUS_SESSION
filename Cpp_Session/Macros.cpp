#include <iostream>
#include "Macros.h"

/*
	директивы препроцессора

	#define #elif #else #endif #error #if
	#ifdef #ifndef #import #include #line
	#pragma #undef #using
*/

#define OCEAN
// директива #define создает макрос, который содержит ИДЕНТИФИКАТОР и Token-String(Строку токена) - опционально
// То есть можем создать подобие константы
// Данная строка означает, что мы создали макрос OCEAN, без Token-String(значения), 
// наличие созданного таким образом макроса можно проверить вызовом директивы #ifdef 

// ВАЖНО
// Первым делом при компиляции идет проверка всех команд препроцессора, по-сути весь остальной код для препроцессора не нужен и он выкидывается
// Так же любая директива, даже если мы ее запихнули куда-то в функцию - будет обработана на стадии препроцессинга

#ifdef OCEAN
void OceanDefined() 
{
	std::cout << "OCEAN defined" << std::endl;
}
#endif

// Так же мы можем добавить Token-String для макроса, которое уже и будет использоваться в коде, замещая собой макрос
#define BLUE_OCEAN 1 // Строковый литерал использовать можно, но тогда не получится проверить его значение директивой #if
#if BLUE_OCEAN == 1 
 // Будет выполнено
#elif BLUE_OCEAN == 2
 // Не будет выполнено
#endif

#define COLD_OCEAN "Arctic Ocean" // Такое использование так же допустимо.


#define multiply(x,y) (x * y) // Чуть ниже будет объяснение почему () важны в макросах
// Macro to get a random integer with a specified range
#define getrandom(min, max) \
		((rand()%(int)(((max)+1)-(min)))+(min))
// Бекслеш здесь используется для перехода на следующую строку, чтобы препроцессора понимал, что определение макроса еще не завершено


// Скобки
#define WIDTH 80
#define HEIGHT (WIDTH + 10) // (90)
#define OTHERHEIGHT WIDTH + 10 // 90

// Если мы будем использовать эти два макроса в коде, то скобки будут учитываться, то есть
// К примеру у нас будет подобная формула int var = HEIGHT * 20;
// Если макрос HEIGHT будет как и сейчас со скобками, то данная формула будет выглядеть так: int var = (80 + 10) * 20 - Результат 1800
// Но если бы наш макрос был записан как #define HEIGHT WIDTH + 10, то формула бы привратилась в int var = 80 + 10 * 20 - Результат 280


// директива #undef удаляет ранее созданный макрос с помощью #define
#define SOMETHING 111
#define func(x,y) x*y

// Для удаления макросов не требуется передавать ничего, кроме идентификатора, аргументы опускаются.
#undef SOMETHING
#undef func 

// Директива #erro используется для показа искоючения, используется разработчиками для сообщения о несогласованности программы или нарушении ограничений
// Используется Token-String для показа уведомления, в нашем примере: (С++ compiler required.)
// Token-String не подлежит раскрытию макросов.

#if !defined(__cplusplus)
#error C++ compiler required.
#endif

// Директивы #if #elif #else #endif

#if DLEVEL > 5
	#define SIGNAL  1
	#if STACKUSE == 1
		#define STACK   200
	#else
		#define STACK   100
	#endif
#else
	#define SIGNAL  0
	#if STACKUSE == 1
		#define STACK   100
	#else
		#define STACK   50
	#endif
#endif

#if DLEVEL == 0
		#define STACK 0
#elif DLEVEL == 1
		#define STACK 100
#elif DLEVEL > 5
	display(debugptr);
#else
	#define STACK 200
#endif

// Начиная с версии VS 2017 15.3 доступна директива __has_include(<path>), для определения подключены ли заголовочные файлы
#ifdef __has_include
#  if __has_include(<filesystem>)
#    include <filesystem>
#    define have_filesystem 1
#  elif __has_include(<experimental/filesystem>)
#    include <experimental/filesystem>
#    define have_filesystem 1
#    define experimental_filesystem
#  else
#    define have_filesystem 0
#  endif
#endif

/// #ifdef #ifndef #endif
// #ifdef #ifndef Директивы препроцессора и имеют тот же результат, что и #if директива, когда она используется с defined оператором.
// #ifndef имеет обратную логическую проверку директиве #ifdef, то есть проверяет если имя не определено

// #import
// Используется для включения сведений из библиотеки типов. Содержимое библиотеки типов преобразовано в классы C++,
// в основном описывающие интерфейсы модели COM.
// Синтаксис:
// #import "filename" [attributes]
// #import <filename> [attributes]

// #line [номер строки] [название файла(опционально)]
// Данная директива изменяет номер строки(обработка коди идет построчно и если препроцессор встретит эту директиву, допустим #line 10, то 
// номер следующей строки будет у него храниться как 10, это не значит, что он перепрыгнет через 10 строк или вернется куда-то или код будет
// выполняться повторно, нет, просто нумерация строк пойдет уже с 10)
// Так же он может изменить и имя файла, при, но не фактическое имя файла, а то, что записано в __FILE__, ровно как и со строкой в __LINE__
// Зачем?
// Директива #line обычно используется генераторами программ. Он используется для того, чтобы сообщения об ошибках ссылались на исходный 
// файл, а не на созданную программу.

#line 25 "MacroCppFile"

// Директива NULL, это просто знак #, он не имеет никакого влияния.

// Директива #using
// Импортирует метаданные в программу, скомпилированную с параметром /clr.
// #using file [as_friend]
// [as_friend] свидетельствует о том, что все типы в file будут доступны.
// file
// A Microsoft intermediate language(MSIL).dll, .exe, .netmodule, or .obj file.
/*
Можно создать сборку, которая ссылается на вторую сборку, которая сама ссылается на третью сборку. Необходимо явно ссылаться на третью сборку из первой, 
если вы явно используете один из ее типов
*/

/*
public ref class A {};
#using "using_assembly_A.dll"
*/

/*
public ref class B {
public:
	void Test(A a) {}
	void Test() {}
};
*/

/*
#using "using_assembly_B.dll"
int main() {
	B b;
	b.Test();
}
*/


void Macros::Init()
{
	// Подставим строковый литерал из макроса COLD_OCEAN
	std::cout << "Witch ocean is very cold: " << COLD_OCEAN << std::endl;

	// Использование макросов multiply & getrandom
	int r1 = getrandom(0, 15);
	int r2 = getrandom(0, 23);
	std::cout << "r1: " << r1 << std::endl;
	std::cout << "r2: " << r2 << std::endl;
	std::cout << multiply(r1,r2) << std::endl;
}