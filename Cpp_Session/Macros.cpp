#include <iostream>
#include "Macros.h"

/*
	��������� �������������

	#define #elif #else #endif #error #if
	#ifdef #ifndef #import #include #line
	#pragma #undef #using
*/

#define OCEAN
// ��������� #define ������� ������, ������� �������� ������������� � Token-String(������ ������) - �����������
// �� ���� ����� ������� ������� ���������
// ������ ������ ��������, ��� �� ������� ������ OCEAN, ��� Token-String(��������), 
// ������� ���������� ����� ������� ������� ����� ��������� ������� ��������� #ifdef 

// �����
// ������ ����� ��� ���������� ���� �������� ���� ������ �������������, ��-���� ���� ��������� ��� ��� ������������� �� ����� � �� ������������
// ��� �� ����� ���������, ���� ���� �� �� ��������� ����-�� � ������� - ����� ���������� �� ������ ��������������

#ifdef OCEAN
void OceanDefined() 
{
	std::cout << "OCEAN defined" << std::endl;
}
#endif

// ��� �� �� ����� �������� Token-String ��� �������, ������� ��� � ����� �������������� � ����, ������� ����� ������
#define BLUE_OCEAN 1 // ��������� ������� ������������ �����, �� ����� �� ��������� ��������� ��� �������� ���������� #if
#if BLUE_OCEAN == 1 
 // ����� ���������
#elif BLUE_OCEAN == 2
 // �� ����� ���������
#endif

#define COLD_OCEAN "Arctic Ocean" // ����� ������������� ��� �� ���������.


#define multiply(x,y) (x * y) // ���� ���� ����� ���������� ������ () ����� � ��������
// Macro to get a random integer with a specified range
#define getrandom(min, max) \
		((rand()%(int)(((max)+1)-(min)))+(min))
// ������� ����� ������������ ��� �������� �� ��������� ������, ����� ������������� �������, ��� ����������� ������� ��� �� ���������


// ������
#define WIDTH 80
#define HEIGHT (WIDTH + 10) // (90)
#define OTHERHEIGHT WIDTH + 10 // 90

// ���� �� ����� ������������ ��� ��� ������� � ����, �� ������ ����� �����������, �� ����
// � ������� � ��� ����� �������� ������� int var = HEIGHT * 20;
// ���� ������ HEIGHT ����� ��� � ������ �� ��������, �� ������ ������� ����� ��������� ���: int var = (80 + 10) * 20 - ��������� 1800
// �� ���� �� ��� ������ ��� ������� ��� #define HEIGHT WIDTH + 10, �� ������� �� ������������ � int var = 80 + 10 * 20 - ��������� 280


// ��������� #undef ������� ����� ��������� ������ � ������� #define
#define SOMETHING 111
#define func(x,y) x*y

// ��� �������� �������� �� ��������� ���������� ������, ����� ��������������, ��������� ����������.
#undef SOMETHING
#undef func 

// ��������� #erro ������������ ��� ������ ����������, ������������ �������������� ��� ��������� � ����������������� ��������� ��� ��������� �����������
// ������������ Token-String ��� ������ �����������, � ����� �������: (�++ compiler required.)
// Token-String �� �������� ��������� ��������.

#if !defined(__cplusplus)
#error C++ compiler required.
#endif

// ��������� #if #elif #else #endif

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

// ������� � ������ VS 2017 15.3 �������� ��������� __has_include(<path>), ��� ����������� ���������� �� ������������ �����
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
// #ifdef #ifndef ��������� ������������� � ����� ��� �� ���������, ��� � #if ���������, ����� ��� ������������ � defined ����������.
// #ifndef ����� �������� ���������� �������� ��������� #ifdef, �� ���� ��������� ���� ��� �� ����������

// #import
// ������������ ��� ��������� �������� �� ���������� �����. ���������� ���������� ����� ������������� � ������ C++,
// � �������� ����������� ���������� ������ COM.
// ���������:
// #import "filename" [attributes]
// #import <filename> [attributes]

// #line [����� ������] [�������� �����(�����������)]
// ������ ��������� �������� ����� ������(��������� ���� ���� ��������� � ���� ������������ �������� ��� ���������, �������� #line 10, �� 
// ����� ��������� ������ ����� � ���� ��������� ��� 10, ��� �� ������, ��� �� ����������� ����� 10 ����� ��� �������� ����-�� ��� ��� �����
// ����������� ��������, ���, ������ ��������� ����� ������ ��� � 10)
// ��� �� �� ����� �������� � ��� �����, ���, �� �� ����������� ��� �����, � ��, ��� �������� � __FILE__, ����� ��� � �� ������� � __LINE__
// �����?
// ��������� #line ������ ������������ ������������ ��������. �� ������������ ��� ����, ����� ��������� �� ������� ��������� �� �������� 
// ����, � �� �� ��������� ���������.

#line 25 "MacroCppFile"

// ��������� NULL, ��� ������ ���� #, �� �� ����� �������� �������.

// ��������� #using
// ����������� ���������� � ���������, ���������������� � ���������� /clr.
// #using file [as_friend]
// [as_friend] ��������������� � ���, ��� ��� ���� � file ����� ��������.
// file
// A Microsoft intermediate language(MSIL).dll, .exe, .netmodule, or .obj file.
/*
����� ������� ������, ������� ��������� �� ������ ������, ������� ���� ��������� �� ������ ������. ���������� ���� ��������� �� ������ ������ �� ������, 
���� �� ���� ����������� ���� �� �� �����
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
	// ��������� ��������� ������� �� ������� COLD_OCEAN
	std::cout << "Witch ocean is very cold: " << COLD_OCEAN << std::endl;

	// ������������� �������� multiply & getrandom
	int r1 = getrandom(0, 15);
	int r2 = getrandom(0, 23);
	std::cout << "r1: " << r1 << std::endl;
	std::cout << "r2: " << r2 << std::endl;
	std::cout << multiply(r1,r2) << std::endl;
}