#include "OperatorsOverload.h"
#include "MembersVisible_PrivateProtectedEtc.h"
#include "Macros.h"
#include <iostream>

enum InitOption
{
	MembersVisible,
	OperatorsOverload,
	Macros
};

void Init(InitOption option)
{
	switch (option)
	{
		case InitOption::OperatorsOverload:
			OperatorsOverload::Init();
			break;
		case InitOption::MembersVisible:
			MembersVisible_PrivateProtectedEtc::Init();
			break;
		case InitOption::Macros:
			Macros::Init();
			break;
	}

}

int main()
{
	setlocale(LC_ALL, "");

	Init(::OperatorsOverload);

	// В каждом из файлов точка входа: функция Init.

	return 0;
}