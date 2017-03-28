//Kasian N. K-12

#include <iostream>
#include "../WrittingLibrary/WritingLibrary.h"
#include "../Greenhouse/Greenhouse.h"
#include <string>

using namespace std;

void main()
{
	Greenhouse oneWithoutOwner;

	setlocale(LC_CTYPE, "Rus");
	copyright();

	while (oneWithoutOwner.getGreenhouseCondition())
	{
		oneWithoutOwner.greenhouseSelfChange();
		oneWithoutOwner.endOfStep();
		cout << oneWithoutOwner.consoleOut() << endl;
	}
	
	cout << oneWithoutOwner.consoleOut() << endl;

	system("pause");
}